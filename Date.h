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
    bool checkIfDateIsCorrect();

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    bool operator < (Date &obj);
    bool operator > (Date &obj);
    bool operator == (Date &obj);

    string getDateAsString();
    int getMonth();
    bool setDateByString(string date);
    void setDay(int day);
    void setMonth(int month);
    void setLastDayOfMonth();

    void setCurrentDate();


};

#endif // DATE_H
