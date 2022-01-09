#include "User.h"

int User::getUserId()
{
    return this->userId;
}
string User::getLogin()
{
    return this->login;
}
string User::getPassword()
{
    return this->password;
}
string User::getName()
{
    return this->name;
}
string User::getSurname()
{
    return this->surname;
}
void User::setUserId(int userId)
{
    if(userId > 0)
        this->userId = userId;
}
void User::setLogin(string login)
{
    this->login = login;
}
void User::setPassword(string password)
{
    this->password = password;
}
void User::setName(string name)
{
    this->name = name;
}
void User::setSurname(string surname)
{
    this->surname = surname;
}
