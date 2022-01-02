#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include "Income.h"
#include "XmlFile.h"

using namespace std;


class TransactionMenager
{
    const int SIGNED_IN_USER_ID;
    int maxIncomeId;
    vector<Income> incomes;
    XmlFile xmlFile;

    public:
        TransactionMenager(int signedInUserId, string nameOfIncomeFile)
        : SIGNED_IN_USER_ID(signedInUserId), xmlFile(nameOfIncomeFile,signedInUserId)
        {
            incomes = xmlFile.loadIncomesFromFile();
            maxIncomeId = xmlFile.findMaxIncomeId();
        }
};

#endif // TRANSACTIONMENAGER_H
