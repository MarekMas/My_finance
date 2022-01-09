#include "TransactionMenager.h"

void TransactionMenager::addIncome()
{
    system("cls");
    cout << "--DODAWANIE PRZYCHODU--" << endl << endl;

    Income income;

    income.setIncomeId(++maxIncomeId);
    income.setDate(selectDate());
    income.setItem(selectIncomeItem());
    income.setAmount(setValueOfAmount());

    incomes.push_back(income);
    sort(incomes.begin(), incomes.end());
    xmlIncomes.addIncome(income);
    cout << "Dodano nowy przychod" << endl;
    system("pause");

}

void TransactionMenager::addExpense()
{
    system("cls");
    cout << "--DODAWANIE WYDATKU--" << endl << endl;

    Expense expense;

    expense.setExpenseId(++maxExpenseId);
    expense.setDate(selectDate());
    expense.setItem(selectExpenseItem());
    expense.setAmount(setValueOfAmount());

    expenses.push_back(expense);
    sort(incomes.begin(), incomes.end());
    xmlExpenses.addExpense(expense);
    cout << "Dodano nowy wydatek" << endl;
    system("pause");
}

Date TransactionMenager::selectDate()
{
    char choice;
    string strDate;
    Date date;
    cout << "Podaj date transakcji" << endl << endl;
    cout << "1. Dzisiejsza data" << endl;
    cout << "2. Wybierz inna date" << endl;

    cout << "Twoj wybor: ";
    choice = SupportingMethods::loadCharacter();

    while(true)
    {
        switch(choice)
        {
            case '1':
                date.setCurrentDate();
                return date;
            break;
            case '2':
                cout << "Wpisz date w formacie rrrr-mm-dd: ";
                strDate = SupportingMethods::loadLine();
                if(date.setDateByString(strDate))
                {
                    cout << endl;
                    return date;
                }

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

    cout << "Podaj rodzaj przychodu" << endl << endl;;
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

string TransactionMenager::selectExpenseItem()
{
    char choice;
    string strItem;

    cout << "Podaj rodzaj wydatku" << endl << endl;
    cout << "1. Art.Gosp.Domowego" << endl;
    cout << "2. Zywnosc" << endl;
    cout << "3. Rozrywka" << endl;
    cout << "4. Paliwo i Transport" << endl;
    cout << "5. Raty" << endl;
    cout << "6. Edukacja" << endl;
    cout << "7. Wpisz wlasne" << endl;

    cout << "Twoj wybor: ";
    choice = SupportingMethods::loadCharacter();

    while(true)
    {
        switch(choice)
        {
            case '1':
                return "Art.Gosp.Domowego";
            break;
            case '2':
                return "Zywnosc";
            break;
            case '3':
                return "Rozrywka";
            break;
            case '4':
                return "Paliwo i Transport";
            break;
            case '5':
                return "Raty";
            break;
            case '6':
                return "Edukacja";
            break;
            case '7':
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
    cout <<endl << "Podaj kwote transakcji: ";
    float amount = SupportingMethods::loadFloatValue();
    return amount;
}

void TransactionMenager::currentMontBalance()
{
    system("cls");
    cout << "--BILANS BIEZACEGO MIESIACA--" << endl;
    Date minDate;
    minDate.setCurrentDate();
    minDate.setDay(1);
    Date maxDate;
    maxDate.setCurrentDate();
    maxDate.setLastDayOfMonth();

    showBalanceByRange(maxDate,minDate);
}

void TransactionMenager::lastMonthBalance()
{
    system("cls");
    cout << "--BILANS OSTATNIEGO MIESIACA--" << endl;
    Date minDate;
    minDate.setCurrentDate();
    minDate.setMonth(minDate.getMonth()-1);
    minDate.setDay(1);

    Date maxDate;
    maxDate.setCurrentDate();
    maxDate.setMonth(maxDate.getMonth()-1);
    maxDate.setLastDayOfMonth();

    showBalanceByRange(maxDate,minDate);
}

void TransactionMenager::selectScopeOfBalance()
{
    system("cls");
    cout << "--BILANS DLA WSKAZANEGO ZAKRESU--" << endl;
    Date minDate;
    cout << "Podaj poczatek zakresu (yyyy-mm-dd): ";
    while(minDate.setDateByString(SupportingMethods::loadLine()) == false)
    {
        cout << "Data niepoprawna"<< endl;
        cout << "Podaj poczatek zakresu ponownie (yyyy-mm-dd): ";
    }

    Date maxDate;

    cout << "Podaj koniec zakresu (yyyy-mm-dd): ";
    while(maxDate.setDateByString(SupportingMethods::loadLine()) == false)
    {
        cout << "Data niepoprawna"<< endl;
        cout << "Podaj koniec zakresu ponownie (yyyy-mm-dd): ";
    }


    showBalanceByRange(maxDate,minDate);
}

void TransactionMenager::showBalanceByRange(Date maxDate, Date minDate)
{
    cout << "MIN " << minDate.getDateAsString() << " MAX " << maxDate.getDateAsString() << endl << endl;
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;
    cout << "-Przychody-" << endl;
    Date transactionDate;
    for(int i = 0; i < incomes.size(); i ++)
    {
         transactionDate = incomes[i].getDate();
        if((minDate < transactionDate || minDate == transactionDate) && (maxDate > transactionDate || maxDate == transactionDate))
        {
            cout << "Data: " << incomes[i].getDateByString() << " Rodzaj: " << incomes[i].getItem() << " Wartosc: " << incomes[i].getAmount() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }

    cout << "-Wydatki-" << endl;

    for(int i = 0; i < expenses.size(); i ++)
    {
        transactionDate = expenses[i].getDate();
        if((minDate < transactionDate || minDate == transactionDate) && (maxDate > transactionDate || maxDate == transactionDate))
        {
            cout << "Data: " << expenses[i].getDateByString() << " Rodzaj: " << expenses[i].getItem() << " Wartosc: " << expenses[i].getAmount() << endl;
            sumOfExpenses += expenses[i].getAmount();
        }
    }
    cout << "-Suma przychodów-" << endl;
    cout << sumOfIncomes << endl;
    cout << "-Suma wydatkow-" << endl;
    cout << sumOfExpenses << endl;
    cout << "Bilans (przychody - wydatki): " << endl;
    cout << sumOfIncomes - sumOfExpenses << endl;
    system("pause");
}

