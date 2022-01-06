#include "MyFinance.h"

void MyFinance::signIn()
{
    userMenager.signIn();
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
