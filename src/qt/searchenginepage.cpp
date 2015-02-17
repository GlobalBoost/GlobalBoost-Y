#include "searchenginepage.h"
#include "ui_searchenginepage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"

#include <QAbstractItemDelegate>
#include <QPainter>

#define DECORATION_SIZE 64


#include "searchenginepage.moc"

SearchEnginePage::SearchEnginePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchEnginePage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewSearchEngine->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

SearchEnginePage::~SearchEnginePage()
{
    delete ui;
}

void SearchEnginePage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void SearchEnginePage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void SearchEnginePage::finished(QNetworkReply *reply) {
  ui->webViewSearchEngine->setHidden(false);
  
}

void SearchEnginePage::GetHttpContent() {
  ui->webViewSearchEngine->setHidden(false);
  ui->submitButton->setHidden(true);

  QString url = "https://duckduckgo.com/";

  ui->webViewSearchEngine->load(QNetworkRequest(url));

}
