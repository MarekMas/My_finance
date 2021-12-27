#ifndef DATE_H
#define DATE_H
#include "SupportingMethods.h"

using namespace std;

class Date
{
    int day;
    int month;
    int year;

    int howManyDaysHaveThisMonth();
    bool checkIfTheYearIsLeapYear();
    void setCurrentData();
    bool checkIfDateIsCorrect();

public:
    Date()
    {
        setCurrentData();
    }

    string getDateAsString();
    bool setDateByString(string date);

};

#endif // DATE_H
