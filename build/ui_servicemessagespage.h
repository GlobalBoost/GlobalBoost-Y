/********************************************************************************
** Form generated from reading UI file 'servicemessagespage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVICEMESSAGESPAGE_H
#define UI_SERVICEMESSAGESPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServiceMessagesPage
{
public:
    QVBoxLayout *verticalLayout_15;
    QWidget *wServiceMessagesHeader;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_33;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_16;
    QWidget *wServiceMessages;
    QVBoxLayout *verticalLayout_16;
    QGridLayout *gridLayout_4;
    QLabel *label_35;
    QLabel *label_36;
    QSpacerItem *horizontalSpacer_27;
    QHBoxLayout *horizontalLayout;
    QTableView *tableServiceMessagesView;

    void setupUi(QWidget *ServiceMessagesPage)
    {
        if (ServiceMessagesPage->objectName().isEmpty())
            ServiceMessagesPage->setObjectName(QStringLiteral("ServiceMessagesPage"));
        ServiceMessagesPage->resize(785, 440);
        QPalette palette;
        QBrush brush(QColor(215, 234, 235, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(235, 235, 235, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        QBrush brush2(QColor(124, 175, 172, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush3(QColor(240, 240, 240, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        ServiceMessagesPage->setPalette(palette);
        verticalLayout_15 = new QVBoxLayout(ServiceMessagesPage);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        wServiceMessagesHeader = new QWidget(ServiceMessagesPage);
        wServiceMessagesHeader->setObjectName(QStringLiteral("wServiceMessagesHeader"));
        wServiceMessagesHeader->setMinimumSize(QSize(0, 32));
        wServiceMessagesHeader->setMaximumSize(QSize(16777215, 32));
        wServiceMessagesHeader->setStyleSheet(QStringLiteral(""));
        wServiceMessagesHeader->setProperty("is_header", QVariant(true));
        horizontalLayout_19 = new QHBoxLayout(wServiceMessagesHeader);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        line = new QFrame(wServiceMessagesHeader);
        line->setObjectName(QStringLiteral("line"));
        line->setMaximumSize(QSize(16777215, 8));
        line->setStyleSheet(QStringLiteral("background-color: rgb(170, 0, 0);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_26 = new QSpacerItem(7, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_26);

        label_33 = new QLabel(wServiceMessagesHeader);
        label_33->setObjectName(QStringLiteral("label_33"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy);
        label_33->setMinimumSize(QSize(30, 30));
        label_33->setMaximumSize(QSize(30, 30));
        label_33->setPixmap(QPixmap(QString::fromUtf8(":/res/mail/mail_normal.png")));

        horizontalLayout_3->addWidget(label_33);

        label_34 = new QLabel(wServiceMessagesHeader);
        label_34->setObjectName(QStringLiteral("label_34"));
        QFont font;
        font.setPointSize(11);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_34->setFont(font);
        label_34->setStyleSheet(QLatin1String("QLabel {\n"
"	color: #ff0000;\n"
"}"));

        horizontalLayout_3->addWidget(label_34);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_19->addLayout(verticalLayout_2);


        verticalLayout_15->addWidget(wServiceMessagesHeader);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        wServiceMessages = new QWidget(ServiceMessagesPage);
        wServiceMessages->setObjectName(QStringLiteral("wServiceMessages"));
        wServiceMessages->setStyleSheet(QLatin1String("#wServiceMessages {\n"
"	background-color: #990000;\n"
"}"));
        verticalLayout_16 = new QVBoxLayout(wServiceMessages);
        verticalLayout_16->setSpacing(4);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(15, 8, 15, 30);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_35 = new QLabel(wServiceMessages);
        label_35->setObjectName(QStringLiteral("label_35"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy1);
        label_35->setMaximumSize(QSize(120, 16777215));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_35->setFont(font1);
        label_35->setStyleSheet(QLatin1String("QLabel {\n"
"	color:white;\n"
"}"));

        gridLayout_4->addWidget(label_35, 1, 1, 1, 1);

        label_36 = new QLabel(wServiceMessages);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font1);
        label_36->setStyleSheet(QLatin1String("QLabel {\n"
"	color: white;\n"
"}"));

        gridLayout_4->addWidget(label_36, 1, 2, 1, 1);

        horizontalSpacer_27 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_27, 1, 0, 1, 1);


        verticalLayout_16->addLayout(gridLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableServiceMessagesView = new QTableView(wServiceMessages);
        tableServiceMessagesView->setObjectName(QStringLiteral("tableServiceMessagesView"));
        tableServiceMessagesView->setMaximumSize(QSize(16777215, 350));
        tableServiceMessagesView->setStyleSheet(QLatin1String(" QScrollBar:vertical {\n"
"     border: 0px solid grey;\n"
"     background: white;\n"
"     width: 9px;\n"
"     margin: 0px 0px 0 0px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background: #90bfbc;\n"
"     min-width: 20px;\n"
" }\n"
"\n"
"QHeaderView {\n"
"	background-color: #d7eaeb;\n"
"	font-size: 10;\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #d7eaeb;\n"
"    color: #1cbbb4;\n"
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
"	selection-background-color: #ebebeb;\n"
"	selection-color: rgb(124, 175, 172);\n"
"}"));
        tableServiceMessagesView->setFrameShape(QFrame::NoFrame);
        tableServiceMessagesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableServiceMessagesView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableServiceMessagesView->setTextElideMode(Qt::ElideRight);
        tableServiceMessagesView->setShowGrid(false);
        tableServiceMessagesView->setWordWrap(true);
        tableServiceMessagesView->horizontalHeader()->setVisible(false);
        tableServiceMessagesView->verticalHeader()->setVisible(false);
        tableServiceMessagesView->verticalHeader()->setDefaultSectionSize(20);
        tableServiceMessagesView->verticalHeader()->setMinimumSectionSize(20);

        horizontalLayout->addWidget(tableServiceMessagesView);


        verticalLayout_16->addLayout(horizontalLayout);


        horizontalLayout_16->addWidget(wServiceMessages);


        verticalLayout_15->addLayout(horizontalLayout_16);


        retranslateUi(ServiceMessagesPage);

        QMetaObject::connectSlotsByName(ServiceMessagesPage);
    } // setupUi

    void retranslateUi(QWidget *ServiceMessagesPage)
    {
        ServiceMessagesPage->setWindowTitle(QApplication::translate("ServiceMessagesPage", "Form", 0));
        label_33->setText(QString());
        label_34->setText(QApplication::translate("ServiceMessagesPage", "Messages from GlobalBoost", 0));
        label_35->setText(QApplication::translate("ServiceMessagesPage", "Date", 0));
        label_36->setText(QApplication::translate("ServiceMessagesPage", "Message content", 0));
    } // retranslateUi

};

namespace Ui {
    class ServiceMessagesPage: public Ui_ServiceMessagesPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVICEMESSAGESPAGE_H
