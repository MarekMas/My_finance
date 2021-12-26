#include <iostream>
#include "Income.h"
#include "Date.h"

using namespace std;

int main()
{
    Income income;
    income.setDate("12.09.2021");
    cout << income.getDate() << endl;

    return 0;
}
