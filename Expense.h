#ifndef EXPENSE_H
#define EXPENSE_H

#include "Transaction.h"


class Expense : public Transaction
{
    int expenseId;
    public:
    Expense(){}
    Expense(int ExpenseId, Date date, string item, float amount)
    :Transaction(date,item,amount)
    {
        this->expenseId = expenseId;
    }

    int getExpenseId();
    void setExpenseId(string newExpenseId);
    void setExpenseId(int expenseId);
};

#endif // EXPENSE_H
