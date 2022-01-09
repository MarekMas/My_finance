#include "XmlUsers.h"

void XmlUsers::addUser(User user)
{
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "userId" , user.getUserId());
    xml.AddElem( "login" , user.getLogin());
    xml.AddElem( "password", user.getPassword());
    xml.AddElem( "name", user.getName());
    xml.AddElem( "surname", user.getSurname());
    xml.Save(FILE_NAME);
}

vector<User> XmlUsers::loadUsersFromFile()
{
    vector<User> users;
    User user;

    if(xml.Load(FILE_NAME))
    {

        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("userId");
            user.setUserId(SupportingMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("login");
            user.setLogin(xml.GetData());
            xml.FindElem("password");
            user.setPassword(xml.GetData());
            xml.FindElem("name");
            user.setName(xml.GetData());
            xml.FindElem("surname");
            user.setSurname(xml.GetData());

            users.push_back(user);
            xml.OutOfElem();
        }

    }
    else
    {
        xml.AddElem("Users");
    }
    return users;
}

void XmlUsers::overwriteUserData(User user)
{
    int i = 0;
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("userId");
        if(xml.GetData() == SupportingMethods::convrtIntToString(user.getUserId()))
        {
            xml.FindElem("login");
            xml.RemoveElem();
            xml.AddElem("login", user.getLogin());

            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password", user.getPassword());

            xml.FindElem("name");
            xml.RemoveElem();
            xml.AddElem("name", user.getName());

            xml.FindElem("surname");
            xml.RemoveElem();
            xml.AddElem("surname", user.getSurname());
        }
        xml.OutOfElem();
    }
    xml.Save(FILE_NAME);
}
