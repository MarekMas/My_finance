#ifndef DATE_H
#define DATE_H
#include "SupportingMethods.h"

using namespace std;

class Date
{
    int day;
    int month;
    int year;

    void seperateDay_Month_YearFromDate(string date);
    int howManyDaysHaveThisMonth();
    bool checkIfTheYearIsLeapYear();

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(string date )
    {
        day = 0;
        month = 0;
        year = 0;
        seperateDay_Month_YearFromDate(date);
    }

    string getDateAsString();
    bool checkIfDateIsCorrect();
};

#endif // DATE_H
