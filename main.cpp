#include <iostream>
#include "Income.h"
#include "Date.h"

using namespace std;

int main()
{
    Date date("29.02.2019");
    if(date.checkIfDateIsCorrect())
        cout << "Date " << date.getDateAsString() << " is Correct"  << endl;
    else
        cout << "Date " << date.getDateAsString() << " is Wrong"  << endl;

    return 0;
}
