#ifndef MYFINANCE_H
#define MYFINANCE_H

#include "TransactionMenager.h"
#include "UserMenager.h"

using namespace std;

class MyFinance
{
    TransactionMenager *transactionMenager;
    UserMenager userMenager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    public:

    MyFinance(string userFileName, string incomesFileName, string expensesFileName)
    :userMenager(userFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        transactionMenager = NULL;
    }
    ~MyFinance()
    {
        delete transactionMenager;
        transactionMenager = NULL;
    }
    void signIn();
    void registeration();
    void changePassword();
    void signOut();
    void addIncome();
    void addExpence();
    void currentMontBalance();
    void lastMonthBalance();
    void selectScopeOfBalance();
    char selectOptionsFromTheMainMenu();
    char selectOptionsFromTheUserMenu();
    bool whetherTheUserIsSignedIn();

};

#endif // MYFINANCE_H
