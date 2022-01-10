#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Date.h"


class Transaction
{
    Date date;
    string item;
    float amount;
    public:
        Transaction(){}
        Transaction(Date date, string item, float amount)
        {
            this->date = date;
            this->item = item;
            this->amount = amount;
        }

    Date getDate();
    string getDateByString();
    string getItem();
    float getAmount();
    void setDate (string newDate);
    void setDate (Date date);
    void setItem(string newItem);
    void setAmount(string newAmount);
    void setAmount(float amount);

    bool operator < (Transaction& str);
};

#endif // TRANSACTION_H
