#ifndef BUYDOMAINS_H
#define BUYDOMAINS_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class BuyDomains;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** BuyDomains page widget */
class BuyDomains : public QWidget
{
    Q_OBJECT

public:
    explicit BuyDomains(QWidget *parent = 0);
    ~BuyDomains();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::BuyDomains *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

    QNetworkAccessManager *nam;

private slots:
    void finished(QNetworkReply *reply);
    void GetHttpContent();
};

#endif // BuyDomains_H
