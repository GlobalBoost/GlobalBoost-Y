/********************************************************************************
** Form generated from reading UI file 'overviewpage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERVIEWPAGE_H
#define UI_OVERVIEWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverviewPage
{
public:
    QGridLayout *gridLayout;
    QFrame *transactionContainer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *recentTransactionsHeader;
    QLabel *label_4;
    QLabel *labelTransactionsStatus;
    QSpacerItem *horizontalSpacer;
    QListView *listTransactions;
    QFrame *walletContainer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *walletHeader;
    QLabel *label_5;
    QLabel *labelWalletStatus;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *walletStatus;
    QLabel *label;
    QLabel *labelBalance;
    QLabel *label_3;
    QLabel *labelUnconfirmed;
    QLabel *labelImmatureText;
    QLabel *labelImmature;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelTotalText;
    QLabel *labelTotal;

    void setupUi(QWidget *OverviewPage)
    {
        if (OverviewPage->objectName().isEmpty())
            OverviewPage->setObjectName(QStringLiteral("OverviewPage"));
        OverviewPage->resize(779, 412);
        gridLayout = new QGridLayout(OverviewPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        transactionContainer = new QFrame(OverviewPage);
        transactionContainer->setObjectName(QStringLiteral("transactionContainer"));
        transactionContainer->setFrameShape(QFrame::StyledPanel);
        transactionContainer->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(transactionContainer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        recentTransactionsHeader = new QHBoxLayout();
        recentTransactionsHeader->setObjectName(QStringLiteral("recentTransactionsHeader"));
        label_4 = new QLabel(transactionContainer);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("background-color: transparent;"));

        recentTransactionsHeader->addWidget(label_4);

        labelTransactionsStatus = new QLabel(transactionContainer);
        labelTransactionsStatus->setObjectName(QStringLiteral("labelTransactionsStatus"));
        labelTransactionsStatus->setStyleSheet(QStringLiteral("QLabel { color: red;Background-color:transparent }"));
        labelTransactionsStatus->setText(QStringLiteral("(out of sync)"));
        labelTransactionsStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        recentTransactionsHeader->addWidget(labelTransactionsStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        recentTransactionsHeader->addItem(horizontalSpacer);


        verticalLayout->addLayout(recentTransactionsHeader);

        listTransactions = new QListView(transactionContainer);
        listTransactions->setObjectName(QStringLiteral("listTransactions"));
        listTransactions->setFrameShape(QFrame::NoFrame);
        listTransactions->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listTransactions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listTransactions->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(listTransactions);


        gridLayout->addWidget(transactionContainer, 1, 0, 1, 2);

        walletContainer = new QFrame(OverviewPage);
        walletContainer->setObjectName(QStringLiteral("walletContainer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(walletContainer->sizePolicy().hasHeightForWidth());
        walletContainer->setSizePolicy(sizePolicy);
        walletContainer->setMaximumSize(QSize(16777215, 220));
        walletContainer->setFrameShape(QFrame::StyledPanel);
        walletContainer->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(walletContainer);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        walletHeader = new QHBoxLayout();
        walletHeader->setObjectName(QStringLiteral("walletHeader"));
        label_5 = new QLabel(walletContainer);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("background-color: transparent;QLabel { color: white; }"));

        walletHeader->addWidget(label_5);

        labelWalletStatus = new QLabel(walletContainer);
        labelWalletStatus->setObjectName(QStringLiteral("labelWalletStatus"));
        labelWalletStatus->setStyleSheet(QStringLiteral("QLabel { color: red;Background-color:transparent }"));
        labelWalletStatus->setText(QStringLiteral("(out of sync)"));
        labelWalletStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        walletHeader->addWidget(labelWalletStatus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        walletHeader->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(walletHeader);

        walletStatus = new QFormLayout();
        walletStatus->setObjectName(QStringLiteral("walletStatus"));
        walletStatus->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        walletStatus->setHorizontalSpacing(12);
        walletStatus->setVerticalSpacing(12);
        label = new QLabel(walletContainer);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("background-color: transparent;"));

        walletStatus->setWidget(0, QFormLayout::LabelRole, label);

        labelBalance = new QLabel(walletContainer);
        labelBalance->setObjectName(QStringLiteral("labelBalance"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        labelBalance->setFont(font1);
        labelBalance->setCursor(QCursor(Qt::IBeamCursor));
        labelBalance->setStyleSheet(QStringLiteral(""));
        labelBalance->setText(QStringLiteral("0 BSTY"));
        labelBalance->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        walletStatus->setWidget(0, QFormLayout::FieldRole, labelBalance);

        label_3 = new QLabel(walletContainer);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background-color: transparent;"));

        walletStatus->setWidget(2, QFormLayout::LabelRole, label_3);

        labelUnconfirmed = new QLabel(walletContainer);
        labelUnconfirmed->setObjectName(QStringLiteral("labelUnconfirmed"));
        labelUnconfirmed->setFont(font1);
        labelUnconfirmed->setCursor(QCursor(Qt::IBeamCursor));
        labelUnconfirmed->setText(QStringLiteral("0 BSTY"));
        labelUnconfirmed->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        walletStatus->setWidget(2, QFormLayout::FieldRole, labelUnconfirmed);

        labelImmatureText = new QLabel(walletContainer);
        labelImmatureText->setObjectName(QStringLiteral("labelImmatureText"));
        labelImmatureText->setStyleSheet(QStringLiteral("background-color: transparent;"));

        walletStatus->setWidget(3, QFormLayout::LabelRole, labelImmatureText);

        labelImmature = new QLabel(walletContainer);
        labelImmature->setObjectName(QStringLiteral("labelImmature"));
        labelImmature->setFont(font1);
        labelImmature->setText(QStringLiteral("0 BSTY"));
        labelImmature->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        walletStatus->setWidget(3, QFormLayout::FieldRole, labelImmature);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        walletStatus->setItem(4, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        walletStatus->setItem(4, QFormLayout::FieldRole, verticalSpacer_2);

        labelTotalText = new QLabel(walletContainer);
        labelTotalText->setObjectName(QStringLiteral("labelTotalText"));
        labelTotalText->setStyleSheet(QStringLiteral("background-color: transparent;"));

        walletStatus->setWidget(5, QFormLayout::LabelRole, labelTotalText);

        labelTotal = new QLabel(walletContainer);
        labelTotal->setObjectName(QStringLiteral("labelTotal"));
        labelTotal->setFont(font1);
        labelTotal->setCursor(QCursor(Qt::IBeamCursor));
        labelTotal->setText(QStringLiteral("0 BSTY"));
        labelTotal->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        walletStatus->setWidget(5, QFormLayout::FieldRole, labelTotal);


        verticalLayout_4->addLayout(walletStatus);


        gridLayout->addWidget(walletContainer, 0, 0, 1, 2);


        retranslateUi(OverviewPage);

        QMetaObject::connectSlotsByName(OverviewPage);
    } // setupUi

    void retranslateUi(QWidget *OverviewPage)
    {
        OverviewPage->setWindowTitle(QApplication::translate("OverviewPage", "Form", 0));
        label_4->setText(QApplication::translate("OverviewPage", "<b>Recent transactions</b>", 0));
#ifndef QT_NO_TOOLTIP
        labelTransactionsStatus->setToolTip(QApplication::translate("OverviewPage", "The displayed information may be out of date. Your wallet automatically synchronizes with the Globalboost network after a connection is established, but this process has not completed yet.", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("OverviewPage", "WALLET", 0));
#ifndef QT_NO_TOOLTIP
        labelWalletStatus->setToolTip(QApplication::translate("OverviewPage", "The displayed information may be out of date. Your wallet automatically synchronizes with the Globalboost network after a connection is established, but this process has not completed yet.", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("OverviewPage", "Spendable:", 0));
#ifndef QT_NO_TOOLTIP
        labelBalance->setToolTip(QApplication::translate("OverviewPage", "Your current spendable balance", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("OverviewPage", "Unconfirmed:", 0));
#ifndef QT_NO_TOOLTIP
        labelUnconfirmed->setToolTip(QApplication::translate("OverviewPage", "Total of transactions that have yet to be confirmed, and do not yet count toward the current balance", 0));
#endif // QT_NO_TOOLTIP
        labelImmatureText->setText(QApplication::translate("OverviewPage", "Immature:", 0));
#ifndef QT_NO_TOOLTIP
        labelImmature->setToolTip(QApplication::translate("OverviewPage", "Mined balance that has not yet matured", 0));
#endif // QT_NO_TOOLTIP
        labelTotalText->setText(QApplication::translate("OverviewPage", "Total:", 0));
#ifndef QT_NO_TOOLTIP
        labelTotal->setToolTip(QApplication::translate("OverviewPage", "Your current total balance", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class OverviewPage: public Ui_OverviewPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERVIEWPAGE_H
