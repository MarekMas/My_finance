#include "Date.h"


void Date::seperateDay_Month_YearFromDate(string date)
{
    string temporaryPartOfDate = "";
    int j = 0;
    for(int i= 0; i < date.length(); i ++)
    {
        if(date[i] >= '0' && date[i] <='9')
        {
            temporaryPartOfDate += date[i];
            j++;
            if(j== 2)
            {
                day = SupportingMethods::convertStringToInt(temporaryPartOfDate);
                temporaryPartOfDate = "";
            }
            else if(j== 4)
            {
                month = SupportingMethods::convertStringToInt(temporaryPartOfDate);
                temporaryPartOfDate = "";
            }
            else if(j== 8)
            {
                year = SupportingMethods::convertStringToInt(temporaryPartOfDate);
                temporaryPartOfDate = "";
            }


        }
    }
}

string Date::getDateAsString()
{
    string day = "", month = "", year = "";

    if (this-> day < 10)
        day = "0" + SupportingMethods::convrtIntToString(this->day);
    else
        day = SupportingMethods::convrtIntToString(this->day);

    if (this-> month < 10)
        month = "0" + SupportingMethods::convrtIntToString(this->month);
    else
        month = SupportingMethods::convrtIntToString(this->month);

    year = SupportingMethods::convrtIntToString(this->year);

    return day + "-" + month + "-" + year;
}

bool Date::checkIfDateIsCorrect()
{
    time_t temporaryTime;
    tm actualTime;
    time( & temporaryTime );
    actualTime = *localtime( & temporaryTime );
    int currentYear = actualTime.tm_year + 1900;;
    int currentMonth = actualTime.tm_mon + 1;

    if (this->year >= 2000 && this->year =< currentYear)
    {
        this->month >= 1 && this->month =< currentMonth)
    }
    return true;
}
