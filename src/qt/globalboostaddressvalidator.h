// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GLOBALBOOST_QT_GLOBALBOOSTADDRESSVALIDATOR_H
#define GLOBALBOOST_QT_GLOBALBOOSTADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class GlobalBoostAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GlobalBoostAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** GlobalBoost address widget validator, checks for a valid globalboost address.
 */
class GlobalBoostAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GlobalBoostAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // GLOBALBOOST_QT_GLOBALBOOSTADDRESSVALIDATOR_H
