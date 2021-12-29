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
    Income(){};

    int getincomeId();
    string getDate();
    string getItem();
    float getAmount();
    void setincomeID(string IncomeId);
    void setDate (string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);


};
#endif // INCOME_H
