#include "buydomains.h"
#include "ui_buydomains.h"

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


#include "buydomains.moc"

BuyDomains::BuyDomains(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyDomains),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewBuyDomains->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

BuyDomains::~BuyDomains()
{
    delete ui;
}

void BuyDomains::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void BuyDomains::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void BuyDomains::finished(QNetworkReply *reply) {
  ui->webViewBuyDomains->setHidden(false);
  
}

void BuyDomains::GetHttpContent() {
  ui->webViewBuyDomains->setHidden(false);
  ui->submitButton->setHidden(true);

  QString url = "https://globalboo.st/domaintcheck.php";

  ui->webViewBuyDomains->load(QNetworkRequest(url));

}
