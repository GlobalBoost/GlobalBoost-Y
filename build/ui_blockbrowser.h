/********************************************************************************
** Form generated from reading UI file 'blockbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKBROWSER_H
#define UI_BLOCKBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockBrowser
{
public:
    QGridLayout *gridLayout;
    QWidget *blockHeaderContainer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *blockHeader;
    QSpacerItem *horizontalSpacer_2;
    QWidget *blockContainer;
    QFormLayout *formLayout_4;
    QSpinBox *heightBox;
    QPushButton *blockButton;
    QGridLayout *bottomgrid;
    QLabel *timeLabel;
    QLabel *heightLabel;
    QLabel *heightLabel_2;
    QLabel *hashBox;
    QLabel *hashLabel;
    QLabel *merkleBox;
    QLabel *nonceLabel;
    QLabel *nonceBox;
    QLabel *bitsLabel;
    QLabel *bitsBox;
    QLabel *merkleLabel;
    QLabel *timeBox;
    QLabel *hardLabel;
    QLabel *hardBox;
    QLabel *pawLabel;
    QLabel *pawBox;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *txBox;
    QPushButton *txButton;
    QGridLayout *topgrid;
    QLabel *txLabel;
    QLabel *txID;
    QLabel *valueLabel;
    QLabel *valueBox;
    QLabel *feesLabel;
    QLabel *feesBox;
    QLabel *outputLabel;
    QLabel *outputBox;
    QLabel *inputLabel;
    QLabel *inputBox;

    void setupUi(QWidget *BlockBrowser)
    {
        if (BlockBrowser->objectName().isEmpty())
            BlockBrowser->setObjectName(QStringLiteral("BlockBrowser"));
        BlockBrowser->setWindowModality(Qt::NonModal);
        BlockBrowser->setEnabled(true);
        BlockBrowser->resize(1000, 548);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BlockBrowser->sizePolicy().hasHeightForWidth());
        BlockBrowser->setSizePolicy(sizePolicy);
        BlockBrowser->setAcceptDrops(false);
        gridLayout = new QGridLayout(BlockBrowser);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        blockHeaderContainer = new QWidget(BlockBrowser);
        blockHeaderContainer->setObjectName(QStringLiteral("blockHeaderContainer"));
        horizontalLayout_4 = new QHBoxLayout(blockHeaderContainer);
        horizontalLayout_4->setSpacing(7);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 5, -1, 5);
        blockHeader = new QLabel(blockHeaderContainer);
        blockHeader->setObjectName(QStringLiteral("blockHeader"));

        horizontalLayout_4->addWidget(blockHeader);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addWidget(blockHeaderContainer, 0, 0, 1, 1);

        blockContainer = new QWidget(BlockBrowser);
        blockContainer->setObjectName(QStringLiteral("blockContainer"));
        formLayout_4 = new QFormLayout(blockContainer);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_4->setHorizontalSpacing(0);
        formLayout_4->setVerticalSpacing(0);
        heightBox = new QSpinBox(blockContainer);
        heightBox->setObjectName(QStringLiteral("heightBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(heightBox->sizePolicy().hasHeightForWidth());
        heightBox->setSizePolicy(sizePolicy1);
        heightBox->setMinimumSize(QSize(531, 0));
        heightBox->setMaximum(99999999);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, heightBox);

        blockButton = new QPushButton(blockContainer);
        blockButton->setObjectName(QStringLiteral("blockButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(blockButton->sizePolicy().hasHeightForWidth());
        blockButton->setSizePolicy(sizePolicy2);
        blockButton->setMinimumSize(QSize(0, 30));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, blockButton);

        bottomgrid = new QGridLayout();
        bottomgrid->setObjectName(QStringLiteral("bottomgrid"));
        bottomgrid->setContentsMargins(-1, 0, -1, -1);
        timeLabel = new QLabel(blockContainer);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        bottomgrid->addWidget(timeLabel, 0, 0, 1, 1);

        heightLabel = new QLabel(blockContainer);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));
        heightLabel->setMinimumSize(QSize(550, 0));

        bottomgrid->addWidget(heightLabel, 0, 1, 1, 1);

        heightLabel_2 = new QLabel(blockContainer);
        heightLabel_2->setObjectName(QStringLiteral("heightLabel_2"));

        bottomgrid->addWidget(heightLabel_2, 1, 0, 1, 1);

        hashBox = new QLabel(blockContainer);
        hashBox->setObjectName(QStringLiteral("hashBox"));
        hashBox->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(hashBox->sizePolicy().hasHeightForWidth());
        hashBox->setSizePolicy(sizePolicy3);
        hashBox->setMinimumSize(QSize(0, 0));

        bottomgrid->addWidget(hashBox, 1, 1, 1, 1);

        hashLabel = new QLabel(blockContainer);
        hashLabel->setObjectName(QStringLiteral("hashLabel"));

        bottomgrid->addWidget(hashLabel, 2, 0, 1, 1);

        merkleBox = new QLabel(blockContainer);
        merkleBox->setObjectName(QStringLiteral("merkleBox"));
        merkleBox->setMinimumSize(QSize(187, 0));

        bottomgrid->addWidget(merkleBox, 2, 1, 1, 1);

        nonceLabel = new QLabel(blockContainer);
        nonceLabel->setObjectName(QStringLiteral("nonceLabel"));

        bottomgrid->addWidget(nonceLabel, 3, 0, 1, 1);

        nonceBox = new QLabel(blockContainer);
        nonceBox->setObjectName(QStringLiteral("nonceBox"));

        bottomgrid->addWidget(nonceBox, 3, 1, 1, 1);

        bitsLabel = new QLabel(blockContainer);
        bitsLabel->setObjectName(QStringLiteral("bitsLabel"));

        bottomgrid->addWidget(bitsLabel, 4, 0, 1, 1);

        bitsBox = new QLabel(blockContainer);
        bitsBox->setObjectName(QStringLiteral("bitsBox"));

        bottomgrid->addWidget(bitsBox, 4, 1, 1, 1);

        merkleLabel = new QLabel(blockContainer);
        merkleLabel->setObjectName(QStringLiteral("merkleLabel"));

        bottomgrid->addWidget(merkleLabel, 5, 0, 1, 1);

        timeBox = new QLabel(blockContainer);
        timeBox->setObjectName(QStringLiteral("timeBox"));

        bottomgrid->addWidget(timeBox, 5, 1, 1, 1);

        hardLabel = new QLabel(blockContainer);
        hardLabel->setObjectName(QStringLiteral("hardLabel"));

        bottomgrid->addWidget(hardLabel, 6, 0, 1, 1);

        hardBox = new QLabel(blockContainer);
        hardBox->setObjectName(QStringLiteral("hardBox"));

        bottomgrid->addWidget(hardBox, 6, 1, 1, 1);

        pawLabel = new QLabel(blockContainer);
        pawLabel->setObjectName(QStringLiteral("pawLabel"));

        bottomgrid->addWidget(pawLabel, 7, 0, 1, 1);

        pawBox = new QLabel(blockContainer);
        pawBox->setObjectName(QStringLiteral("pawBox"));

        bottomgrid->addWidget(pawBox, 7, 1, 1, 1);


        formLayout_4->setLayout(1, QFormLayout::SpanningRole, bottomgrid);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_4->setItem(2, QFormLayout::LabelRole, verticalSpacer_2);

        txBox = new QLineEdit(blockContainer);
        txBox->setObjectName(QStringLiteral("txBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(txBox->sizePolicy().hasHeightForWidth());
        txBox->setSizePolicy(sizePolicy4);
        txBox->setMinimumSize(QSize(531, 0));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, txBox);

        txButton = new QPushButton(blockContainer);
        txButton->setObjectName(QStringLiteral("txButton"));
        sizePolicy2.setHeightForWidth(txButton->sizePolicy().hasHeightForWidth());
        txButton->setSizePolicy(sizePolicy2);
        txButton->setMinimumSize(QSize(0, 30));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, txButton);

        topgrid = new QGridLayout();
        topgrid->setObjectName(QStringLiteral("topgrid"));
        topgrid->setContentsMargins(-1, 9, -1, 9);
        txLabel = new QLabel(blockContainer);
        txLabel->setObjectName(QStringLiteral("txLabel"));

        topgrid->addWidget(txLabel, 0, 0, 1, 1);

        txID = new QLabel(blockContainer);
        txID->setObjectName(QStringLiteral("txID"));

        topgrid->addWidget(txID, 0, 1, 1, 1);

        valueLabel = new QLabel(blockContainer);
        valueLabel->setObjectName(QStringLiteral("valueLabel"));

        topgrid->addWidget(valueLabel, 1, 0, 1, 1);

        valueBox = new QLabel(blockContainer);
        valueBox->setObjectName(QStringLiteral("valueBox"));

        topgrid->addWidget(valueBox, 1, 1, 1, 1);

        feesLabel = new QLabel(blockContainer);
        feesLabel->setObjectName(QStringLiteral("feesLabel"));

        topgrid->addWidget(feesLabel, 2, 0, 1, 1);

        feesBox = new QLabel(blockContainer);
        feesBox->setObjectName(QStringLiteral("feesBox"));

        topgrid->addWidget(feesBox, 2, 1, 1, 1);

        outputLabel = new QLabel(blockContainer);
        outputLabel->setObjectName(QStringLiteral("outputLabel"));
        outputLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        topgrid->addWidget(outputLabel, 3, 0, 1, 1);

        outputBox = new QLabel(blockContainer);
        outputBox->setObjectName(QStringLiteral("outputBox"));
        outputBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        topgrid->addWidget(outputBox, 3, 1, 1, 1);

        inputLabel = new QLabel(blockContainer);
        inputLabel->setObjectName(QStringLiteral("inputLabel"));
        inputLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        topgrid->addWidget(inputLabel, 4, 0, 1, 1);

        inputBox = new QLabel(blockContainer);
        inputBox->setObjectName(QStringLiteral("inputBox"));
        inputBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        topgrid->addWidget(inputBox, 4, 1, 1, 1);


        formLayout_4->setLayout(5, QFormLayout::SpanningRole, topgrid);

        txButton->raise();
        heightBox->raise();
        blockButton->raise();
        txBox->raise();

        gridLayout->addWidget(blockContainer, 1, 0, 1, 1);


        retranslateUi(BlockBrowser);

        QMetaObject::connectSlotsByName(BlockBrowser);
    } // setupUi

    void retranslateUi(QWidget *BlockBrowser)
    {
        BlockBrowser->setWindowTitle(QApplication::translate("BlockBrowser", "Form", 0));
        blockHeader->setText(QApplication::translate("BlockBrowser", "Block Explorer ", 0));
        blockButton->setText(QApplication::translate("BlockBrowser", "Jump to Block", 0));
        timeLabel->setText(QApplication::translate("BlockBrowser", "Block Timestamp:", 0));
        heightLabel->setText(QApplication::translate("BlockBrowser", "0", 0));
        heightLabel_2->setText(QApplication::translate("BlockBrowser", "Block Height:", 0));
        hashBox->setText(QApplication::translate("BlockBrowser", "0x0", 0));
        hashLabel->setText(QApplication::translate("BlockBrowser", "Block Hash:", 0));
        merkleBox->setText(QApplication::translate("BlockBrowser", "0x0", 0));
        nonceLabel->setText(QApplication::translate("BlockBrowser", "Block nNonce:", 0));
        nonceBox->setText(QApplication::translate("BlockBrowser", "0", 0));
        bitsLabel->setText(QApplication::translate("BlockBrowser", "Block nBits:", 0));
        bitsBox->setText(QApplication::translate("BlockBrowser", "0", 0));
        merkleLabel->setText(QApplication::translate("BlockBrowser", "Block Merkle:", 0));
        timeBox->setText(QApplication::translate("BlockBrowser", "0", 0));
        hardLabel->setText(QApplication::translate("BlockBrowser", "Block Difficulty:", 0));
        hardBox->setText(QApplication::translate("BlockBrowser", "0.00", 0));
        pawLabel->setText(QApplication::translate("BlockBrowser", "Block Hashrate:", 0));
        pawBox->setText(QApplication::translate("BlockBrowser", "0000 KH/s", 0));
        txBox->setInputMask(QString());
        txBox->setPlaceholderText(QString());
        txButton->setText(QApplication::translate("BlockBrowser", "Decode Transaction", 0));
        txLabel->setText(QApplication::translate("BlockBrowser", "Transaction ID:", 0));
        txID->setText(QApplication::translate("BlockBrowser", "000", 0));
        valueLabel->setText(QApplication::translate("BlockBrowser", "Value out:", 0));
        valueBox->setText(QString());
        feesLabel->setText(QApplication::translate("BlockBrowser", "Fees:", 0));
        feesBox->setText(QString());
        outputLabel->setText(QApplication::translate("BlockBrowser", "Outputs:", 0));
        outputBox->setText(QString());
        inputLabel->setText(QApplication::translate("BlockBrowser", "Inputs:", 0));
        inputBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BlockBrowser: public Ui_BlockBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKBROWSER_H
