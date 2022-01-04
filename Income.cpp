#include "Income.h"


int Income::getIncomeId()
{
    return incomeId;
}


void Income::setincomeID(string newIncomeId)
{
    int incomeId = SupportingMethods::convertStringToInt(newIncomeId);
    if(incomeId >0)
       this->incomeId = incomeId;
}
