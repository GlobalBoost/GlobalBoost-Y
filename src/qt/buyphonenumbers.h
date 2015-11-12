#ifndef BUYPHONENUMBERS_H
#define BUYPHONENUMBERS_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class BuyPhoneNumbers;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** BuyPhoneNumbers page widget */
class BuyPhoneNumbers : public QWidget
{
    Q_OBJECT

public:
    explicit BuyPhoneNumbers(QWidget *parent = 0);
    ~BuyPhoneNumbers();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::BuyPhoneNumbers *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

    QNetworkAccessManager *nam;

private slots:
    void finished(QNetworkReply *reply);
    void GetHttpContent();
};

#endif // BuyPhoneNumbers_H
