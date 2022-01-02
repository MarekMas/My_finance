#ifndef XMLFILE_H
#define XMLFILE_H

#include <vector>
#include "Markup.h"
#include "Income.h"

class XmlFile
{
    const string FILE_NAME;
    const string SIGNED_IN_USER_ID;
    CMarkup xml;

    public:
        XmlFile(string fileName, int signedInUserID )
        : FILE_NAME(fileName), SIGNED_IN_USER_ID(SupportingMethods::convrtIntToString(signedInUserID))
        {
        }

        void addIncome(Income income);
        vector<Income> loadIncomesFromFile();
        int findMaxIncomeId();
};

#endif // XMLFILE_H
