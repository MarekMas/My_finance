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
    float static convertStringToFloat(string number);
    string static convertFloatToString(float number);
    string static loadLine();
    string static changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text);
    string static pobierzLiczbe(string tekst, int pozycjaZnaku);
    char static loadCharacter();
    int static wczytajLiczbeCalkowita();

};
#endif // SUPPORTINGMETHODS_h
