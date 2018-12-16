/********************************************************************************
** Form generated from reading UI file 'Header.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADER_H
#define UI_HEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Header
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *logoLabel;
    QLabel *label;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Header)
    {
        if (Header->objectName().isEmpty())
            Header->setObjectName(QStringLiteral("Header"));
        Header->resize(847, 101);
        horizontalLayout = new QHBoxLayout(Header);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        logoLabel = new QLabel(Header);
        logoLabel->setObjectName(QStringLiteral("logoLabel"));

        verticalLayout_2->addWidget(logoLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        label = new QLabel(Header);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setPixmap(QPixmap(QString::fromUtf8(":/default/res/themes/default/logo.png")));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(517, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(Header);

        QMetaObject::connectSlotsByName(Header);
    } // setupUi

    void retranslateUi(QWidget *Header)
    {
        Header->setWindowTitle(QApplication::translate("Header", "Form", 0));
        logoLabel->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Header: public Ui_Header {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADER_H
