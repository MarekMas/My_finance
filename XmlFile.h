#ifndef XMLFILE_H
#define XMLFILE_H

#include <vector>
#include "Markup.h"
#include "Income.h"
#include "Expense.h"

class XmlFile
{
    protected:
    const string FILE_NAME;
    CMarkup xml;

    public:
        XmlFile(string fileName)
        : FILE_NAME(fileName)
        {
        }
        int findMaxId(string attribute);

};

#endif // XMLFILE_H
