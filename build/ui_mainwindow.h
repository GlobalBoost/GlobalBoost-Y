/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QWidget *wHeader;
    QHBoxLayout *horizontalLayout_4;
    QWidget *wLogo;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_9;
    QPushButton *bHome;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *bNewMessage;
    QVBoxLayout *verticalLayout_2;
    QWidget *wCaption;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *wCaptionButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QWidget *wMining;
    QLabel *label_16;
    QCheckBox *checkBox;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *bchat;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_trade;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *bAbout;
    QPushButton *bHelp;
    QStackedWidget *stackedWidget;
    QFrame *line_4;
    QWidget *wStatusBar;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_12;
    QProgressBar *progressBar;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(804, 400);
        MainWindow->setMaximumSize(QSize(804, 600));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow {\n"
"	background-color: white;\n"
"	/*margin: 6px;\n"
"	/*border: 6px solid rgba(0,0,0, 0);*/\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: white;\n"
"    border: 0px solid black;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    background-color: transparent;\n"
"	color: black;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: rgb(191,25,25);\n"
"	color: white;\n"
"}\n"
"\n"
"/* ================= combobox */\n"
"QComboBox {\n"
"    border: 1px solid #ededed;\n"
"    padding: 0px 18px 0px 3px;\n"
"    min-width: 20px;\n"
"	min-height: 20px;\n"
" }\n"
"\n"
" QComboBox:editable {\n"
"     background-color: rgb(192,25,25);\n"
" }\n"
"\n"
" QComboBox:!editable{\n"
"      background-color: white;\n"
" }\n"
"\n"
" QComboBox:!editable:on {\n"
"     background-color:rgb(191,25,25);\n"
" }\n"
"\n"
" QComboBox:!editable:off {\n"
"     background-color:rgb(191,25,25);\n"
" }\n"
"\n"
" QComboBox:on {\n"
"     /*padding-top: 3px;\n"
"     padding-left: 4px;*/\n"
" }\n"
"\n"
"QComboBox::drop-down {\n"
"    "
                        "subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"	background-color: rgb(191,25,25);\n"
"\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"}\n"
"QComboBox::drop-down:hover, QComboBox::drop-down:on {\n"
"	background-color: rgb(191,25,25);\n"
"}\n"
"\n"
" QComboBox::down-arrow {\n"
"	image: url(:/res/combo_arrow.png);\n"
" }\n"
"\n"
" QComboBox::down-arrow:on {\n"
"/*     top: 1px;\n"
"     left: 1px;*/\n"
" }\n"
"\n"
"/* =========== QLineEdit =============*/\n"
"QLineEdit {\n"
"	border: 1px solid #ededed;\n"
"\n"
"}\n"
"/* =========== header ===============*/\n"
"QWidget[is_header=\"true\"] {\n"
"	background-color: Black;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(6, 6, 6, 6);
        wHeader = new QWidget(centralWidget);
        wHeader->setObjectName(QStringLiteral("wHeader"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wHeader->sizePolicy().hasHeightForWidth());
        wHeader->setSizePolicy(sizePolicy);
        wHeader->setMinimumSize(QSize(0, 127));
        wHeader->setMaximumSize(QSize(16777215, 127));
        wHeader->setStyleSheet(QLatin1String("#wHeader {\n"
"	background-color: white;\n"
"}\n"
"\n"
"QWidget {\n"
"	color: black;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(wHeader);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        wLogo = new QWidget(wHeader);
        wLogo->setObjectName(QStringLiteral("wLogo"));
        wLogo->setMinimumSize(QSize(85, 0));
        wLogo->setMaximumSize(QSize(85, 16777215));
        wLogo->setStyleSheet(QLatin1String("#wHeader {\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(wLogo);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(wLogo);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        bHome = new QPushButton(widget);
        bHome->setObjectName(QStringLiteral("bHome"));
        bHome->setMinimumSize(QSize(85, 85));
        bHome->setMaximumSize(QSize(85, 85));
        bHome->setAutoFillBackground(false);
        bHome->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid gray;\n"
"	image: url(:/res/logo.png);\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"\n"
"}"));
        bHome->setIconSize(QSize(26, 23));
        bHome->setFlat(true);

        verticalLayout_9->addWidget(bHome);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        bNewMessage = new QPushButton(widget);
        bNewMessage->setObjectName(QStringLiteral("bNewMessage"));
        bNewMessage->setMinimumSize(QSize(30, 31));
        bNewMessage->setMaximumSize(QSize(30, 31));
        bNewMessage->setStyleSheet(QLatin1String("QPushButton:flat {\n"
"	border: 0px solid gray;\n"
"	image: url(:/res/icons/message.png);\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	image: url(:/res/mail/mail_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	image: url(:/res/mail/mail_hover.png);\n"
"}"));
        bNewMessage->setIconSize(QSize(26, 17));
        bNewMessage->setFlat(true);

        horizontalLayout_5->addWidget(bNewMessage);


        verticalLayout_9->addLayout(horizontalLayout_5);


        horizontalLayout_9->addLayout(verticalLayout_9);


        verticalLayout_7->addWidget(widget);


        horizontalLayout_4->addWidget(wLogo);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        wCaption = new QWidget(wHeader);
        wCaption->setObjectName(QStringLiteral("wCaption"));
        wCaption->setStyleSheet(QLatin1String("#wCaption {\n"
"	background-color: rgb(191, 25, 25);\n"
"}\n"
"\n"
"QWidget {\n"
"	color: white;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(wCaption);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(wCaption);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label = new QLabel(wCaption);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(11);
        label->setFont(font2);
        label->setStyleSheet(QLatin1String("QLabel {\n"
"	color: rgb(190, 191, 191);\n"
"}"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        verticalLayout->addWidget(label);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_9 = new QPushButton(wCaption);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(11);
        font3.setStyleStrategy(QFont::PreferAntialias);
        pushButton_9->setFont(font3);
        pushButton_9->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid #d5c3b4;\n"
"	margin: 0px;\n"
"	padding: 10px;\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border: 0px solid #d5c3b4;\n"
"	margin: 0px;\n"
"	background-color: rgb(180, 0, 0);\n"
"}"));
        pushButton_9->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_9);

        horizontalSpacer_10 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        pushButton_5 = new QPushButton(wCaption);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setFont(font3);
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid #d5c3b4;\n"
"	margin: 0px;\n"
"	padding: 10px;\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border: 0px solid #d5c3b4;\n"
"	margin: 0px;\n"
"	background-color: rgb(183, 0, 0);\n"
"}"));
        pushButton_5->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalSpacer_12 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        pushButton_3 = new QPushButton(wCaption);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid #d5c3b4;\n"
"	margin: 0px;\n"
"	padding: 10px;\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border: 0px solid #d5c3b4;\n"
"	margin: 0px;\n"
"	background-color: rgb(183, 0, 0);\n"
"}"));
        pushButton_3->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        wCaptionButtons = new QWidget(wCaption);
        wCaptionButtons->setObjectName(QStringLiteral("wCaptionButtons"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(wCaptionButtons->sizePolicy().hasHeightForWidth());
        wCaptionButtons->setSizePolicy(sizePolicy3);
        horizontalLayout = new QHBoxLayout(wCaptionButtons);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(wCaptionButtons);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid gray;\n"
"	image: url(:/res/minimize_normal.png);\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	border: 0px solid gray;\n"
"	image: url(:/res/minimize_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	image: url(:/res/minimize_hover.png);\n"
"}"));
        pushButton_2->setText(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setFlat(true);

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(wCaptionButtons);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setStyleSheet(QLatin1String("QPushButton {	\n"
"	image: url(:/res/close_normal.png);\n"
"	border: 0px solid gray;\n"
"}\n"
"QPushButton:pressed:flat {\n"
"	image: url(:/res/close_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	image: url(:/res/close_hover.png);\n"
"}"));
        pushButton->setText(QStringLiteral(""));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_2->addWidget(wCaptionButtons);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(7, 1);

        verticalLayout_2->addWidget(wCaption);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        wMining = new QWidget(wHeader);
        wMining->setObjectName(QStringLiteral("wMining"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(wMining->sizePolicy().hasHeightForWidth());
        wMining->setSizePolicy(sizePolicy4);
        wMining->setMinimumSize(QSize(90, 76));
        wMining->setMaximumSize(QSize(90, 16777215));
        wMining->setStyleSheet(QLatin1String("#wMining {\n"
"	background-color: white\n"
"}\n"
"\n"
"#wMining:hover {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"#wMining[is_pressed=\"true\"] {\n"
"	background-color: #B70000;\n"
"}\n"
"\n"
"#wMining[is_checked=\"true\"] {\n"
"	background-color: #ff0000;\n"
"}"));
        wMining->setProperty("is_checked", QVariant(false));
        wMining->setProperty("is_pressed", QVariant(false));
        label_16 = new QLabel(wMining);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 7, 41, 51));
        label_16->setStyleSheet(QStringLiteral(""));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/res/mining.png")));
        checkBox = new QCheckBox(wMining);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setGeometry(QRect(30, 40, 20, 20));
        checkBox->setStyleSheet(QLatin1String("/* =========== CheckBox ==============*/\n"
"QCheckBox {\n"
"    spacing: 5px;\n"
"	color: Black;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"	image: url(:/res/check_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover {\n"
"    image: url(:/res/check_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed {\n"
"    image: url(:/res/check_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"	image: url(:/res/check_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover {\n"
"    image: url(:/res/check_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:pressed {\n"
"    image: url(:/res/check_checked.png);\n"
"}\n"
""));
        checkBox->setCheckable(true);
        label_17 = new QLabel(wMining);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 57, 90, 20));
        label_17->setFont(font3);
        label_17->setStyleSheet(QLatin1String("QLabel {\n"
"	color: Black;\n"
"}"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(wMining);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bchat = new QPushButton(wHeader);
        bchat->setObjectName(QStringLiteral("bchat"));
        bchat->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/res/icons/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        bchat->setIcon(icon1);
        bchat->setIconSize(QSize(30, 30));

        gridLayout->addWidget(bchat, 0, 3, 1, 1);

        pushButton_12 = new QPushButton(wHeader);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy2.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(10);
        font4.setStyleStrategy(QFont::PreferAntialias);
        pushButton_12->setFont(font4);
        pushButton_12->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/icons/address_book.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon2);
        pushButton_12->setIconSize(QSize(30, 30));
        pushButton_12->setFlat(true);

        gridLayout->addWidget(pushButton_12, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(wHeader);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy2.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy2);
        pushButton_11->setFont(font4);
        pushButton_11->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color:#D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/icons/verify_message.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon3);
        pushButton_11->setIconSize(QSize(30, 30));
        pushButton_11->setFlat(true);

        gridLayout->addWidget(pushButton_11, 1, 2, 1, 1);

        pushButton_10 = new QPushButton(wHeader);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy2.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy2);
        pushButton_10->setFont(font4);
        pushButton_10->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/res/icons/sign_message.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon4);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);

        gridLayout->addWidget(pushButton_10, 0, 2, 1, 1);

        pushButton_8 = new QPushButton(wHeader);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy2.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy2);
        pushButton_8->setFont(font4);
        pushButton_8->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/res/icons/transactions.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon5);
        pushButton_8->setIconSize(QSize(30, 30));
        pushButton_8->setFlat(true);

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(wHeader);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);
        pushButton_7->setFont(font4);
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/res/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(30, 30));
        pushButton_7->setFlat(true);

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(wHeader);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_6->setFont(font4);
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/res/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon7);
        pushButton_6->setIconSize(QSize(30, 30));
        pushButton_6->setFlat(true);

        gridLayout->addWidget(pushButton_6, 0, 0, 1, 1);

        pushButton_trade = new QPushButton(wHeader);
        pushButton_trade->setObjectName(QStringLiteral("pushButton_trade"));
        sizePolicy2.setHeightForWidth(pushButton_trade->sizePolicy().hasHeightForWidth());
        pushButton_trade->setSizePolicy(sizePolicy2);
        pushButton_trade->setFont(font4);
        pushButton_trade->setStyleSheet(QLatin1String("QPushButton {\n"
"	text-align:left;\n"
"	border: 0px solid gray;\n"
"	padding: 3px 5px 3px 5px;\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	background-color: #D9D9D9;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #D9D9D9;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/trading"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_trade->setIcon(icon8);
        pushButton_trade->setIconSize(QSize(30, 30));
        pushButton_trade->setFlat(true);

        gridLayout->addWidget(pushButton_trade, 1, 3, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 5, -1);
        bAbout = new QPushButton(wHeader);
        bAbout->setObjectName(QStringLiteral("bAbout"));
        bAbout->setMinimumSize(QSize(30, 30));
        bAbout->setMaximumSize(QSize(30, 30));
        bAbout->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid gray;\n"
"	image: url(:/res/icons/Exclamation-mark.png);\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	image: url(:/res/about_pressed.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	image: url(:/res/about_hover.png);\n"
"}"));
        bAbout->setText(QStringLiteral(""));
        bAbout->setIconSize(QSize(26, 26));
        bAbout->setFlat(true);

        verticalLayout_3->addWidget(bAbout);

        bHelp = new QPushButton(wHeader);
        bHelp->setObjectName(QStringLiteral("bHelp"));
        bHelp->setMinimumSize(QSize(30, 30));
        bHelp->setMaximumSize(QSize(30, 30));
        bHelp->setStyleSheet(QLatin1String("QPushButton {\n"
"	border: 0px solid gray;\n"
"	image: url(:/res/icons/Question-mark.png);\n"
"}\n"
"\n"
"QPushButton:pressed:flat {\n"
"	image: url(:/res/help_pressed.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	image: url(:/res/help_hover.png);\n"
"}"));
        bHelp->setIconSize(QSize(26, 26));
        bHelp->setFlat(true);

        verticalLayout_3->addWidget(bHelp);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_8->addWidget(wHeader);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(804, 440));

        verticalLayout_8->addWidget(stackedWidget);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setStyleSheet(QStringLiteral("background-color: #C00000;"));
        line_4->setLineWidth(0);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_4);

        wStatusBar = new QWidget(centralWidget);
        wStatusBar->setObjectName(QStringLiteral("wStatusBar"));
        wStatusBar->setMinimumSize(QSize(0, 37));
        wStatusBar->setMaximumSize(QSize(16777215, 37));
        wStatusBar->setStyleSheet(QLatin1String("#wStatusBar {\n"
"	background-color: #BF1919;\n"
"}\n"
"QLabel {\n"
"	color: #c8e1e1;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(wStatusBar);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        label_12 = new QLabel(wStatusBar);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(263, 0));
        QFont font5;
        font5.setPointSize(10);
        label_12->setFont(font5);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_12);

        progressBar = new QProgressBar(wStatusBar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(208, 0));
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"    border: 0px solid grey;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #ff0000;\n"
"    /*width: 20px;*/\n"
"}"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        horizontalLayout_6->addWidget(progressBar);

        label_13 = new QLabel(wStatusBar);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font5);

        horizontalLayout_6->addWidget(label_13);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label_14 = new QLabel(wStatusBar);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setText(QStringLiteral(""));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/res/connection_1.png")));

        horizontalLayout_6->addWidget(label_14);

        horizontalSpacer_7 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(3, 1);

        verticalLayout_8->addWidget(wStatusBar);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), MainWindow, SLOT(gotoHistoryPage()));
        QObject::connect(bHome, SIGNAL(clicked()), MainWindow, SLOT(gotoOverviewPage()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), MainWindow, SLOT(menuFileRequested()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(menuOperationsRequested()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(menuSettingsRequested()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), MainWindow, SLOT(gotoReceiveCoinsPage()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), MainWindow, SLOT(gotoAddressBookPage()));
        QObject::connect(pushButton_trade, SIGNAL(clicked()), MainWindow, SLOT(gotoTradingPage()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), MainWindow, SLOT(gotoSendCoinsPage()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), MainWindow, SLOT(gotoSignMessageTab()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), MainWindow, SLOT(gotoVerifyMessageTab()));
        QObject::connect(bAbout, SIGNAL(clicked()), MainWindow, SLOT(aboutClicked()));

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        bHome->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Welcome to payment system GlobalBoost-Y BSTY. This is your personal account</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        bHome->setText(QString());
        bNewMessage->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "GlobalBoost-Y", 0));
        label->setText(QApplication::translate("MainWindow", "Digital Money", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "File", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Operations", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Settings", 0));
        label_16->setText(QString());
        checkBox->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "Mining", 0));
        bchat->setText(QApplication::translate("MainWindow", "IRC Chat", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "Address Book", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "Verify Message", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "Sign Message", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Transactions", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Receive BSTY", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Send BSTY</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QApplication::translate("MainWindow", "Send BSTY", 0));
        pushButton_trade->setText(QApplication::translate("MainWindow", "Trade", 0));
        bHelp->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Synchronization", 0));
        progressBar->setFormat(QString());
        label_13->setText(QApplication::translate("MainWindow", "10549874 blocks", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
