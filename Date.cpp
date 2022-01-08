#include "Date.h"
#include <ctime>


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
    int currentYear = actualTime.tm_year + 1900;
    int currentMonth = actualTime.tm_mon + 1;


    if (this->year >= 2000 && this->year < currentYear)
    {
        if(this->month >= 1 && this->month <= 12)
        {
            if(this->day >=1 && this->day <= howManyDaysHaveThisMonth())
                return true;
        }
    }
    else if (this->year == currentYear)
    {
        if(this->month >= 1 && this->month <= currentMonth)
        {
            if(this->day >=1 && this->day <= howManyDaysHaveThisMonth())
                return true;
        }
    }
    return false;
}

int Date::howManyDaysHaveThisMonth()
{
    switch(month)
    {
    case 1: return 31;
    break;

    case 2: if(checkIfTheYearIsLeapYear())
               return 29;
            else
                return 28;
    break;

    case 3: return 31;
    break;

    case 4: return 30;
    break;

    case 5: return 31;
    break;

    case 6: return 30;
    break;

    case 7: return 31;
    break;

    case 8: return 31;
    break;

    case 9: return 30;
    break;

    case 10: return 31;
    break;

    case 11: return 30;
    break;

    case 12: return 31;

    default:
        return 0;
    }
}

bool Date::checkIfTheYearIsLeapYear()
{
    return (this->year % 4 == 0 && this->year % 100 != 0) || (this->year% 400 == 0);

}

bool Date::setDateByString(string date)
{
    string temporaryPartOfDate = "";
    this->day = 0;
    this->month = 0;
    this->year = 0;
    int j = 0;
    for(int i= 0; i < date.length(); i ++)
    {
        if(date[i] >= '0' && date[i] <='9')
        {
            temporaryPartOfDate += date[i];
            j++;
            if(j== 4)
            {
                this->year = SupportingMethods::convertStringToInt(temporaryPartOfDate);
                temporaryPartOfDate = "";
            }
            else if(j== 6)
            {
                this->month = SupportingMethods::convertStringToInt(temporaryPartOfDate);
                temporaryPartOfDate = "";
            }
            else if(j== 8)
            {
                this->day = SupportingMethods::convertStringToInt(temporaryPartOfDate);
                temporaryPartOfDate = "";
            }


        }
    }
    return checkIfDateIsCorrect();
}

void Date::setCurrentData()
{
    time_t temporaryTime;
    tm actualTime;
    time( & temporaryTime );
    actualTime = *localtime( & temporaryTime );
    this->year = actualTime.tm_year + 1900;
    this->month = actualTime.tm_mon + 1;
    this->day = actualTime.tm_mday;
}

bool Date::operator < (Date &obj)
    {
        if (this->year < obj.year)
            return true;
        else if(this->year == obj.year)
        {
            if(this->month < obj.month)
                return true;
            else if(this->month == obj.month)
            {
                if(this->day < obj.day)
                    return true;
            }
        }
        return false;
    }

 bool Date::operator > (Date &obj)
 {
     if (this->year > obj.year)
        return true;
    else if(this->year == obj.year)
    {
        if(this->month > obj.month)
            return true;
        else if(this->month == obj.month)
        {
            if(this->day > obj.day)
                return true;
        }
    }
    return false;
 }

 bool Date::operator == (Date &obj)
 {
     return (this->year == obj.year && this->month == obj.month && this->day == obj.day);
 }

