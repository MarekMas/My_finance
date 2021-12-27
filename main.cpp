#include <iostream>
#include "Income.h"
#include "Date.h"

using namespace std;

int main()
{
    Date date;
    if(date.setDateByString("12.02.2012"))
        cout << "Date " << date.getDateAsString() << " is Correct"  << endl;
    else
        cout << "Date " << date.getDateAsString() << " is Wrong"  << endl;

    Date date2 = date;

    cout << "Look at this " << date.getDateAsString()  << endl;


    return 0;
}
