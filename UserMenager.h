#ifndef USERMENAGER_H
#define USERMENAGER_H

#include "XmlUsers.h"


class UserMenager
{
    int signedInUserId;
    vector <User> users;
    XmlUsers xmlUsers;

    User giveDataOfTheNewUser();
    int getNewUserId();
    bool checkIfLoginExist(string login);
public:
    UserMenager(string usersFileName)
    : xmlUsers(usersFileName)
    {
        signedInUserId = 0;
        users = xmlUsers.loadUsersFromFile();
    }
    int getIdOfSignedInUser();

    void registration();
    void signIn();
    void changePassword();
    void signOut();
};

#endif // USERMENAGER_H
