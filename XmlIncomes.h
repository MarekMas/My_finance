#ifndef XMLINCOMES_H
#define XMLINCOMES_H

#include "XmlFile.h"


class XmlIncomes : public XmlFile
{
    const string SIGNED_IN_USER_ID;
    public:
        XmlIncomes(string fileName, int signedInUserId)
        : XmlFile(fileName), SIGNED_IN_USER_ID(SupportingMethods::convrtIntToString(signedInUserId)){}
        void addIncome(Income income);
        vector<Income> loadIncomesFromFile();
};

#endif // XMLINCOMES_H
