
#ifndef TRADINGDIALOG_H
#define TRADINGDIALOG_H

#include <QDialog>
#include <QObject>
#include <stdint.h>
#include "ui_tradingdialog.h"

#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class tradingDialog;
}

class tradingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tradingDialog(QWidget *parent = 0);
    ~tradingDialog();
private slots:

    void InitTrading();
    void on_TradingTabWidget_tabBarClicked(int index);
    void ParseAndPopulateOrderBookTables(QString Response);
    void ParseAndPopulateMarketHistoryTable(QString Response);
    void ParseAndPopulateAccountHistoryTable(QString Response);
    void ParseAndPopulateOpenOrdersTable(QString Response);
    void UpdaterFunction();
    void CreateOrderBookTables(QTableWidget& Table,QStringList TableHeader);
    void CalculateBuyCostLabel();
    void CalculateSellCostLabel();
    void DisplayBalance(QLabel &BalanceLabel,QLabel &Available, QLabel &Pending, QString Currency,QString Response);
    void ActionsOnSwitch(int index);
    void CancelOrderSlot(int row, int col);
    void on_UpdateKeys_clicked();
    void on_GenDepositBTN_clicked();
    void on_Buy_Max_Amount_clicked();
    void on_buyOrdertypeCombo_activated(const QString &arg1);
    void on_BuyBidcomboBox_currentIndexChanged(const QString &arg1);
    void on_UnitsInput_textChanged(const QString &arg1);
    void on_BuyBidPriceEdit_textChanged(const QString &arg1);
    void on_BuyBSTY_clicked();
    void on_SellBSTYBTN_clicked();
    void on_SellBidcomboBox_currentIndexChanged(const QString &arg1);
    void on_Sell_Max_Amount_clicked();
    void on_UnitsInputBSTY_textChanged(const QString &arg1);
    void on_SellBidPriceEdit_textChanged(const QString &arg1);
    void on_AdvancedView_stateChanged(int arg1);

    int SetExchangeInfoTextLabels();

    QString BittrexTimeStampToReadable(QString DateTime);
    QString CancelOrder(QString Orderid);
    QString BuyBSTY(QString OrderType, double Quantity, double Rate);
    QString SellBSTY(QString OrderType, double Quantity, double Rate);
    QString GetMarketHistory();
    QString GetMarketSummary();
    QString GetOrderBook();
    QString GetOpenOrders();
    QString GetAccountHistory();
    QString GetBalance(QString Currency);
    QString GetDepositAddress();
    QString HMAC_SHA512_SIGNER(QString UrlToSign,QString Secretkey);
    QString sendRequest(QString url);
    QJsonObject GetResultObjectFromJSONObject(QString response);
    QJsonObject GetResultObjectFromJSONArray(QString response);
    QJsonArray  GetResultArrayFromJSONObject(QString response);

public slots:


private:
    Ui::tradingDialog *ui;
    //Socket *socket;
    int timerid;
    QTimer *timer;
    QString ApiKey;
    QString SecretKey;


};

#endif // TRADINGDIALOG_H
