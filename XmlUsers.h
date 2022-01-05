#ifndef XMLUSERS_H
#define XMLUSERS_H

#include "XmlFile.h"


class XmlUsers : public XmlFile
{
    public:

        XmlUsers();
        void addUser(Income income);
        vector<User> loadUsersFromFile();
};

#endif // XMLUSERS_H
