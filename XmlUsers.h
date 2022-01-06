#ifndef XMLUSERS_H
#define XMLUSERS_H

#include "XmlFile.h"


class XmlUsers : public XmlFile
{
    public:

        XmlUsers(string fileName)
        : XmlFile(fileName){}
        void addUser(User user);
        vector<User> loadUsersFromFile();
        void overwriteUserData(User user);
};

#endif // XMLUSERS_H
