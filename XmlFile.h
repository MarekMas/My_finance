#ifndef XMLFILE_H
#define XMLFILE_H

#include <vector>
#include "Markup.h"
#include "Income.h"

class XmlFile
{
    const string FILE_NAME;
    CMarkup xmlFile;


    public:
        XmlFile(string fileName)
        : FILE_NAME(fileName){}
        bool addIncome(Income income);
        vector<Income> loadIncomesFromFile(int signedInUserId);

};

#endif // XMLFILE_H
