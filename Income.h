#ifndef INCOME_H
#define INCOME_H
#include "Date.h"
#include "Transaction.h"

using namespace std;
class Income : public Transaction
{
    int incomeId;

public:
    Income(){}
    Income(int incomeId, Date date, string item, float amount)
    :Transaction(date,item,amount)
    {
        this->incomeId = incomeId;
    }

    int getIncomeId();
    void setIncomeId(string newIncomeId);
    void setIncomeId(int IncomeId);
};
#endif // INCOME_H
