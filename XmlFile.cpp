#include "XmlFile.h"

bool XmlFile::addIncome(Income income)
{

}

vector<Income> XmlFile::loadIncomesFromFile(int signedInUserId)
{
    string UserId = SupportingMethods::convrtIntToString(signedInUserId);
    vector<Income> incomes;
    Income income;

    if(xml.Load(FILE_NAME))
    {

        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("userId");
            if(UserId == xml.GetData())
            {
                xml.FindElem("incomeId");
                income.setincomeID(xml.GetData());
                xml.FindElem("date");
                income.setDate(xml.GetData());
                xml.FindElem("item");
                income.setItem(xml.GetData());
                xml.FindElem("amount");
                income.setAmount(xml.GetData());

                incomes.push_back(income);
            }
            xml.OutOfElem();
        }

    }
    else
    {
        xml.AddElem("Incomes");
    }
    return incomes;
}
