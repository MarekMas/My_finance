#include "MyFinance.h"

void MyFinance::signIn()
{
    userMenager.signIn();
    if(userMenager.getIdOfSignedInUser() > 0)
        transactionMenager = new TransactionMenager(userMenager.getIdOfSignedInUser(),INCOMES_FILE_NAME, EXPENSES_FILE_NAME);
}

void MyFinance::registeration()
{
    userMenager.registration();
}

void MyFinance::changePassword()
{
    userMenager.changePassword();
}

void MyFinance::signOut()
{
    userMenager.signOut();
}

void MyFinance::addIncome()
{
    transactionMenager->addIncome();
}

void MyFinance::addExpence()
{
    transactionMenager->addExpense();
}

void MyFinance::currentMontBalance()
{

}

void MyFinance::lastMonthBalance()
{

}

void MyFinance::selectScopeOfBalance()
{

}


char MyFinance::selectOptionsFromTheMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportingMethods::loadCharacter();

    return choice;
}

char MyFinance::selectOptionsFromTheUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportingMethods::loadCharacter();

    return choice;
}

bool MyFinance::whetherTheUserIsSignedIn()
{
    if(userMenager.getIdOfSignedInUser() == 0)
        return false;
    else
        return true;
}
