#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class SupportingMethods
{
public:
    string static convrtIntToString(int number);
    int static convertStringToInt(string number);
    string static wczytajLinie();
    string static zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    string static pobierzLiczbe(string tekst, int pozycjaZnaku);
    char static wczytajZnak();
    int static wczytajLiczbeCalkowita();

};
#endif // SUPPORTINGMETHODS_h
