#include "XmlIncomes.h"

void XmlIncomes::addIncome(Income income)
{
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "incomeId" , income.getIncomeId());
    xml.AddElem( "userId" , SIGNED_IN_USER_ID);
    xml.AddElem( "date", income.getDateByString());
    xml.AddElem( "item", income.getItem());
    xml.AddElem( "amount", SupportingMethods::convertFloatToString(income.getAmount()));
    xml.Save(FILE_NAME);
}

vector<Income> XmlIncomes::loadIncomesFromFile()
{
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
            if(SIGNED_IN_USER_ID == xml.GetData())
            {
                xml.FindElem("incomeId");
                income.setIncomeId(xml.GetData());
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
