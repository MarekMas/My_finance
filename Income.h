#ifndef INCOME_H
#define INCOME_H
#include "Date.h"

using namespace std;
class Income
{
    int incomeId;
    Date date;
    string item;
    float amount;
public:
    Income(){}
    Income(int incomeId, Date date, string item, float amount)
    {
        this->incomeId = incomeId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    int getincomeId();
    Date getDate();
    string getDateByString();
    string getItem();
    float getAmount();
    void setincomeID(string IncomeId);
    void setDate (string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);


};
#endif // INCOME_H
