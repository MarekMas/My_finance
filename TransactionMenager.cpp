#include "TransactionMenager.h"

void TransactionMenager::addIncome()
{
    system("cls");
    cout << "DODAWANIE PRZYCHODU" << endl;

    Income income;

    income.setIncomeId(++maxIncomeId);
    income.setDate(selectDate());
    income.setItem(selectIncomeItem());
    income.setAmount(setValueOfAmount());

    incomes.push_back(income);
    xmlIncomes.addIncome(income);
    cout << "Dodano nowy przychod" << endl;
    system("pause");

}

Date TransactionMenager::selectDate()
{
    char choice;
    string strDate;
    Date date;
    cout << "DATA TRANSAKCJI" << endl;
    cout << "1. Dzisiejsza data" << endl;
    cout << "2. Wybierz inna date" << endl;

    cout << "Twoj wybor: ";
    choice = SupportingMethods::loadCharacter();

    while(true)
    {
        switch(choice)
        {
            case '1':
                return date;
            break;
            case '2':
                cout << "Wpisz date w formacie rrrr-mm-dd: ";
                strDate = SupportingMethods::loadLine();
                if(date.setDateByString(strDate))
                    return date;
                else
                    cout << "Podana data jest niepoprawna" << endl;

            break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
        }
    }
}

string TransactionMenager::selectIncomeItem()
{
    char choice;
    string strItem;

    cout << "RODZAJ PRZYCHODU" << endl;
    cout << "1. Pensja" << endl;
    cout << "2. Sprzedaz" << endl;
    cout << "3. Zyski kapitalowe" << endl;
    cout << "4. Darowizna" << endl;
    cout << "5. Wpisz wlasne" << endl;

    cout << "Twoj wybor: ";
    choice = SupportingMethods::loadCharacter();

    while(true)
    {
        switch(choice)
        {
            case '1':
                return "Pensja";
            break;
            case '2':
                return "Sprzedaz";
            break;
            case '3':
                return "Zyski kapitalowe";
            break;
            case '4':
                return "Darowizna";
            break;
            case '5':
                cout << "Podaj rodzaj przychodu: ";
                strItem = SupportingMethods::loadLine();
                return strItem;
            break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
        }
    }

}

float TransactionMenager::setValueOfAmount()
{
    cout << "Podaj kwote transakcji: ";
    float amount = SupportingMethods::loadFloatValue();
    return amount;
}




