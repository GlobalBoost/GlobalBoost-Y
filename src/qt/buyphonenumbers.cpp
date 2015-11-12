#include "buyphonenumbers.h"
#include "ui_buyphonenumbers.h"

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


#include "buyphonenumbers.moc"

BuyPhoneNumbers::BuyPhoneNumbers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyPhoneNumbers),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewBuyPhoneNumbers->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

BuyPhoneNumbers::~BuyPhoneNumbers()
{
    delete ui;
}

void BuyPhoneNumbers::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void BuyPhoneNumbers::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void BuyPhoneNumbers::finished(QNetworkReply *reply) {
  ui->webViewBuyPhoneNumbers->setHidden(false);
  
}

void BuyPhoneNumbers::GetHttpContent() {
  ui->webViewBuyPhoneNumbers->setHidden(false);
  ui->submitButton->setHidden(true);

  QString url = "https://dev.globalboo.st/#/configuration";

  ui->webViewBuyPhoneNumbers->load(QNetworkRequest(url));

}
