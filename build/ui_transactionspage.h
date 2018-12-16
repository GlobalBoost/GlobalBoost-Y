/********************************************************************************
** Form generated from reading UI file 'transactionspage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONSPAGE_H
#define UI_TRANSACTIONSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransactionsPage
{
public:
    QVBoxLayout *verticalLayout_9;
    QFrame *line_3;
    QWidget *wTransactionsHeader;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *wTransactionsContainer;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *gridLayout_3;
    QLineEdit *addressWidget;
    QComboBox *dateWidget;
    QComboBox *typeWidget;
    QLineEdit *amountWidget;
    QPushButton *bTransactionsSortOrder;
    QTableView *transactionView;

    void setupUi(QWidget *TransactionsPage)
    {
        if (TransactionsPage->objectName().isEmpty())
            TransactionsPage->setObjectName(QStringLiteral("TransactionsPage"));
        TransactionsPage->resize(792, 438);
        TransactionsPage->setMaximumSize(QSize(16777215, 438));
        verticalLayout_9 = new QVBoxLayout(TransactionsPage);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        line_3 = new QFrame(TransactionsPage);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setStyleSheet(QStringLiteral("background-color: rgb(191,25,25);"));
        line_3->setLineWidth(0);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_3);

        wTransactionsHeader = new QWidget(TransactionsPage);
        wTransactionsHeader->setObjectName(QStringLiteral("wTransactionsHeader"));
        wTransactionsHeader->setMinimumSize(QSize(0, 32));
        wTransactionsHeader->setMaximumSize(QSize(16777215, 32));
        wTransactionsHeader->setProperty("is_header", QVariant(true));
        horizontalLayout_10 = new QHBoxLayout(wTransactionsHeader);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_14 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_14);

        label_20 = new QLabel(wTransactionsHeader);
        label_20->setObjectName(QStringLiteral("label_20"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMinimumSize(QSize(25, 25));
        label_20->setMaximumSize(QSize(25, 25));
        label_20->setText(QStringLiteral(""));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/res/last_transactions.png")));

        horizontalLayout_10->addWidget(label_20);

        label_21 = new QLabel(wTransactionsHeader);
        label_21->setObjectName(QStringLiteral("label_21"));
        QFont font;
        font.setPointSize(11);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_21->setFont(font);
        label_21->setStyleSheet(QLatin1String("QLabel {\n"
"	color: #ff0000;\n"
"}"));

        horizontalLayout_10->addWidget(label_21);


        verticalLayout_9->addWidget(wTransactionsHeader);

        wTransactionsContainer = new QWidget(TransactionsPage);
        wTransactionsContainer->setObjectName(QStringLiteral("wTransactionsContainer"));
        wTransactionsContainer->setStyleSheet(QLatin1String("#wTransactionsContainer {\n"
"	background-color: white;\n"
" }\n"
"\n"
"QLabel {\n"
"	color:White;\n"
"}\n"
""));
        verticalLayout_10 = new QVBoxLayout(wTransactionsContainer);
        verticalLayout_10->setSpacing(5);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(15, 14, 15, 30);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        addressWidget = new QLineEdit(wTransactionsContainer);
        addressWidget->setObjectName(QStringLiteral("addressWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addressWidget->sizePolicy().hasHeightForWidth());
        addressWidget->setSizePolicy(sizePolicy1);
        addressWidget->setStyleSheet(QStringLiteral("border-color: white;"));

        gridLayout_3->addWidget(addressWidget, 0, 4, 1, 1);

        dateWidget = new QComboBox(wTransactionsContainer);
        dateWidget->setObjectName(QStringLiteral("dateWidget"));
        sizePolicy.setHeightForWidth(dateWidget->sizePolicy().hasHeightForWidth());
        dateWidget->setSizePolicy(sizePolicy);
        dateWidget->setMinimumSize(QSize(43, 22));
        dateWidget->setMaximumSize(QSize(120, 16777215));
        dateWidget->setStyleSheet(QStringLiteral(""));
        dateWidget->setIconSize(QSize(16, 20));

        gridLayout_3->addWidget(dateWidget, 0, 1, 1, 1);

        typeWidget = new QComboBox(wTransactionsContainer);
        typeWidget->setObjectName(QStringLiteral("typeWidget"));
        typeWidget->setMinimumSize(QSize(43, 22));
        typeWidget->setMaximumSize(QSize(120, 16777215));

        gridLayout_3->addWidget(typeWidget, 0, 2, 1, 1);

        amountWidget = new QLineEdit(wTransactionsContainer);
        amountWidget->setObjectName(QStringLiteral("amountWidget"));
        sizePolicy1.setHeightForWidth(amountWidget->sizePolicy().hasHeightForWidth());
        amountWidget->setSizePolicy(sizePolicy1);
        amountWidget->setStyleSheet(QStringLiteral("border-color: white;"));

        gridLayout_3->addWidget(amountWidget, 0, 5, 1, 1);

        bTransactionsSortOrder = new QPushButton(wTransactionsContainer);
        bTransactionsSortOrder->setObjectName(QStringLiteral("bTransactionsSortOrder"));
        bTransactionsSortOrder->setMinimumSize(QSize(20, 20));
        bTransactionsSortOrder->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid gray;	\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/sort_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        bTransactionsSortOrder->setIcon(icon);
        bTransactionsSortOrder->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(bTransactionsSortOrder, 0, 0, 1, 1);


        verticalLayout_10->addLayout(gridLayout_3);

        transactionView = new QTableView(wTransactionsContainer);
        transactionView->setObjectName(QStringLiteral("transactionView"));
        transactionView->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
"     border: 0px solid grey;\n"
"     background: white;\n"
"     width: 9px;\n"
"     margin: 0px 0px 0 0px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background: rgb(191,25,25);\n"
"     min-width: 20px;\n"
" }\n"
"\n"
"QHeaderView {\n"
"	background-color:rgb(192,0,0);\n"
"	font-size: 10;\n"
"	text-align:left;\n"
"}\n"
"QHeaderView::section {\n"
"   background-color:rgb(51,51,51);\n"
"    color: white;\n"
"    padding-left: 5px;\n"
"    border: 0px solid #6c6c6c;\n"
"	text-align:left;\n"
"}\n"
"\n"
"/* style the sort indicator */\n"
"QHeaderView::down-arrow {\n"
"    image: url(down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(up_arrow.png);\n"
"}\n"
"\n"
"QTableView {\n"
"	border: 1px solid #ededed;\n"
"	selection-background-color: Black;\n"
"	selection-color: rgb(255, 255,255);\n"
"}"));
        transactionView->setFrameShape(QFrame::NoFrame);
        transactionView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        transactionView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        transactionView->setSelectionMode(QAbstractItemView::SingleSelection);
        transactionView->setSelectionBehavior(QAbstractItemView::SelectRows);
        transactionView->setShowGrid(false);
        transactionView->verticalHeader()->setVisible(false);
        transactionView->verticalHeader()->setDefaultSectionSize(20);
        transactionView->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_10->addWidget(transactionView);

        verticalLayout_10->setStretch(1, 1);

        verticalLayout_9->addWidget(wTransactionsContainer);


        retranslateUi(TransactionsPage);

        QMetaObject::connectSlotsByName(TransactionsPage);
    } // setupUi

    void retranslateUi(QWidget *TransactionsPage)
    {
        TransactionsPage->setWindowTitle(QApplication::translate("TransactionsPage", "Form", 0));
        label_21->setText(QApplication::translate("TransactionsPage", "Transactions", 0));
        bTransactionsSortOrder->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TransactionsPage: public Ui_TransactionsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONSPAGE_H
