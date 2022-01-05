#include <iostream>
#include "Income.h"
#include "Date.h"
#include "XmlFile.h"
#include "TransactionMenager.h"

using namespace std;

int main1() //Porównywanie dat
{
    Date date1;
    Date date2;
    date2.setDateByString("31-12-2021");
    if(date1 > date2)
        cout << "data " << date1.getDateAsString() << " jest wieksza niz / mlodsza od " << date2.getDateAsString();

    return 0;

}
int main2()
{   //Wczytywanie z pliku xml i dodawanie do pliku
    Date date;
    XmlIncomes xmlFile("income.xml", 1);
    vector<Income> incomes = xmlFile.loadIncomesFromFile();
    Income income1(1,date,"loan",200.10);
    xmlFile.addIncome(income1);
    Income income2(2,date,"salary",465.49);
    xmlFile.addIncome(income2);

    return 0;
}

int main3()
{
    //sprawdzenie poprawnoœci daty
    Date date;
    if (date.setDateByString("28.02.2021"))
        cout << "Data prawidlowa" << endl;
    else
        cout << "Data nieprawidlowa" << endl;
    return 0;
}

int main()
{
    Date date;
    vector<Income> incomes;
    Income income1(1,date,"loan",200.10);
    Income income2(2,date,"salary",465.49);
    incomes.push_back(income1);
    incomes.push_back(income2);
    cout << incomes[0].getDateByString() << endl;
    cout << incomes[0].getItem() << endl;
    cout << incomes[1].getIncomeId() << endl;
    cout << incomes[1].getAmount() << endl;

    return 0;
}
