#ifndef MYFINANCE_H
#define MYFINANCE_H

#include "TransactionMenager.h"

using namespace std;

class MyFinance
{
    TransactionMenager *transactionMenager;

    public:
        MyFinance();
        void signIn();

};

#endif // MYFINANCE_H
