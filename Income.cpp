#include "Income.h"


int Income::getIncomeId()
{
    return incomeId;
}


void Income::setIncomeId(string newIncomeId)
{
    int incomeId = SupportingMethods::convertStringToInt(newIncomeId);
    if(incomeId >0)
       this->incomeId = incomeId;
}

void Income::setIncomeId(int incomeId)
{
    if(incomeId > 0)
        this->incomeId = incomeId;
}
