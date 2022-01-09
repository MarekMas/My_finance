#include "Expense.h"

int Expense::getExpenseId()
{
    return expenseId;
}


void Expense::setExpenseId(string newExpenseId)
{
    int expenseId = SupportingMethods::convertStringToInt(newExpenseId);
    if(expenseId > 0)
       this->expenseId = expenseId;
}

void Expense::setExpenseId(int expenseId)
{
    if(expenseId > 0)
       this->expenseId = expenseId;
}
