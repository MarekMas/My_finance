#include "UserMenager.h"

void UserMenager::registration()
{
    User user = giveDataOfTheNewUser();

    users.push_back(user);
    xmlUsers.addUser(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserMenager::giveDataOfTheNewUser()
{
    User user;

    user.setUserId(getNewUserId());

    cout << "Podaj imie: ";
    user.setName(SupportingMethods::loadLine());
    cout << "Podaj nazwisko: ";
    user.setSurname(SupportingMethods::loadLine());

    do
    {
        cout << "Podaj login: ";
        user.setLogin(SupportingMethods::loadLine());
    } while (checkIfLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(SupportingMethods::loadLine());

    return user;
}

int UserMenager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserMenager::checkIfLoginExist(string login)
{

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserMenager::signIn()
{
     string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = SupportingMethods::loadLine();

    vector<User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = SupportingMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    signedInUserId = itr -> getUserId();

                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserMenager::changePassword()
{
    if(signedInUserId == 0)
    {
       cout << "Zaden uzytkownik nie jest zalogowany" << endl;
       return;
    }

    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportingMethods::loadLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserId() == signedInUserId)
        {
            users[i].setPassword(newPassword);
            xmlUsers.overwriteUserData(users[i]);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}

void UserMenager::signOut()
{
    signedInUserId = 0;
}

int UserMenager::getIdOfSignedInUser()
{
    return signedInUserId;
}



