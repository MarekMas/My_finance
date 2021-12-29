#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include "Income.h"
#include "XmlFile.h"

using namespace std;


class TransactionMenager
{
    const int SIGNED_IN_USER_ID;
    CMarkup xmlIncomes;
    XmlFile xmlFile;

    public:
        TransactionMenager(int signedInUserId, string nameOfIncomeFile)
        : SIGNED_IN_USER_ID(signedInUserId), xmlFile(nameOfIncomeFile)
        {

        }
};

#endif // TRANSACTIONMENAGER_H
