#include "Income.h"


int Income::getincomeId()
{
    return incomeId;
}

string Income::getDate()
{
    return date.getDateAsString();
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}

void Income::setincomeID(int newIncomeId)
{
    if (newIncomeId >0)
       incomeId = newIncomeId;
}
bool Income::setDate (string newDate)
{

}
void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(float newAmount)
{
    if(newAmount > 0)
        amount = newAmount;
}
