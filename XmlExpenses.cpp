#include "XmlExpenses.h"

void XmlExpenses::addExpense(Expense expense)
{
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Expense" );
    xml.IntoElem();
    xml.AddElem( "expenseId" , expense.getExpenseId());
    xml.AddElem( "userId" , SIGNED_IN_USER_ID);
    xml.AddElem( "date", expense.getDateByString());
    xml.AddElem( "item", expense.getItem());
    xml.AddElem( "amount", SupportingMethods::convertFloatToString(expense.getAmount()));
    xml.Save(FILE_NAME);
}

vector<Expense> XmlExpenses::loadExpensesFromFile()
{
    vector<Expense> expenses;
    Expense expense;

    if(xml.Load(FILE_NAME))
    {

        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("userId");
            if(SIGNED_IN_USER_ID == xml.GetData())
            {
                xml.FindElem("expenseId");
                expense.setExpenseId(xml.GetData());
                xml.FindElem("date");
                expense.setDate(xml.GetData());
                xml.FindElem("item");
                expense.setItem(xml.GetData());
                xml.FindElem("amount");
                expense.setAmount(xml.GetData());

                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }

    }
    else
    {
        xml.AddElem("Expenses");
    }
    return expenses;
}
