#ifndef MININGPAGE_H
#define MININGPAGE_H

#include "clientmodel.h"
#include "bitcoingui.h"
#include <QWidget>

#include <QDir>
#include <QFile>
#include <QProcess>
#include <QTime>
#include <QTimer>
#include <QStringList>
#include <QMap>
#include <QSettings>

// Log types
#define STARTED 0
#define SHARE_SUCCESS 1
#define SHARE_FAIL 2
#define ERROR 3
#define LONGPOLL 4

namespace Ui {
class MiningPage;
}

class MiningPage : public QWidget
{
    Q_OBJECT

public:
    explicit MiningPage(QWidget *parent, BitcoinGUI *mainForm);
    ~MiningPage();

    bool minerActive;
    bool minerSet;
    QProcess *minerProcess;
    QMap<int, double> threadSpeed;
    QTimer *readTimer;
    QTimer *readTimer1;
    int acceptedShares;
    int rejectedShares;
    int roundAcceptedShares;
    int roundRejectedShares;
    int initThreads;

    enum MessageClass {
        MC_ERROR,
        MC_DEBUG,
        CMD_REQUEST,
        CMD_REPLY,
        CMD_ERROR
    };

    void SetMiningStatus(bool isMining);
    bool SetGenerate(bool start, int proc);

public slots:
    void clear();
    void message(int category, const QString &message, bool html = false);
    void scrollToEnd();
    void slotUpdateSpeed();

    void startPressed();
    void startPoolMining();
    void stopPoolMining();
    void updateSpeed();
    void setModel(ClientModel *model);
    void loadSettings();
    void saveSettings();
    void reportToList(QString, int, QString);
    void minerStarted();
    void minerError(QProcess::ProcessError);
    void minerFinished();
    void readProcessOutput();
    QString getTime(QString);
    void enableMiningControls(bool enable);
    void enablePoolMiningControls(bool enable);
    ClientModel::MiningType getMiningType();
    void typeChanged(int index);
    void debugToggled(bool checked);



private slots:

private:
    //int timer_id;
    Ui::MiningPage *ui;
    BitcoinGUI *_mainFrom;

    ClientModel *model;
    void resetMiningButton();


};

#endif // MININGPAGE_H
