#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include "Income.h"
#include "XmlIncomes.h"
#include "Expense.h"
#include "XmlExpenses.h"

using namespace std;


class TransactionMenager
{
    const int SIGNED_IN_USER_ID;
    int maxIncomeId;
    int maxExpenseId;
    vector<Income> incomes;
    vector<Expense> expenses;
    XmlIncomes xmlIncomes;
    XmlExpenses xmlExpenses;

    Date selectDate();
    string selectIncomeItem();
    string selectExpenseItem();
    float setValueOfAmount();


    public:
        TransactionMenager(int signedInUserId, string nameOfIncomeFile, string nameOfExpenseFile)
        : SIGNED_IN_USER_ID(signedInUserId), xmlIncomes(nameOfIncomeFile,signedInUserId), xmlExpenses(nameOfExpenseFile, signedInUserId)
        {
            incomes = xmlIncomes.loadIncomesFromFile();
            maxIncomeId = xmlIncomes.findMaxId("income");
            expenses = xmlExpenses.loadExpensesFromFile();
            maxExpenseId = xmlExpenses.findMaxId("expense");
        }

        void addIncome();
        void addExpense();
};

#endif // TRANSACTIONMENAGER_H
