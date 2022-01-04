#include "Transaction.h"

string Transaction::getDateByString()
{
    return date.getDateAsString();
}

Date Transaction::getDate()
{
    return date;
}
string Transaction::getItem()
{
    return item;
}

float Transaction::getAmount()
{
    return amount;
}

void Transaction::setDate (string newDate)
{
    Date date;
    if(date.setDateByString(newDate))
        this->date = date;

}
void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(string newAmount)
{
    float amount = SupportingMethods::convertStringToFloat(newAmount);
    if(amount > 0)
        this->amount = amount;
}
