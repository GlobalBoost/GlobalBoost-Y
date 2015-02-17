#include "socialnetworkmanagerpage.h"
#include "ui_socialnetworkmanagerpage.h"

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

#include "socialnetworkmanagerpage.moc"
SocialNetworkManagerPage::SocialNetworkManagerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SocialNetworkManagerPage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);        
    ui->webViewSocialNetworkManager->setHidden(true);
    ui->frameSocianNetworkManagerBottom->setHidden(true);         
    connect(ui->pushButtonSignUp,SIGNAL(clicked()),this,SLOT(SignUpWebview()));
    connect(ui->pushButtonLoadSNM,SIGNAL(clicked()),this,SLOT(LoadSNMWebview()));
}

SocialNetworkManagerPage::~SocialNetworkManagerPage()
{
    delete ui;
}

void SocialNetworkManagerPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void SocialNetworkManagerPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void SocialNetworkManagerPage::SignUpWebview() {
  ui->webViewSocialNetworkManager->setHidden(false);
  ui->frameSocianNetworkManagerCenter->setHidden(true);
  ui->frameSocianNetworkManagerBottom->setHidden(false);
  QString url = "https://globalboo.st/signup.php?auglbost&pass=469092462";
  ui->webViewSocialNetworkManager->load(QNetworkRequest(url));
  connect(ui->pushButtonSignUp_bottom,SIGNAL(clicked()),this,SLOT(SignUpWebviewBottom()));
  connect(ui->pushButtonLoadSNM_bottom,SIGNAL(clicked()),this,SLOT(LoadSNMWebviewBottom()));
}

void SocialNetworkManagerPage::LoadSNMWebview() {
  ui->webViewSocialNetworkManager->setHidden(false);
  ui->frameSocianNetworkManagerCenter->setHidden(true);
  ui->frameSocianNetworkManagerBottom->setHidden(false);
  QString url = "https://GlobalBoo.st/status";
  ui->webViewSocialNetworkManager->load(QNetworkRequest(url));
  connect(ui->pushButtonSignUp_bottom,SIGNAL(clicked()),this,SLOT(SignUpWebviewBottom()));
  connect(ui->pushButtonLoadSNM_bottom,SIGNAL(clicked()),this,SLOT(LoadSNMWebviewBottom()));
}


void SocialNetworkManagerPage::SignUpWebviewBottom() {
  ui->webViewSocialNetworkManager->setHidden(false);
  ui->frameSocianNetworkManagerCenter->setHidden(true);
  ui->frameSocianNetworkManagerBottom->setHidden(false);
  QString url = "https://globalboo.st/signup.php?auglbost&pass=469092462";
  ui->webViewSocialNetworkManager->load(QNetworkRequest(url));
}

void SocialNetworkManagerPage::LoadSNMWebviewBottom() {
  ui->webViewSocialNetworkManager->setHidden(false);
  ui->frameSocianNetworkManagerCenter->setHidden(true);
  ui->frameSocianNetworkManagerBottom->setHidden(false);
  QString url = "https://GlobalBoo.st/status";
  ui->webViewSocialNetworkManager->load(QNetworkRequest(url));
}


