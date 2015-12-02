#include "tradingdialog.h"
#include "ui_tradingdialog.h"
#include "clientmodel.h"
#include "walletmodel.h"
#include <qmessagebox.h>
#include <qtimer.h>
#include <bitcoinrpc.h>

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QUrl>
#include <QUrlQuery>
#include <QVariant>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QTime>

#include <openssl/hmac.h>

using namespace std;

tradingDialog::tradingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tradingDialog),
    model(0)
{
    ui->setupUi(this);
    timerid = 0;
    qDebug() <<  "Expected this";

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, Qt::green);

    ui->BuyCostLabel->setPalette(sample_palette);
    ui->SellCostLabel->setPalette(sample_palette);
    ui->BSTYAvailableLabel->setPalette(sample_palette);
    ui->BSTYAvailableLabel_2->setPalette(sample_palette);
    ui->BSTYAvailableLabel_3->setPalette(sample_palette);
    ui->BtcAvailableLbl_2->setPalette(sample_palette);
    //Set tabs to inactive
    ui->TradingTabWidget->setTabEnabled(0,false);
    ui->TradingTabWidget->setTabEnabled(1,false);
    ui->TradingTabWidget->setTabEnabled(4,false);
    ui->TradingTabWidget->setTabEnabled(5,false);
    ui->TradingTabWidget->setTabEnabled(6,false);


    /*OrderBook Table Init*/
    CreateOrderBookTables(*ui->BidsTable,QStringList() << "TOTAL(BTC)"<< "BSTY(SIZE)" << "BID(BTC)");
    CreateOrderBookTables(*ui->AsksTable,QStringList() << "ASK(BTC)"  << "BSTY(SIZE)" << "TOTAL(BTC)");
    /*OrderBook Table Init*/

    /*Market History Table Init*/
    ui->MarketHistoryTable->setColumnCount(5);
    ui->MarketHistoryTable->verticalHeader()->setVisible(false);

    ui->MarketHistoryTable->setHorizontalHeaderLabels(QStringList()<<"DATE"<<"BUY/SELL"<<"BID/ASK"<<"TOTAL UNITS(BSTY)"<<"TOTAL COST(BTC");
    ui->MarketHistoryTable->setRowCount(0);

    int Cellwidth =  ui->MarketHistoryTable->width() / 5;

    ui->MarketHistoryTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    ui->MarketHistoryTable->horizontalHeader()->resizeSection(1,Cellwidth); // column 1, width 50
    ui->MarketHistoryTable->horizontalHeader()->resizeSection(2,Cellwidth);
    ui->MarketHistoryTable->horizontalHeader()->resizeSection(3,Cellwidth);
    ui->MarketHistoryTable->horizontalHeader()->resizeSection(4,Cellwidth);
    ui->MarketHistoryTable->horizontalHeader()->resizeSection(5,Cellwidth);
    ui->MarketHistoryTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->MarketHistoryTable->horizontalHeader()->setStyleSheet("QHeaderView::section, QHeaderView::section * {font-weight :bold;}");
    /*Market History Table Init*/

    /*Account History Table Init*/
    ui->TradeHistoryTable->setColumnCount(13);

    ui->TradeHistoryTable->setHorizontalHeaderLabels(QStringList() << "Date Time" << "Exchange" << "OrderType"  << "Limit" << "QTY" << "QTY_Rem" << "Price" << "PricePerUnit" <<
                                                     "Conditional" << "Condition" << "Condition Target" << "ImmediateOrCancel" << "Closed");
    ui->TradeHistoryTable->setRowCount(0);
    ui->TradeHistoryTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->TradeHistoryTable->horizontalHeader()->setStyleSheet("QHeaderView::section, QHeaderView::section * {font-weight :bold;}");
    ui->TradeHistoryTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    /*Account History Table Init*/

    /*Open Orders Table*/
    ui->OpenOrdersTable->setColumnCount(15);
    ui->OpenOrdersTable->setHorizontalHeaderLabels(QStringList() << "OrderId" << "Date Time" << "Exchange" << "OrderType"  << "Limit" << "QTY" << "QTY_Rem" << "Price" << "PricePerUnit" << "CancelInitiated" <<
                                                   "Conditional" << "Condition" << "Condition Target" << "ImmediateOrCancel" << "Cancel Order");
    ui->OpenOrdersTable->setRowCount(0);
    ui->OpenOrdersTable->setColumnHidden(0,true);
    ui->OpenOrdersTable->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->OpenOrdersTable->horizontalHeader()->setStyleSheet("QHeaderView::section, QHeaderView::section * {font-weight :bold;}");

    ui->OpenOrdersTable->horizontalHeader()->resizeSection(1,120); // column 1, width 50
    ui->OpenOrdersTable->horizontalHeader()->resizeSection(2,70);
    ui->OpenOrdersTable->horizontalHeader()->resizeSection(3,70);
    ui->OpenOrdersTable->horizontalHeader()->resizeSection(4,70);
    ui->OpenOrdersTable->horizontalHeader()->resizeSection(5,70);
    ui->OpenOrdersTable->horizontalHeader()->resizeSection(6,70);
    ui->OpenOrdersTable->horizontalHeader()->resizeSection(7,70);

    ui->OpenOrdersTable->setColumnHidden(9,true);
    ui->OpenOrdersTable->setColumnHidden(10,true);
    ui->OpenOrdersTable->setColumnHidden(11,true);
    ui->OpenOrdersTable->setColumnHidden(12,true);
    ui->OpenOrdersTable->setColumnHidden(13,true);

    connect (ui->OpenOrdersTable, SIGNAL(cellClicked(int,int)), this, SLOT(CancelOrderSlot(int, int)));
    /*Open Orders Table*/

    /*populate static combo values*/
    ui->BuyBidcomboBox   -> addItems(QStringList()<<"Last"<<"Bid"<<"Ask");
    //ui->buyOrdertypeCombo-> addItems(QStringList()<<"Limit"<<"Market");
    ui->buyOrdertypeCombo->hide();
    ui->SellBidcomboBox  -> addItems(QStringList()<<"Last"<<"Bid"<<"Ask");
    //ui->SellOrdertypeCombo-> addItems(QStringList()<<"Limit"<<"Market");
    ui->SellOrdertypeCombo->hide();
    ui->OrderTypeL->hide();
    //ui->BuyTimeInForceCombo-> addItems(QStringList()<<"Good 'Til Cancelled"<<"Immediate Or Cancel");
    //ui->BuyConditionCombo->   addItems(QStringList()<<"Greater Than Or Equal To"<<"Less Than Or Equal To");
    //ui->BuyConditionCombo->hide();
    //ui->BuyWhenPriceLabel->hide();
    //ui->ConditionLineEdit->hide();
    /*populate static combo values*/
}

void tradingDialog::InitTrading()
{       //todo - add internet connection/socket error checking.

        //Get default exchange info for the qlabels
        UpdaterFunction();
        qDebug() << "Updater called";
      if(this->timerid == 0)
        {
          //Timer is not set,lets create one.
          this->timer = new QTimer(this);
          connect(timer, SIGNAL(timeout()), this, SLOT(UpdaterFunction()));
          this->timer->start(5000);
          this->timerid = this->timer->timerId();
        }

}

void tradingDialog::UpdaterFunction(){
    //BSTYst get the main exchange info in order to populate qLabels in maindialog. then get data
    //required for the current tab.

     int Retval = SetExchangeInfoTextLabels();

     if (Retval == 0){
                      ActionsOnSwitch(-1);
                     }
}

QString tradingDialog::GetMarketSummary(){

     QString Response = sendRequest("https://bittrex.com/api/v1.1/public/GetMarketSummary?market=btc-BSTY");
     return Response;
}

QString tradingDialog::GetOrderBook(){

      QString  Response = sendRequest("https://bittrex.com/api/v1.1/public/getorderbook?market=BTC-BSTY&type=both&depth=50");
      return Response;
}

QString tradingDialog::GetMarketHistory(){
      QString Response = sendRequest("https://bittrex.com/api/v1.1/public/getmarkethistory?market=BTC-BSTY&count=100");
      return Response;
}

QString tradingDialog::CancelOrder(QString OrderId){

        QString URL = "https://bittrex.com/api/v1.1/market/cancel?apikey=";
                URL += this->ApiKey;
                URL += "&nonce=12345434&uuid=";
                URL += OrderId;

        QString Response = sendRequest(URL);
        return Response;
}

QString tradingDialog::BuyBSTY(QString OrderType, double Quantity, double Rate){

    QString str = "";
    QString URL = "https://bittrex.com/api/v1.1/market/";
            URL += OrderType;
            URL += "?apikey=";
            URL += this->ApiKey;
            URL += "&nonce=12345434&market=BTC-BSTY&quantity=";
            URL += str.number(Quantity,'i',8);
            URL += "&rate=";
            URL += str.number(Rate,'i',8);

    QString Response = sendRequest(URL);
    return Response;
}

QString tradingDialog::SellBSTY(QString OrderType, double Quantity, double Rate){

    QString str = "";
    QString URL = "https://bittrex.com/api/v1.1/market/";
            URL += OrderType;
            URL += "?apikey=";
            URL += this->ApiKey;
            URL += "&nonce=12345434&market=BTC-BSTY&quantity=";
            URL += str.number(Quantity,'i',8);
            URL += "&rate=";
            URL += str.number(Rate,'i',8);

    QString Response = sendRequest(URL);
    return Response;
}

QString tradingDialog::Withdraw(double Amount, QString Address, QString Coin){

    QString str = "";
    QString URL = "https://bittrex.com/api/v1.1/account/withdraw?apikey=";
            URL += this->ApiKey;
            URL += "&currency=";
            URL += Coin;
            URL += "&quantity=";
            URL += str.number(Amount,'i',8);
            URL += "&address=";
            URL += Address;
            URL += "&nonce=12345434";

    QString Response = sendRequest(URL);
     return Response;
}

QString tradingDialog::GetOpenOrders(){
    QString URL = "https://bittrex.com/api/v1.1/market/getopenorders?apikey=";
            URL += this->ApiKey;
            URL += "&nonce=12345434&market=BTC-BSTY";

    QString Response = sendRequest(URL);
    return Response;
}

QString tradingDialog::GetBalance(QString Currency){

    QString URL = "https://bittrex.com/api/v1.1/account/getbalance?apikey=";
            URL += this->ApiKey;
            URL += "&nonce=12345434&currency=";
            URL += Currency;

    QString Response = sendRequest(URL);
     return Response;
}

QString tradingDialog::GetDepositAddress(){

    QString URL = "https://bittrex.com/api/v1.1/account/getdepositaddress?apikey=";
            URL += this->ApiKey;
            URL += "&nonce=12345434&currency=BSTY";

    QString Response = sendRequest(URL);
    return Response;
}

QString tradingDialog::GetAccountHistory(){

    QString URL = "https://bittrex.com/api/v1.1/account/getorderhistory?apikey=";
            URL += this->ApiKey;
            URL += "&nonce=12345434&market=BTC-BSTY&count=10";

    QString Response = sendRequest(URL);
    return Response;
}

int tradingDialog::SetExchangeInfoTextLabels(){
    //Get the current exchange information + information for the current open tab if required.
    QString str = "";
    QString Response = GetMarketSummary();

    //Set the labels, parse the json result to get values.
    QJsonObject obj = GetResultObjectFromJSONArray(Response);

    //set labels to richtext to use css.
    ui->Bid->setTextFormat(Qt::RichText);
    ui->Ask->setTextFormat(Qt::RichText);
    ui->volumet->setTextFormat(Qt::RichText);
    ui->volumebtc->setTextFormat(Qt::RichText);

    ui->Ask->setText("<b>Ask:</b> <span style='font-weight:bold; font-size:14px; color:Red'>" + str.number(obj["Ask"].toDouble(),'i',8) + "</span> BTC");

    ui->Bid->setText("<b>Bid:</b> <span style='font-weight:bold; font-size:14px; color:Green;'>" + str.number(obj["Bid"].toDouble(),'i',8) + "</span> BTC");

    ui->volumet->setText("<b>BSTY Volume:</b> <span style='font-weight:bold; font-size:14px; color:blue;'>" + str.number(obj["Volume"].toDouble(),'i',8) + "</span> BSTY");

    ui->volumebtc->setText("<b>BTC Volume:</b> <span style='font-weight:bold; font-size:14px; color:blue;'>" + str.number(obj["BaseVolume"].toDouble(),'i',8) + "</span> BTC");

    obj.empty();

return 0;
 }

void tradingDialog::CreateOrderBookTables(QTableWidget& Table,QStringList TableHeader){

    Table.setColumnCount(3);
    Table.verticalHeader()->setVisible(false);

    Table.setHorizontalHeaderLabels(TableHeader);

    int Cellwidth =  Table.width() / 3;

    Table.horizontalHeader()->resizeSection(1,Cellwidth); // column 1, width 50
    Table.horizontalHeader()->resizeSection(2,Cellwidth);
    Table.horizontalHeader()->resizeSection(3,Cellwidth);

    Table.setRowCount(0);

    Table.horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    Table.horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    Table.horizontalHeader()->setStyleSheet("QHeaderView::section, QHeaderView::section * { font-weight :bold;}");
}

void tradingDialog::DisplayBalance(QLabel &BalanceLabel,QLabel &Available, QLabel &Pending, QString Currency,QString Response){

    QString str;

    BalanceLabel.setTextFormat(Qt::RichText);
    Available.setTextFormat(Qt::RichText);
    Pending.setTextFormat(Qt::RichText);

    //Set the labels, parse the json result to get values.
    QJsonObject ResultObject = GetResultObjectFromJSONObject(Response);

    BalanceLabel.setText("<span style='font-weight:bold; font-size:11px; color:green'>" + str.number( ResultObject["Balance"].toDouble(),'i',8) + "</span> " + Currency);
    Available.setText("<span style='font-weight:bold; font-size:11px; color:green'>" + str.number( ResultObject["Available"].toDouble(),'i',8) + "</span> " +Currency);
    Pending.setText("<span style='font-weight:bold; font-size:11px; color:green'>" + str.number( ResultObject["Pending"].toDouble(),'i',8) + "</span> " +Currency);
}

void tradingDialog::ParseAndPopulateOpenOrdersTable(QString Response){

    int itteration = 0, RowCount = 0;

    QJsonArray jsonArray = GetResultArrayFromJSONObject(Response);
    QJsonObject obj;

    ui->OpenOrdersTable->setRowCount(0);

    foreach (const QJsonValue & value, jsonArray)
        {
            QString str = "";
            obj = value.toObject();

            RowCount = ui->OpenOrdersTable->rowCount();

            QString ios;
            QString IsConditional;
            QString ConditionTarget;
            QString CancelInitiated;

            obj["ImmediateOrCancel"].toBool() == true ? (ios = "true")             : ( ios = "false");
            obj["IsConditional"].toBool()     == true ? (IsConditional = "true")   : ( IsConditional = "false");
            obj["ConditionTarget"].toBool()   == true ? (ConditionTarget = "true") : ( ConditionTarget = "false");
            obj["CancelInitiated"].toBool()   == true ? (CancelInitiated = "true") : ( CancelInitiated = "false");

            ui->OpenOrdersTable->insertRow(RowCount);
            ui->OpenOrdersTable->setItem(itteration, 0, new QTableWidgetItem(obj["OrderUuid"].toString()));
            ui->OpenOrdersTable->setItem(itteration, 1, new QTableWidgetItem(BittrexTimeStampToReadable(obj["Opened"].toString())));
            ui->OpenOrdersTable->setItem(itteration, 2, new QTableWidgetItem(obj["Exchange"].toString()));
            ui->OpenOrdersTable->setItem(itteration, 3, new QTableWidgetItem(obj["OrderType"].toString()));
            ui->OpenOrdersTable->setItem(itteration, 4, new QTableWidgetItem(str.number(obj["Limit"].toDouble(),'i',8)));
            ui->OpenOrdersTable->setItem(itteration, 5, new QTableWidgetItem(str.number(obj["Quantity"].toDouble(),'i',8)));
            ui->OpenOrdersTable->setItem(itteration, 6, new QTableWidgetItem(str.number(obj["QuantityRemaining"].toDouble(),'i',8)));
            ui->OpenOrdersTable->setItem(itteration, 7, new QTableWidgetItem(str.number(obj["Price"].toDouble(),'i',8)));
            ui->OpenOrdersTable->setItem(itteration, 8, new QTableWidgetItem(str.number(obj["PricePerUnit"].toDouble(),'i',8)));
            ui->OpenOrdersTable->setItem(itteration, 9, new QTableWidgetItem(CancelInitiated));
            ui->OpenOrdersTable->setItem(itteration, 10, new QTableWidgetItem(IsConditional));
            ui->OpenOrdersTable->setItem(itteration, 11, new QTableWidgetItem(obj["Condition"].toString()));
            ui->OpenOrdersTable->setItem(itteration, 12, new QTableWidgetItem(ConditionTarget));
            ui->OpenOrdersTable->setItem(itteration, 13, new QTableWidgetItem(ios));
            ui->OpenOrdersTable->setItem(itteration, 14, new QTableWidgetItem(tr("Cancel Order")));

            //Handle the cancel link in open orders table
            QTableWidgetItem* CancelCell;
            CancelCell= ui->OpenOrdersTable->item(itteration, 14);    //Set the wtablewidget item to the cancel cell item.
            CancelCell->setForeground(QColor::fromRgb(255,0,0));      //make this item red.
            CancelCell->setTextAlignment(Qt::AlignCenter);
            itteration++;
            }
            obj.empty();
}


void tradingDialog::CancelOrderSlot(int row, int col){

   QString OrderId = ui->OpenOrdersTable->model()->data(ui->OpenOrdersTable->model()->index(row,0)).toString();
   QMessageBox::StandardButton reply;
   reply = QMessageBox::question(this,"Cancel Order","Are you sure you want to cancel the order?",QMessageBox::Yes|QMessageBox::No);

   if (reply == QMessageBox::Yes) {

          QString Response = CancelOrder(OrderId);

          QJsonDocument jsonResponse = QJsonDocument::fromJson(Response.toUtf8());
          QJsonObject ResponseObject = jsonResponse.object();

              if (ResponseObject["success"].toBool() == false){

                            QMessageBox::information(this,"Failed To Cancel Order",ResponseObject["message"].toString());

                  }else if (ResponseObject["success"].toBool() == true){
                             ui->OpenOrdersTable->model()->removeRow(row);
                             QMessageBox::information(this,"Success","You're order was cancelled.");
                  }
   } else {
           qDebug() << "Do Nothing";
          }
}

void tradingDialog::ParseAndPopulateAccountHistoryTable(QString Response){

    int itteration = 0, RowCount = 0;

    QJsonArray jsonArray   = GetResultArrayFromJSONObject(Response);
    QJsonObject obj;

    ui->TradeHistoryTable->setRowCount(0);

    foreach (const QJsonValue & value, jsonArray)
        {
            QString str = "";
            obj = value.toObject();

            RowCount = ui->TradeHistoryTable->rowCount();

            QString ios;
            QString IsConditional;
            QString ConditionTarget;

            obj["ImmediateOrCancel"].toBool() == true ? (ios = "true")             : ( ios = "false");
            obj["IsConditional"].toBool()     == true ? (IsConditional = "true")   : ( IsConditional = "false");
            obj["ConditionTarget"].toBool()   == true ? (ConditionTarget = "true") : ( ConditionTarget = "false");

            ui->TradeHistoryTable->insertRow(RowCount);
            ui->TradeHistoryTable->setItem(itteration, 0, new QTableWidgetItem(BittrexTimeStampToReadable(obj["TimeStamp"].toString())));
            ui->TradeHistoryTable->setItem(itteration, 1, new QTableWidgetItem(obj["Exchange"].toString()));
            ui->TradeHistoryTable->setItem(itteration, 2, new QTableWidgetItem(obj["OrderType"].toString()));
            ui->TradeHistoryTable->setItem(itteration, 3, new QTableWidgetItem(str.number(obj["Limit"].toDouble(),'i',8)));
            ui->TradeHistoryTable->setItem(itteration, 4, new QTableWidgetItem(str.number(obj["Quantity"].toDouble(),'i',8)));
            ui->TradeHistoryTable->setItem(itteration, 5, new QTableWidgetItem(str.number(obj["QuantityRemaining"].toDouble(),'i',8)));
            ui->TradeHistoryTable->setItem(itteration, 6, new QTableWidgetItem(str.number(obj["Price"].toDouble(),'i',8)));
            ui->TradeHistoryTable->setItem(itteration, 7, new QTableWidgetItem(str.number(obj["PricePerUnit"].toDouble(),'i',8)));
            ui->TradeHistoryTable->setItem(itteration, 8, new QTableWidgetItem(IsConditional));
            ui->TradeHistoryTable->setItem(itteration, 9, new QTableWidgetItem(obj["Condition"].toString()));
            ui->TradeHistoryTable->setItem(itteration, 10, new QTableWidgetItem(ConditionTarget));
            ui->TradeHistoryTable->setItem(itteration, 11, new QTableWidgetItem(ios));
            ui->TradeHistoryTable->setItem(itteration, 12, new QTableWidgetItem(obj["Closed"].toString()));
            itteration++;
        }

        obj.empty();
}


void tradingDialog::ParseAndPopulateOrderBookTables(QString OrderBook){

    QString str;
    QJsonObject obj;
    QJsonObject ResultObject = GetResultObjectFromJSONObject(OrderBook);

    int BuyItteration = 0,SellItteration = 0, BidRows = 0, AskRows = 0;

    QJsonArray  BuyArray  = ResultObject.value("buy").toArray();                //get buy/sell object from result object
    QJsonArray  SellArray = ResultObject.value("sell").toArray();               //get buy/sell object from result object

    double BSTYSupply = 0;
    double BSTYDemand = 0;
    double BtcSupply  = 0;
    double BtcDemand  = 0;

    ui->AsksTable->setRowCount(0);

    foreach (const QJsonValue & value, SellArray)
    {
        obj = value.toObject();

        double x = obj["Rate"].toDouble(); //would like to use int64 here
        double y = obj["Quantity"].toDouble();
        double a = (x * y);

        BSTYSupply = BSTYSupply + y;
        BtcSupply  = BtcSupply  + a;

        AskRows = ui->AsksTable->rowCount();
        ui->AsksTable->insertRow(AskRows);

        ui->AsksTable->setItem(SellItteration, 0, new QTableWidgetItem(str.number(x,'i',8)));
        ui->AsksTable->setItem(SellItteration, 1, new QTableWidgetItem(str.number(y,'i',8)));
        ui->AsksTable->setItem(SellItteration, 2, new QTableWidgetItem(str.number(a,'i',8)));
        SellItteration++;
     }

    ui->BidsTable->setRowCount(0);

    foreach (const QJsonValue & value, BuyArray)
    {
        obj = value.toObject();

        double x = obj["Rate"].toDouble(); //would like to use int64 here
        double y = obj["Quantity"].toDouble();
        double a = (x * y);

        BSTYDemand = BSTYDemand + y;
        BtcDemand  = BtcDemand  + a;

        BidRows = ui->BidsTable->rowCount();
        ui->BidsTable->insertRow(BidRows);
        ui->BidsTable->setItem(BuyItteration, 0, new QTableWidgetItem(str.number(a,'i',8)));
        ui->BidsTable->setItem(BuyItteration, 1, new QTableWidgetItem(str.number(y,'i',8)));
        ui->BidsTable->setItem(BuyItteration, 2, new QTableWidgetItem(str.number(x,'i',8)));
        BuyItteration++;
     }

        ui->BSTYSupply->setText("<b>Supply:</b> <span style='font-weight:bold; font-size:14px; color:blue'>" + str.number(BSTYSupply,'i',8) + "</span><b> BSTY</b>");
        ui->BtcSupply->setText("<span style='font-weight:bold; font-size:14px; color:blue'>" + str.number(BtcSupply,'i',8) + "</span><b> BTC</b>");
        ui->AsksCount->setText("<b>Ask's :</b> <span style='font-weight:bold; font-size:14px; color:blue'>" + str.number(ui->AsksTable->rowCount()) + "</span>");


        ui->BSTYDemand->setText("<b>Demand:</b> <span style='font-weight:bold; font-size:14px; color:blue'>" + str.number(BSTYDemand,'i',8) + "</span><b> BSTY</b>");
        ui->BtcDemand->setText("<span style='font-weight:bold; font-size:14px; color:blue'>" + str.number(BtcDemand,'i',8) + "</span><b> BTC</b>");
        ui->BidsCount->setText("<b>Bid's :</b> <span style='font-weight:bold; font-size:14px; color:blue'>" + str.number(ui->BidsTable->rowCount()) + "</span>");
  obj.empty();
}


void tradingDialog::ParseAndPopulateMarketHistoryTable(QString Response){

    int itteration = 0, RowCount = 0;
    QJsonArray    jsonArray    = GetResultArrayFromJSONObject(Response);
    QJsonObject   obj;

    ui->MarketHistoryTable->setRowCount(0);

    foreach (const QJsonValue & value, jsonArray)
        {
            QString str = "";
            obj = value.toObject();

            RowCount = ui->MarketHistoryTable->rowCount();

            ui->MarketHistoryTable->insertRow(RowCount);
            ui->MarketHistoryTable->setItem(itteration, 0, new QTableWidgetItem(BittrexTimeStampToReadable(obj["TimeStamp"].toString())));
            ui->MarketHistoryTable->setItem(itteration, 1, new QTableWidgetItem(obj["OrderType"].toString()));
            ui->MarketHistoryTable->setItem(itteration, 2, new QTableWidgetItem(str.number(obj["Price"].toDouble(),'i',8)));
            ui->MarketHistoryTable->setItem(itteration, 3, new QTableWidgetItem(str.number(obj["Quantity"].toDouble(),'i',8)));
            ui->MarketHistoryTable->setItem(itteration, 4, new QTableWidgetItem(str.number(obj["Total"].toDouble(),'i',8)));
            ui->MarketHistoryTable->item(itteration,1)->setBackgroundColor((obj["OrderType"] == "BUY") ? (QColor (150, 191, 70,255)) : ( QColor (201, 119, 153,255)));
            itteration++;
        }
       obj.empty();
}

void tradingDialog::ActionsOnSwitch(int index = -1){

    QString Response = "";

    if(index == -1){
       index = ui->TradingTabWidget->currentIndex();
    }

    switch (index){
                case 0:    //buy tab is active
                           Response = GetMarketSummary();
                           if(Response.size() > 0 && Response != "Error"){

                               QString balance = GetBalance("BTC");
                               QString BSTYbalance = GetBalance("BSTY");

                               QString str;
                               QString BSTYstr;

                               QJsonObject ResultObject =  GetResultObjectFromJSONObject(balance);
                               QJsonObject BSTYResultObject =  GetResultObjectFromJSONObject(BSTYbalance);

                               ui->BtcAvailableLbl->setText(str.number(ResultObject["Available"].toDouble(),'i',8));
                               ui->BSTYAvailableLabel->setText(BSTYstr.number(BSTYResultObject["Available"].toDouble(),'i',8));
                             }

                break;

                case 1: //Cross send tab active
                                   //Cross send tab is active
                                   Response = GetMarketSummary();
                                   if(Response.size() > 0 && Response != "Error"){

                                       QString balance = GetBalance("BSTY");
                                       QString str;
                                       QJsonObject ResultObject =  GetResultObjectFromJSONObject(balance);

                                       ui->BSTYAvailableLabel_3->setText(str.number(ResultObject["Available"].toDouble(),'i',8));
                                     }

                break;

                case 2: //Order book tab is the current tab - update the info
                       Response = GetOrderBook();
                       if(Response.size() > 0 && Response != "Error"){
                          ParseAndPopulateOrderBookTables(Response);
                       }

                break;

                case 3://market history tab
                       Response = GetMarketHistory();
                           if(Response.size() > 0 && Response != "Error"){
                              ParseAndPopulateMarketHistoryTable(Response);
                         }
                break;

                case 4: //open orders tab
                       Response = GetOpenOrders();
                         if(Response.size() > 0 && Response != "Error"){
                            ParseAndPopulateOpenOrdersTable(Response);
                         }

                break;

                case 5://account history tab
                       Response = GetAccountHistory();
                         if(Response.size() > 0 && Response != "Error"){
                            ParseAndPopulateAccountHistoryTable(Response);
                         }
                break;

                case 6://show balance tab
                       Response = GetBalance("BTC");
                         if(Response.size() > 0 && Response != "Error"){
                          DisplayBalance(*ui->BitcoinBalanceLabel,*ui->BitcoinAvailableLabel,*ui->BitcoinPendingLabel, QString::fromUtf8("BTC"),Response);
                         }

                         Response = GetBalance("BSTY");

                       if(Response.size() > 0 && Response != "Error"){
                         DisplayBalance(*ui->BSTYBalanceLabel,*ui->BSTYAvailableLabel_2,*ui->BSTYPendingLabel, QString::fromUtf8("BSTY"),Response);
                        }
                break;

                case 7:

                break;

              }

}

void tradingDialog::on_TradingTabWidget_tabBarClicked(int index)
{
 //tab was clicked, interrupt the timer and restart after action completed.

    this->timer->stop();

    ActionsOnSwitch(index);

    this->timer->start();
}


QString tradingDialog::sendRequest(QString url){

    QString Response = "";
    QString Secret   = this->SecretKey;

    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req = QNetworkRequest(QUrl(url));

    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //make this conditional,depending if we are using private api call
    req.setRawHeader("apisign",HMAC_SHA512_SIGNER(url,Secret).toStdString().c_str()); //set header for bittrex

    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //success
        Response = reply->readAll();
        delete reply;
    }
    else{
        //failure
        qDebug() << "Failure" <<reply->errorString();
        Response = "Error";
      //QMessageBox::information(this,"Error",reply->errorString());
        delete reply;
        }

     return Response;
}

QString tradingDialog::BittrexTimeStampToReadable(QString DateTime){
    //Seperate Time and date.
    int TPos = DateTime.indexOf("T");
    int sPos = DateTime.indexOf(".");
    QDateTime Date = QDateTime::fromString(DateTime.left(TPos),"yyyy-MM-dd"); //format to convert from
    DateTime.remove(sPos,sizeof(DateTime));
    DateTime.remove(0,TPos+1);
    QDateTime Time = QDateTime::fromString(DateTime.right(TPos),"hh:mm:ss");

    //Reconstruct time and date in our own format, one that QDateTime will recognise.
    QString DisplayDate = Date.toString("dd/MM/yyyy") + " " + Time.toString("hh:mm:ss A"); //formats to convert to

    return DisplayDate;
}

void tradingDialog::CalculateBuyCostLabel(){

    double price    = ui->BuyBidPriceEdit->text().toDouble();
    double Quantity = ui->UnitsInput->text().toDouble();
    double cost = ((price * Quantity) + ((price * Quantity / 100) * 0.25));

    QString Str = "";
    ui->BuyCostLabel->setText(Str.number(cost,'i',8));
}

void tradingDialog::CalculateSellCostLabel(){

    double price    = ui->SellBidPriceEdit->text().toDouble();
    double Quantity = ui->UnitsInputBSTY->text().toDouble();
    double cost = ((price * Quantity) - ((price * Quantity / 100) * 0.25));

    QString Str = "";
    ui->SellCostLabel->setText(Str.number(cost,'i',8));
}

void tradingDialog::CalculateCSReceiveLabel(){

    //calculate amount of currency than can be transferred to bitcoin
    QString balance = GetBalance("BSTY");
    QString buyorders = GetOrderBook();

    QJsonObject BuyObject = GetResultObjectFromJSONObject(buyorders);
    QJsonObject BalanceObject =  GetResultObjectFromJSONObject(balance);
    QJsonObject obj;

    double AvailableBSTY = BalanceObject["Available"].toDouble();
    double Quantity = ui->CSUnitsInput->text().toDouble();
    double Received = 0;
    double Qty = 0;
    double Price = 0;
    QJsonArray  BuyArray  = BuyObject.value("buy").toArray();                //get buy/sell object from result object

    // For each buy order
    foreach (const QJsonValue & value, BuyArray)
    {
        obj = value.toObject();

        double x = obj["Rate"].toDouble(); //would like to use int64 here
        double y = obj["Quantity"].toDouble();
        // If
        if ( ((Quantity / x) - y) > 0 )
        {
            Price = x;
            Received += ((Price * y) - ((Price * y / 100) * 0.25));
            Qty += y;
            Quantity -= ((Price * y) - ((Price * y / 100) * 0.25));
        } else {
            Price = x;
            Received += ((Price * (Quantity / x)) - ((Price * (Quantity / x) / 100) * 0.25));
            Qty += (Quantity / x);
            Quantity -= 0;
            break;
        }
    }

    QString ReceiveStr = "";
    QString DumpStr = "";
    if ( Qty < AvailableBSTY )
    {
        ui->CSReceiveLabel->setText(ReceiveStr.number((ui->CSUnitsInput->text().toDouble() - 0.0002),'i',8));
        ui->CSDumpLabel->setText(DumpStr.number(Price,'i',8));
    } else {
        ReceiveStr = "N/A";
        DumpStr = "N/A";
        ui->CSReceiveLabel->setText(ReceiveStr);
        ui->CSDumpLabel->setText(DumpStr);
    }
}

void tradingDialog::on_UpdateKeys_clicked()
{
  this->ApiKey    = ui->ApiKeyInput->text();
  this->SecretKey = ui->SecretKeyInput->text();

   QJsonDocument jsonResponse = QJsonDocument::fromJson(GetAccountHistory().toUtf8()); //get json from str.
   QJsonObject ResponseObject = jsonResponse.object();                                 //get json obj

  if ( ResponseObject.value("success").toBool() == false){
       QMessageBox::information(this,"API Configuration Failed","Api configuration was unsuccesful.");

  }else if ( ResponseObject.value("success").toBool() == true){
         QMessageBox::information(this,"API Configuration Complete","Api connection has been successfully configured and tested.");
         ui->ApiKeyInput->setEchoMode(QLineEdit::Password);
         ui->SecretKeyInput->setEchoMode(QLineEdit::Password);
         ui->PasswordInput->setText("");
         ui->TradingTabWidget->setTabEnabled(0,true);
         ui->TradingTabWidget->setTabEnabled(1,true);
         ui->TradingTabWidget->setTabEnabled(3,true);
         ui->TradingTabWidget->setTabEnabled(4,true);
         ui->TradingTabWidget->setTabEnabled(5,true);
         ui->TradingTabWidget->setTabEnabled(6,true);
  }

}

string tradingDialog::encryptDecrypt(string toEncrypt, string password) {

    char * key = new char [password.size()+1];
    std::strcpy (key, password.c_str());
    key[password.size()] = '\0'; // don't forget the terminating 0

    string output = toEncrypt;

    for (unsigned int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    return output;
}

void tradingDialog::on_SaveKeys_clicked()
{
    bool fSuccess = true;
    boost::filesystem::path pathConfigFile = GetDataDir() / "APIcache.txt";
    boost::filesystem::ofstream stream (pathConfigFile.string(), ios::out | ios::trunc);

    // Qstring to string
    string password = ui->PasswordInput->text().toUtf8().constData();

    if (password.length() <= 6){
        QMessageBox::information(this,"Error !","Your password is too short !");
        fSuccess = false;
        stream.close();
    }

    // qstrings to utf8, add to byteArray and convert to const char for stream
    string Secret = ui->SecretKeyInput->text().toUtf8().constData();
    string Key = ui->ApiKeyInput->text().toUtf8().constData();
    string ESecret = "";
    string EKey = "";

    if (stream.is_open() && fSuccess)
    {
        ESecret = encryptDecrypt(Secret, password);
        EKey = encryptDecrypt(Key, password);
        stream << ESecret << '\n';
        stream << EKey;
        stream.close();
    }
    if (fSuccess) {
        QMessageBox::information(this,"Success !","Saved keys successfully to APIcache.txt");
        on_UpdateKeys_clicked();
    }

}

void tradingDialog::on_LoadKeys_clicked()
{
    bool fSuccess = true;
    boost::filesystem::path pathConfigFile = GetDataDir() / "APIcache.txt";
    boost::filesystem::ifstream stream (pathConfigFile.string());

    // Qstring to string
    string password = ui->PasswordInput->text().toUtf8().constData();

    if (password.length() <= 6){
        QMessageBox::information(this,"Error !","Your password is too short !");
        fSuccess = false;
        stream.close();
    }

    QString DSecret = "";
    QString DKey = "";

    if (stream.is_open() && fSuccess)
    {
        int i =0;
        for ( std::string line; std::getline(stream,line); )
        {
            if (i == 0 ){
                DSecret = QString::fromUtf8(encryptDecrypt(line, password).c_str());
                ui->SecretKeyInput->setText(DSecret);
            } else if (i == 1){
                DKey = QString::fromUtf8(encryptDecrypt(line, password).c_str());
                ui->ApiKeyInput->setText(DKey);
            }
            i++;
        }
        stream.close();
    }
    if (fSuccess) {
        QMessageBox::information(this,"Success !","Loaded keys successfully from APIcache.txt");
        on_UpdateKeys_clicked();
    }

}

void tradingDialog::on_GenDepositBTN_clicked()
{
    QString response         =  GetDepositAddress();
    QJsonObject ResultObject =  GetResultObjectFromJSONObject(response);
    ui->DepositAddressLabel->setText(ResultObject["Address"].toString());
}


void tradingDialog::on_Sell_Max_Amount_clicked()
{
    //calculate amount of BTC that can be gained from selling BSTY available balance
    QString responseA = GetBalance("BSTY");
    QString str;
    QJsonObject ResultObject =  GetResultObjectFromJSONObject(responseA);

    double AvailableBSTY = ResultObject["Available"].toDouble();

    ui->UnitsInputBSTY->setText(str.number(AvailableBSTY,'i',8));
}

void tradingDialog::on_Buy_Max_Amount_clicked()
{
    //calculate amount of currency than can be brought with the BTC balance available
    QString responseA = GetBalance("BTC");
    QString responseB = GetMarketSummary();
    QString str;

    QJsonObject ResultObject =  GetResultObjectFromJSONObject(responseA);
    QJsonObject ResultObj    =  GetResultObjectFromJSONArray(responseB);

    //Get the Bid ask or last value from combo
    QString value = ui->BuyBidcomboBox->currentText();

    double AvailableBTC = ResultObject["Available"].toDouble();
    double CurrentASK   = ResultObj[value].toDouble();
    double Result = (AvailableBTC / CurrentASK);
    double percentofnumber = (Result * 0.0025);

    Result = Result - percentofnumber;
    ui->UnitsInput->setText(str.number(Result,'i',8));
}

void tradingDialog::on_CS_Max_Amount_clicked()
{
    double Quantity = ui->BSTYAvailableLabel_3->text().toDouble();
    double Received = 0;
    double Qty = 0;
    double Price = 0;
    QString buyorders = GetOrderBook();
    QJsonObject BuyObject = GetResultObjectFromJSONObject(buyorders);
    QJsonObject obj;
    QString str;

    QJsonArray  BuyArray  = BuyObject.value("buy").toArray();                //get buy/sell object from result object

    // For each buy order
    foreach (const QJsonValue & value, BuyArray)
    {
        obj = value.toObject();

        double x = obj["Rate"].toDouble(); //would like to use int64 here
        double y = obj["Quantity"].toDouble();
        // If
        if ( (Quantity - y) > 0 )
        {
            Price = x;
            Received += ((Price * y) - ((Price * y / 100) * 0.25));
            Qty += y;
            Quantity -= y;

        } else {
            Price = x;
            Received += ((Price * Quantity) - ((Price * Quantity / 100) * 0.25));
            Qty += Quantity;

            if ((Quantity * x) < 0.00051){
                Quantity = (0.00051 / x);
            }

            break;
        }
    }

    ui->CSUnitsInput->setText(str.number(Received,'i',8));
}

void tradingDialog::on_Withdraw_Max_Amount_clicked()
{
    //calculate amount of currency than can be brought with the BTC balance available
    QString responseA = GetBalance("BSTY");
    QString str;

    QJsonObject ResultObject =  GetResultObjectFromJSONObject(responseA);

    double AvailableBSTY = ResultObject["Available"].toDouble();

    ui->WithdrawUnitsInput->setText(str.number(AvailableBSTY,'i',8));
}

void tradingDialog::on_buyOrdertypeCombo_activated(const QString &arg1)
{
   if(arg1 == "Conditional"){
                             //ui->BuyWhenPriceLabel->show();
                             //ui->BuyConditionCombo->show();
                             //ui->ConditionLineEdit->show();
                             //ui->Conditionlabel->show();
                            }else if (arg1 == "Limit"){
                                                     //  ui->BuyWhenPriceLabel->hide();
                                                     //  ui->BuyConditionCombo->hide();
                                                     //  ui->ConditionLineEdit->hide();
                                                     //  ui->Conditionlabel->hide();
                                                      }
}


QJsonObject tradingDialog::GetResultObjectFromJSONObject(QString response){

    QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());          //get json from str.
    QJsonObject  ResponseObject = jsonResponse.object();                              //get json obj
    QJsonObject  ResultObject   = ResponseObject.value(QString("result")).toObject(); //get result object

  return ResultObject;
}

QJsonObject tradingDialog::GetResultObjectFromJSONArray(QString response){

    QJsonDocument jsonResponsea = QJsonDocument::fromJson(response.toUtf8());
    QJsonObject   jsonObjecta   = jsonResponsea.object();
    QJsonArray    jsonArraya    = jsonObjecta["result"].toArray();
    QJsonObject   obj;

    foreach (const QJsonValue & value, jsonArraya)
        {
        obj = value.toObject();
        }

return obj;
}

QJsonArray tradingDialog::GetResultArrayFromJSONObject(QString response){

    QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    QJsonObject   jsonObject   = jsonResponse.object();
    QJsonArray    jsonArray    = jsonObject["result"].toArray();

return jsonArray;
}

QString tradingDialog::HMAC_SHA512_SIGNER(QString UrlToSign, QString Secret){

    QString retval = "";

    QByteArray byteArray = UrlToSign.toUtf8();
    const char* URL = byteArray.constData();

    QByteArray byteArrayB = Secret.toUtf8();
    const char* Secretkey = byteArrayB.constData();

    const EVP_MD *md = EVP_sha512();
    unsigned char* digest = NULL;

    // Using sha512 hash engine here.
    digest = HMAC(md,  Secretkey, strlen( Secretkey), (unsigned char*) URL, strlen( URL), NULL, NULL);

    // Be careful of the length of string with the choosen hash engine. SHA1 produces a 20-byte hash value which rendered as 40 characters.
    // Change the length accordingly with your choosen hash engine
    char mdString[129] = { 0 };

    for(int i = 0; i < 64; i++){
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }
    retval = mdString;
    //qDebug() << "HMAC digest:"<< retval;

    return retval;
}

void tradingDialog::on_SellBidcomboBox_currentIndexChanged(const QString &arg1)
{
    QString response = GetMarketSummary();
    QJsonObject ResultObject = GetResultObjectFromJSONArray(response);
    QString Str;

    //Get the Bid ask or last value from combo
    ui->SellBidPriceEdit->setText(Str.number(ResultObject[arg1].toDouble(),'i',8));

    CalculateSellCostLabel(); //update cost
}

void tradingDialog::on_BuyBidcomboBox_currentIndexChanged(const QString &arg1)
{
    QString response = GetMarketSummary();
    QJsonObject ResultObject = GetResultObjectFromJSONArray(response);
    QString Str;

    //Get the Bid ask or last value from combo
    ui->BuyBidPriceEdit->setText(Str.number(ResultObject[arg1].toDouble(),'i',8));

    CalculateBuyCostLabel(); //update cost
}

void tradingDialog::on_BuyBSTY_clicked()
{
    double Rate;
    double Quantity;

    Rate     = ui->BuyBidPriceEdit->text().toDouble();
    Quantity = ui->UnitsInput->text().toDouble();

    QString OrderType = "Limit";
    QString Order;

    if(OrderType == "Limit"){Order = "buylimit";}else if (OrderType == "Market"){ Order = "buymarket";}

    QString Msg = "Are you sure you want to buy ";
            Msg += ui->UnitsInput->text();
            Msg += "BSTY @ ";
            Msg += ui->BuyBidPriceEdit->text();
            Msg += " BTC Each";

            QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Buy Order",Msg,QMessageBox::Yes|QMessageBox::No);

            if (reply == QMessageBox::Yes) {

                QString Response =  BuyBSTY(Order,Quantity,Rate);

                QJsonDocument jsonResponse = QJsonDocument::fromJson(Response.toUtf8());          //get json from str.
                QJsonObject  ResponseObject = jsonResponse.object();                              //get json obj

                if (ResponseObject["success"].toBool() == false){

                    QMessageBox::information(this,"Buy Order Failed",ResponseObject["message"].toString());

                }else if (ResponseObject["success"].toBool() == true){
                        QMessageBox::information(this,"Buy Order Initiated","You Placed an order");
                        }
            }else{

                  //do nothing
                 }
}

void tradingDialog::on_SellBSTYBTN_clicked()
{
    double Rate;
    double Quantity;

    Rate     = ui->SellBidPriceEdit->text().toDouble();
    Quantity = ui->UnitsInputBSTY->text().toDouble();

    QString OrderType = "Limit";
    QString Order;

    if(OrderType == "Limit"){Order = "selllimit";}else if (OrderType == "Market"){ Order = "sellmarket";}

    QString Msg = "Are you sure you want to Sell ";
            Msg += ui->UnitsInputBSTY->text();
            Msg += " BSTY @ ";
            Msg += ui->SellBidPriceEdit->text();
            Msg += " BTC Each";

            QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Sell Order",Msg,QMessageBox::Yes|QMessageBox::No);

            if (reply == QMessageBox::Yes) {

            QString Response =  SellBSTY(Order,Quantity,Rate);
            QJsonDocument jsonResponse = QJsonDocument::fromJson(Response.toUtf8());          //get json from str.
            QJsonObject  ResponseObject = jsonResponse.object();                              //get json obj

            if (ResponseObject["success"].toBool() == false){

                QMessageBox::information(this,"Sell Order Failed",ResponseObject["message"].toString());

                 }else if (ResponseObject["success"].toBool() == true){
                           QMessageBox::information(this,"Sell Order Initiated","You Placed an order");
                          }
}else{

      //do nothing
     }
}

void tradingDialog::on_CSUnitsBtn_clicked()
{
    double Quantity = ui->CSUnitsInput->text().toDouble();
    double Rate = ui->CSDumpLabel->text().toDouble();
    double Received = 0;
    double Qty = 0;
    double Price = 0;
    double Add = 0;
    QString buyorders = GetOrderBook();
    QJsonObject BuyObject = GetResultObjectFromJSONObject(buyorders);
    QJsonObject obj;
    QString Astr;
    QString Qstr;
    QString Rstr;
    QString Coin = "BTC";
    QString Msg = "Are you sure you want to Send ";
            Msg += Qstr.number((Quantity - 0.0002),'i',8);
            Msg += " BTC to ";
            Msg += ui->CSUnitsAddress->text();
            Msg += ", DUMPING your coins at ";
            Msg += Rstr.number(Rate,'i',8);
            Msg += " satoshis ?";

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Cross-Send",Msg,QMessageBox::Yes|QMessageBox::No);

    if(reply != QMessageBox::Yes)
    {
        return;
    }

    WalletModel::UnlockContext ctx(model->requestUnlock());
    if(!ctx.isValid())
    {
        // Unlock wallet was cancelled
        return;
    }

        QString Order = "selllimit";
        QJsonArray  BuyArray  = BuyObject.value("buy").toArray();                //get buy/sell object from result object

        // For each buy order
        foreach (const QJsonValue & value, BuyArray)
        {
            obj = value.toObject();

            double x = obj["Rate"].toDouble(); //would like to use int64 here
            double y = obj["Quantity"].toDouble();
            // If
            if ( ((Quantity / x) - y) > 0 )
            {
                Price = x;
                Received += ((Price * y) - ((Price * y / 100) * 0.25));
                Qty += y;
                Quantity -= ((Price * y) - ((Price * y / 100) * 0.25));

                QString SellResponse = SellBSTY(Order,y,x);
                QJsonDocument SelljsonResponse = QJsonDocument::fromJson(SellResponse.toUtf8());          //get json from str.
                QJsonObject SellResponseObject = SelljsonResponse.object();                              //get json obj

                if (SellResponseObject["success"].toBool() == false){
                    if (SellResponseObject["message"] == "DUST_TRADE_DISALLOWED_MIN_VALUE_50K_SAT"){
                        Add += y;
                        continue;
                    }
                    QMessageBox::information(this,"sFailed",SellResponse);
                    break;
                }
                MilliSleep(100);

            } else {
                Price = x;
                Received += ((Price * (Quantity / x)) - ((Price * (Quantity / x) / 100) * 0.25));
                Qty += (Quantity / x);
                Quantity += (Add * x);
                if (Quantity < 0.00051){
                    Quantity = 0.00051;
                }
                QString SellResponse = SellBSTY(Order,(Quantity / x),x);
                QJsonDocument SelljsonResponse = QJsonDocument::fromJson(SellResponse.toUtf8());          //get json from str.
                QJsonObject SellResponseObject = SelljsonResponse.object();                              //get json obj

                if (SellResponseObject["success"].toBool() == false){
                    QMessageBox::information(this,"sFailed",SellResponse);

                } else if (SellResponseObject["success"].toBool() == true){
                    MilliSleep(7500);
                    QString Response = Withdraw(ui->CSUnitsInput->text().toDouble(),ui->CSUnitsAddress->text(),Coin);
                    QJsonDocument jsonResponse = QJsonDocument::fromJson(Response.toUtf8());          //get json from str.
                    QJsonObject ResponseObject = jsonResponse.object();                              //get json obj

                    if (ResponseObject["success"].toBool() == false){
                        MilliSleep(5000);
                        QString Response = Withdraw(ui->CSUnitsInput->text().toDouble(),ui->CSUnitsAddress->text(),Coin);
                        QJsonDocument jsonResponse = QJsonDocument::fromJson(Response.toUtf8());          //get json from str.
                        QJsonObject ResponseObject = jsonResponse.object();

                        if (ResponseObject["success"].toBool() == false){
                            QMessageBox::information(this,"Failed",ResponseObject["message"].toString());
                        } else if (ResponseObject["success"].toBool() == true){
                            QMessageBox::information(this,"Success","<center>Cross-Send Successful</center>\n Sold "+Astr.number(Qty,'i',4)+" BSTY for "+Qstr.number((ui->CSUnitsInput->text().toDouble()-0.0002),'i',8)+" BTC");
                        }
                    } else if (ResponseObject["success"].toBool() == true){
                        QMessageBox::information(this,"Success","<center>Cross-Send Successful</center>\n Sold "+Astr.number(Qty,'i',4)+" BSTY for "+Qstr.number((ui->CSUnitsInput->text().toDouble()-0.0002),'i',8)+" BTC");

                    }
                }
                break;
            }
        }
}

void tradingDialog::on_WithdrawUnitsBtn_clicked()
{
    double Quantity = ui->WithdrawUnitsInput->text().toDouble();
    QString Qstr;
    QString Coin = "BSTY";
    QString Msg = "Are you sure you want to Withdraw ";
            Msg += Qstr.number((Quantity - 0.02),'i',8);
            Msg += " BSTY to ";
            Msg += ui->WithdrawAddress->text();
            Msg += " ?";

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Withdraw",Msg,QMessageBox::Yes|QMessageBox::No);

    if(reply != QMessageBox::Yes)
    {
        return;
    }

    WalletModel::UnlockContext ctx(model->requestUnlock());
    if(!ctx.isValid())
    {
        // Unlock wallet was cancelled
        return;
    }

        QString Response =  Withdraw(Quantity, ui->WithdrawAddress->text(), Coin);
        QJsonDocument jsonResponse = QJsonDocument::fromJson(Response.toUtf8());          //get json from str.
        QJsonObject  ResponseObject = jsonResponse.object();                              //get json obj

        if (ResponseObject["success"].toBool() == false){
            QMessageBox::information(this,"Failed",ResponseObject["message"].toString());

        }else if (ResponseObject["success"].toBool() == true){
            QMessageBox::information(this,"Success","Withdrawal Successful !");
        }
}

void tradingDialog::on_AdvancedView_stateChanged(int arg1)
{
    //Show or hide columns in OpenOrders Table depending on checkbox state
    if(arg1 == 2){
        ui->OpenOrdersTable->setColumnHidden(9,false);
        ui->OpenOrdersTable->setColumnHidden(10,false);
        ui->OpenOrdersTable->setColumnHidden(11,false);
        ui->OpenOrdersTable->setColumnHidden(12,false);
        ui->OpenOrdersTable->setColumnHidden(13,false);
    }else if(arg1 == 0) {
        ui->OpenOrdersTable->setColumnHidden(9,true);
        ui->OpenOrdersTable->setColumnHidden(10,true);
        ui->OpenOrdersTable->setColumnHidden(11,true);
        ui->OpenOrdersTable->setColumnHidden(12,true);
        ui->OpenOrdersTable->setColumnHidden(13,true);

          }
}

void tradingDialog::on_UnitsInputBSTY_textChanged(const QString &arg1)
{
     CalculateSellCostLabel(); //update cost
}

void tradingDialog::on_UnitsInput_textChanged(const QString &arg1)
{
     CalculateBuyCostLabel(); //update cost
}

void tradingDialog::on_BuyBidPriceEdit_textChanged(const QString &arg1)
{
     CalculateBuyCostLabel(); //update cost
}

void tradingDialog::on_SellBidPriceEdit_textChanged(const QString &arg1)
{
     CalculateSellCostLabel();
}

void tradingDialog::on_CSUnitsInput_textChanged(const QString &arg1)
{
    CalculateCSReceiveLabel(); //update cost
}

void tradingDialog::setModel(WalletModel *model)
{
    this->model = model;
}

tradingDialog::~tradingDialog()
{
    delete ui;
}
