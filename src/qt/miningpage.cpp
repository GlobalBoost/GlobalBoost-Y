#include "miningpage.h"
#include "ui_miningpage.h"
#include "guiutil.h"
#include "util.h"
#include "main.h"
#include "init.h"
#include "bitcoingui.h"

#include <QTime>
#include <QTimer>
#include <QThread>
#include <QTextEdit>
#include <QKeyEvent>
#include <QUrl>
#include <QScrollBar>

MiningPage::MiningPage(QWidget *parent, BitcoinGUI *mainForm) :
    QWidget(parent),
    ui(new Ui::MiningPage)
{
    _mainFrom = mainForm;
    ui->setupUi(this);

    minerSet = false;
    minerActive = false;
    typeChanged(0);
    minerProcess = new QProcess(this);
    minerProcess->setProcessChannelMode(QProcess::MergedChannels);
    readTimer = new QTimer(this);
    readTimer1 = new QTimer(this);
    acceptedShares = 0;
    rejectedShares = 0;
    roundAcceptedShares = 0;
    roundRejectedShares = 0;
    initThreads = 0;

    connect(readTimer, SIGNAL(timeout()), this, SLOT(readProcessOutput()));

    connect(readTimer1, SIGNAL(timeout()), this, SLOT(updateSpeed()));

    connect(ui->startButton, SIGNAL(pressed()), this, SLOT(startPressed()));
    connect(ui->typeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(typeChanged(int)));
    connect(ui->debugCheckBox, SIGNAL(toggled(bool)), this, SLOT(debugToggled(bool)));
    connect(minerProcess, SIGNAL(started()), this, SLOT(minerStarted()));
    connect(minerProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(minerError(QProcess::ProcessError)));
    connect(minerProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(minerFinished()));
    connect(minerProcess, SIGNAL(readyRead()), this, SLOT(readProcessOutput()));

    // error: no known function for call ClientModel (MiningPage* const)
    // candidates are ClientModel::ClientModel(OptionsModel*, QObject*)
    setModel(new ClientModel(0, this));
    updateSpeed();

    clear();
   // ui->procSlider->setMinimum(1);
    ui->threadsBox->setMinimum(1);
    int nProcessors = boost::thread::hardware_concurrency();
    //ui->procSlider->setMaximum(nProcessors);
    //ui->procSlider->setValue(nProcessors / 2);

    ui->threadsBox->setMaximum(nProcessors);
    ui->threadsBox->setValue(nProcessors/2);

    QTimer* ptimer = new QTimer(this);
    connect(ptimer, SIGNAL(timeout()), SLOT(slotUpdateSpeed()));
    ptimer->start(1000);
    slotUpdateSpeed();
}

void MiningPage::slotUpdateSpeed()
{
        boost::int64_t speed = 0;
        if (GetTimeMillis() - nHPSTimerStart > 8000)
            speed = (boost::int64_t)0;
        else
            speed = (boost::int64_t)dHashesPerSec;

        if (speed > 10000)
            ui->mineSpeedLabel->setText(QString("Speed: %1 khash/sec").arg(speed / 1000));
        else
            ui->mineSpeedLabel->setText(QString("Speed: %1 hash/sec").arg(speed));
}

MiningPage::~MiningPage()
{
    delete ui;
}

void MiningPage::scrollToEnd()
{
    QScrollBar *scrollbar = ui->miningLog->verticalScrollBar();
    scrollbar->setValue(scrollbar->maximum());
}

void MiningPage::SetMiningStatus(bool isMining)
{
    //ui->procSlider->setEnabled(!isMining);
    ui->threadsBox->setEnabled(!isMining);
    ui->mineSpeedLabel->setVisible(isMining);
    _mainFrom->SetMiningStatus(isMining);
    if (isMining)
    {
        message(CMD_REQUEST, tr("Mining bst started!"));
        int64 pc = GetArg("-genproclimit", -1);
        message(CMD_REQUEST, QString(tr("Used threads %1")).arg(pc));
    }
    else
        message(CMD_REQUEST, tr("Mining bst stopped!"));
}

void MiningPage::clear()
{
    ui->miningLog->clear();

    ui->miningLog->document()->setDefaultStyleSheet(
                "table { }"
                "td.time { color: #808080; padding-top: 3px; } "
                "td.message { font-family: Monospace; font-size: 12px; } "
                "td.cmd-request { color: #006060; } "
                "td.cmd-error { color: red; } "
                "b { color: #006060; } "
                );
}

static QString categoryClass(int category)
{
    switch(category)
    {
    case MiningPage::CMD_REQUEST:  return "cmd-request"; break;
    case MiningPage::CMD_REPLY:    return "cmd-reply"; break;
    case MiningPage::CMD_ERROR:    return "cmd-error"; break;
    default:                       return "misc";
    }
}

void MiningPage::message(int category, const QString &message, bool html)
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString();
    QString out;
    out += "<table><tr><td class=\"time\" width=\"65\">" + timeString + "</td>";
    out += "<td class=\"icon\" width=\"32\"><img src=\"" + categoryClass(category) + "\"></td>";
    out += "<td class=\"message " + categoryClass(category) + "\" valign=\"middle\">";
    if(html)
        out += message;
    else
        out += GUIUtil::HtmlEscape(message, true);
    out += "</td></tr></table>";
    ui->miningLog->append(out);
}

bool MiningPage::SetGenerate(bool start, int proc)
{
    bool fGenerate = start;
    int nGenProcLimit = proc;
    mapArgs["-genproclimit"] = itostr(nGenProcLimit);
    if (nGenProcLimit == 0)
        fGenerate = false;
    mapArgs["-gen"] = (fGenerate ? "1" : "0");
    GenerateBitcoins(fGenerate, pwalletMain);
    return GetBoolArg("-gen");
}


void MiningPage::setModel(ClientModel *modelIn)
{
    if(minerSet)
        return;

    minerSet = true;

    this->model = modelIn;

    loadSettings();

    bool pool = model->getMiningType() == ClientModel::PoolMining;

    ui->threadsBox->setValue(model->getMiningThreads());

    ui->typeBox->setCurrentIndex(pool ? 1 : 0);

    if (model->getMiningStarted())
    {
      // startPressed();
    }

}

void MiningPage::startPressed()
{
    initThreads = ui->threadsBox->value();

    if (minerActive == false)
    {

        saveSettings();
        if (getMiningType() == ClientModel::SoloMining)
        {
            minerStarted();
            typeChanged(0);
        }
        else
        {
            startPoolMining();
            typeChanged(1);
        }
    }
    else
    {
        if (getMiningType() == ClientModel::SoloMining)
        {
            minerFinished();
            typeChanged(0);
        }
        else
        {
            stopPoolMining();
            typeChanged(1);
        }
    }
}

void MiningPage::startPoolMining()
{
    QStringList args;
    QString url = ui->serverLine->text();
    if (!url.contains("stratum+tcp://"))
        url.prepend("stratum+tcp://");
    QString urlLine = QString("%1:%2").arg(url, ui->portLine->text());
    QString userpassLine = QString("%1:%2").arg(ui->usernameLine->text(), ui->passwordLine->text());
    args << "--algo" << "yescrypt";
    args << "--scantime" << ui->scantimeBox->text().toAscii();
    args << "--url" << urlLine.toAscii();
    args << "--userpass" << userpassLine.toAscii();
    //QString threadsvalue = QString("%1").arg(ui->procSlider->value());
    QString threadsvalue = QString("%1").arg(ui->threadsBox->value());
    args << "--threads" << threadsvalue.toAscii();
    args << "--retries" << "-1"; // Retry forever.
    args << "-P"; // This is needed for this to work correctly on Windows. Extra protocol dump helps flush the buffer quicker.

    threadSpeed.clear();

    acceptedShares = 0;
    rejectedShares = 0;

    roundAcceptedShares = 0;
    roundRejectedShares = 0;

    // If minerd is in current path, then use that. Otherwise, assume minerd is in the path somewhere.
    QString program = QDir::current().filePath("minerd");
    if (!QFile::exists(program))
        program = "minerd";

    if (ui->debugCheckBox->isChecked())
    {
        message(CMD_REQUEST, args.join(" ").prepend(" ").prepend(program));
    }
    ui->mineSpeedLabel->setText("Speed: N/A");
    ui->shareCount->setText("Accepted: 0 - Rejected: 0");
    minerProcess->start(program,args);
    minerProcess->waitForStarted(-1);
    readTimer->start(500);
}

void MiningPage::stopPoolMining()
{
    ui->mineSpeedLabel->setText("");
    minerProcess->kill();
    readTimer->stop();
}

void MiningPage::saveSettings()
{
    model->setMiningDebug(ui->debugCheckBox->isChecked());
    model->setMiningScanTime(ui->scantimeBox->value());
    model->setMiningServer(ui->serverLine->text());
    model->setMiningPort(ui->portLine->text());
    model->setMiningUsername(ui->usernameLine->text());
    model->setMiningPassword(ui->passwordLine->text());
}

void MiningPage::loadSettings()
{
    ui->debugCheckBox->setChecked(model->getMiningDebug());
    ui->scantimeBox->setValue(model->getMiningScanTime());
    ui->serverLine->setText(model->getMiningServer());
    ui->portLine->setText(model->getMiningPort());
    ui->usernameLine->setText(model->getMiningUsername());
    ui->passwordLine->setText(model->getMiningPassword());
}

void MiningPage::readProcessOutput()
{
    QByteArray output;
    minerProcess->reset();
    output = minerProcess->readAll();
    QString outputString(output);
    if (!outputString.isEmpty())
    {
        QStringList list = outputString.split("\n", QString::SkipEmptyParts);
        int i;
        for (i=0; i<list.size(); i++)
        {
            QString line = list.at(i);
            // Ignore protocol dump
            if (!line.startsWith("[") || line.contains("JSON protocol") || line.contains("HTTP hdr"))
                continue;

            if (ui->debugCheckBox->isChecked())
            {
               // ui->list->addItem(line.trimmed());
                 message(CMD_REQUEST, line.trimmed());
               // ui->list->scrollToBottom();
            }

            if (line.contains("(yay!!!)"))
            {
                reportToList("Share accepted", SHARE_SUCCESS, getTime(line));
                message(CMD_REQUEST, tr("Share accepted"));
            }
            else if (line.contains("(booooo)"))
            {
                reportToList("Share rejected", SHARE_FAIL, getTime(line));
                message(CMD_REQUEST, tr("Share rejected"));
            }
            else if (line.contains("LONGPOLL detected new block"))
            {
                reportToList("LONGPOLL detected a new block", LONGPOLL, getTime(line));
                 message(CMD_REQUEST, tr("Share rejected"));
            }
            else if (line.contains("Supported options:"))
            {
                reportToList("Miner didn't start properly. Try checking your settings.", ERROR, NULL);
                 message(CMD_ERROR, tr("Miner didn't start properly. Try checking your settings."));
            }
            else if (line.contains("The requested URL returned error: 403"))
            {
                reportToList("Couldn't connect. Please check your username and password.", ERROR, NULL);
                 message(CMD_ERROR, tr("Couldn't connect. Please check your username and password."));
            }
            else if (line.contains("HTTP request failed"))
            {
                reportToList("Couldn't connect. Please check pool server and port.", ERROR, NULL);
                 message(CMD_ERROR, tr("Couldn't connect. Please check pool server and port."));
            }
            else if (line.contains("JSON-RPC call failed"))
            {
                reportToList("Couldn't communicate with server. Retrying in 30 seconds.", ERROR, NULL);
                 message(CMD_ERROR, tr("Couldn't communicate with server. Retrying in 30 seconds."));
            }
            else if (line.contains("thread ") && line.contains("khash/s"))
            {
                QString threadIDstr = line.at(line.indexOf("thread ")+7);
                int threadID = threadIDstr.toInt();
                int threadSpeedindx = line.indexOf(",");
                QString threadSpeedstr = line.mid(threadSpeedindx);
                threadSpeedstr.chop(8);
                threadSpeedstr.remove(", ");
                threadSpeedstr.remove(" ");
                threadSpeedstr.remove('\n');
                double speed=0;
                speed = threadSpeedstr.toDouble();
                threadSpeed[threadID] = speed;
                updateSpeed();
            }
        }
    }
}

void MiningPage::minerError(QProcess::ProcessError error)
{
    if (error == QProcess::FailedToStart)
    {
       // reportToList("Miner failed to start. Make sure you have the minerd executable and libraries in the same directory as GlobalBoost-Y.", ERROR, NULL);
        message(CMD_ERROR, tr("Miner failed to start. Make sure you have the minerd executable and libraries in the same directory as GlobalBoost-Y."));
    }
}

void MiningPage::minerFinished()
{
    if (getMiningType() == ClientModel::SoloMining)
    {
        message(CMD_REPLY, tr("Stop mining bst..."));
        try
        {
            bool res = SetGenerate(false, -1);
            if (res == false)
                SetMiningStatus(res);
            else
                message(CMD_ERROR, tr("Stop error!"));
        }
        catch (std::exception& e)
        {
            message(CMD_ERROR, QString("Error: ") + QString::fromStdString(e.what()));
        }
        scrollToEnd();

    }
    else
        reportToList("Miner exited.", ERROR, NULL);
         message(CMD_ERROR, tr("Miner exited."));
    minerActive = false;
    resetMiningButton();
}

void MiningPage::minerStarted()
{
    if (!minerActive)
    {
        if (getMiningType() == ClientModel::SoloMining)
        {
            message(CMD_REPLY, tr("Running mining bst..."));
            try
            {
                bool res = SetGenerate(true, ui->threadsBox->value());
                if (res == true)
                    SetMiningStatus(res);
                else
                    message(CMD_ERROR, tr("Start error!"));
            }
            catch (std::exception& e)
            {
                message(CMD_ERROR, QString("Error: ") + QString::fromStdString(e.what()));
            }
            scrollToEnd();
            ui->shareCount->setVisible(false);

        }
        else
        {
            reportToList("Miner started. You might not see any output for a few minutes.", STARTED, NULL);
            message(CMD_REPLY, tr("Miner started. You might not see any output for a few minutes."));
            ui->shareCount->setVisible(true);
        }
    }
    minerActive = true;
    resetMiningButton();

}

void MiningPage::updateSpeed()
{
    double totalSpeed=0;
    int totalThreads=0;

    QMapIterator<int, double> iter(threadSpeed);
    while(iter.hasNext())
    {
        iter.next();
        totalSpeed += iter.value();
        totalThreads++;
    }

    // If all threads haven't reported the hash speed yet, make an assumption
    if (totalThreads != initThreads)
    {
        totalSpeed = (totalSpeed/totalThreads)*initThreads;
    }

    QString speedString = QString("%1").arg(totalSpeed);
    QString threadsString = QString("%1").arg(initThreads);

    QString acceptedString = QString("%1").arg(acceptedShares);
    QString rejectedString = QString("%1").arg(rejectedShares);

    QString roundAcceptedString = QString("%1").arg(roundAcceptedShares);
    QString roundRejectedString = QString("%1").arg(roundRejectedShares);

    if (totalThreads == initThreads)
        ui->mineSpeedLabel->setText(QString("Speed: %1 khash/sec - %2 thread(s)").arg(speedString, threadsString));
    else
        ui->mineSpeedLabel->setText(QString("Speed: ~%1 khash/sec - %2 thread(s)").arg(speedString, threadsString));

    ui->shareCount->setText(QString("Accepted: %1 (%3) - Rejected: %2 (%4)").arg(acceptedString, rejectedString, roundAcceptedString, roundRejectedString));
    model->setMining(getMiningType(), true, initThreads, totalSpeed*1000);
}

void MiningPage::reportToList(QString msg, int type, QString time)
{
    QString message;
    if (time == NULL)
        message = QString("[%1] - %2").arg(QTime::currentTime().toString(), msg);
    else
        message = QString("[%1] - %2").arg(time, msg);

    switch(type)
    {
        case SHARE_SUCCESS:
            acceptedShares++;
            roundAcceptedShares++;
            updateSpeed();
            break;

        case SHARE_FAIL:
            rejectedShares++;
            roundRejectedShares++;
            updateSpeed();
            break;

        case LONGPOLL:
            roundAcceptedShares = 0;
            roundRejectedShares = 0;
            break;

        default:
            break;
    }
}

// Function for fetching the time
QString MiningPage::getTime(QString time)
{
    if (time.contains("["))
    {
        time.resize(21);
        time.remove("[");
        time.remove("]");
        time.remove(0,11);
        return time;
    }
    else
        return NULL;
}

void MiningPage::enableMiningControls(bool enable)
{
    ui->typeBox->setEnabled(enable);
    ui->threadsBox->setEnabled(enable);
    ui->scantimeBox->setEnabled(enable);
    ui->serverLine->setEnabled(enable);
    ui->portLine->setEnabled(enable);
    ui->usernameLine->setEnabled(enable);
    ui->passwordLine->setEnabled(enable);
}

void MiningPage::enablePoolMiningControls(bool enable)
{
    ui->scantimeBox->setEnabled(enable);
    ui->serverLine->setEnabled(enable);
    ui->portLine->setEnabled(enable);
    ui->usernameLine->setEnabled(enable);
    ui->passwordLine->setEnabled(enable);
}

ClientModel::MiningType MiningPage::getMiningType()
{
    if (ui->typeBox->currentIndex() == 0)  // Solo Mining
    {
        return ClientModel::SoloMining;
    }
    else if (ui->typeBox->currentIndex() == 1)  // Pool Mining
    {
        return ClientModel::PoolMining;
    }
    return ClientModel::SoloMining;
}

void MiningPage::typeChanged(int index)
{
    if (index == 0)  // Solo Mining
    {
        enablePoolMiningControls(false);
    }
    else if (index == 1)  // Pool Mining
    {
        enablePoolMiningControls(true);
    }
}

void MiningPage::debugToggled(bool checked)
{
    model->setMiningDebug(checked);
}

void MiningPage::resetMiningButton()
{
    ui->startButton->setText(minerActive ? "Stop Mining" : "Start Mining");
    _mainFrom->SetMiningStatus(minerActive);
    enableMiningControls(!minerActive);
}

