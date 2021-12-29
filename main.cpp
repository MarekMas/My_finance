#include <iostream>
#include "Income.h"
#include "Date.h"

using namespace std;

int main()
{


    Date date;
    Date date2;
    date.setDateByString("12.02.2012");
    date2.setDateByString("15-02.2012");

    if(date < date2)
    {
        cout <<  date.getDateAsString() << " is before " << date2.getDateAsString()  << endl;
    }

    else
        cout <<  date.getDateAsString() << " is after " << date2.getDateAsString()  << endl;





    return 0;
}
