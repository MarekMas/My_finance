#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include "Income.h"
#include "XmlIncomes.h"

using namespace std;


class TransactionMenager
{
    const int SIGNED_IN_USER_ID;
    int maxIncomeId;
    vector<Income> incomes;
    XmlIncomes xmlIncomes;

    public:
        TransactionMenager(int signedInUserId, string nameOfIncomeFile)
        : SIGNED_IN_USER_ID(signedInUserId), xmlIncomes(nameOfIncomeFile,signedInUserId)
        {
            incomes = xmlIncomes.loadIncomesFromFile();
            maxIncomeId = xmlIncomes.findMaxId("income");
        }
};

#endif // TRANSACTIONMENAGER_H
