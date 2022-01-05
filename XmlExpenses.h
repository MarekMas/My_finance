#ifndef XMLEXPENSES_H
#define XMLEXPENSES_H

#include "XmlFile.h"


class XmlExpenses : public XmlFile
{
    const string SIGNED_IN_USER_ID;
    public:
        XmlExpenses(string fileName, int signedInUserId)
        : XmlFile(fileName), SIGNED_IN_USER_ID(SupportingMethods::convrtIntToString(signedInUserId)){}
        void addExpense(Expense expense);
        vector<Expense> loadExpensesFromFile();
};

#endif // XMLEXPENSES_H
