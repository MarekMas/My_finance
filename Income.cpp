#include "Income.h"


int Income::getincomeId()
{
    return incomeId;
}

string Income::getDateByString()
{
    return date.getDateAsString();
}

Date Income::getDate()
{
    return date;
}
string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}

void Income::setincomeID(string newIncomeId)
{
    int incomeId = SupportingMethods::convertStringToInt(newIncomeId);
    if(incomeId >0)
       this->incomeId = incomeId;
}
void Income::setDate (string newDate)
{
    Date date;
    if(date.setDateByString(newDate))
        this->date = date;

}
void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(string newAmount)
{
    float amount = SupportingMethods::convertStringToFloat(newAmount);
    if(amount > 0)
        this->amount = amount;
}
