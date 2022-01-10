#include <iostream>
#include "MyFinance.h"

using namespace std;

int main()
{
    MyFinance myFinanse("users.xml","incomes.xml","expenses.xml");

    while (true)
    {
        if(!myFinanse.whetherTheUserIsSignedIn())
        {
            switch (myFinanse.selectOptionsFromTheMainMenu())
            {
                case '1':
                    myFinanse.registeration();
                    break;
                case '2':
                    myFinanse.signIn();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
            }
        }
        else
        {
            switch (myFinanse.selectOptionsFromTheUserMenu())
            {
                case '1':
                    myFinanse.addIncome();
                    break;
                case '2':
                    myFinanse.addExpence();
                    break;
                case '3':
                    myFinanse.currentMontBalance();
                    break;
                case '4':
                    myFinanse.lastMonthBalance();
                    break;
                case '5':
                    myFinanse.selectScopeOfBalance();
                    break;
                case '6':
                    myFinanse.changePassword();
                    break;
                case '7':
                    myFinanse.signOut();
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
            }
        }
    }
    return 0;
}

