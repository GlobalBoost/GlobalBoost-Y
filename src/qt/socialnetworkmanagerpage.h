#ifndef SOCIALNETWORKMANAGERPAGE_H_H
#define SOCIALNETWORKMANAGERPAGE_H_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class SocialNetworkManagerPage;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** SocialNetworkManager page widget */
class SocialNetworkManagerPage : public QWidget
{
    Q_OBJECT

public:
    explicit SocialNetworkManagerPage(QWidget *parent = 0);
    ~SocialNetworkManagerPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::SocialNetworkManagerPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

private slots:
    void SignUpWebview();
    void LoadSNMWebview();
    void SignUpWebviewBottom();
    void LoadSNMWebviewBottom();
};

#endif // SOCIALNETWORKMANAGERPAGE_H
