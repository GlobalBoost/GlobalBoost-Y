#ifndef SEARCHENGINEPAGE_H
#define SEARCHENGINEPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class SearchEnginePage;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** SearchEngine page widget */
class SearchEnginePage : public QWidget
{
    Q_OBJECT

public:
    explicit SearchEnginePage(QWidget *parent = 0);
    ~SearchEnginePage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);

public slots:

signals:

private:
    Ui::SearchEnginePage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

    QNetworkAccessManager *nam;

private slots:
    void finished(QNetworkReply *reply);
    void GetHttpContent();
};

#endif // SEARCHENGINEPAGE_H
