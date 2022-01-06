#ifndef MYFINANCE_H
#define MYFINANCE_H

#include "TransactionMenager.h"
#include "UserMenager.h"

using namespace std;

class MyFinance
{
    TransactionMenager *transactionMenager;
    UserMenager userMenager;

    public:

    MyFinance(string userFileName)
    :userMenager(userFileName){}
    void signIn();
    void registeration();
    void changePassword();
    void signOut();
    char selectOptionsFromTheMainMenu();

};

#endif // MYFINANCE_H
