#include "SupportingMethods.h"

string SupportingMethods::convrtIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportingMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

float SupportingMethods::convertStringToFloat(string number)
{
    float numberFloat;
    istringstream ss(number);
    ss >> numberFloat;

    return numberFloat;

}

string SupportingMethods::convertFloatToString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportingMethods::loadLine()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}


string SupportingMethods::changeTheFirstLetterToUppercaseAndTheRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupportingMethods::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

char SupportingMethods::loadCharacter()
{
    string outcome = "";
    char character  = {0};

    while (true)
    {
        getline(cin, outcome);

        if (outcome.length() == 1)
        {
            character = outcome[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int SupportingMethods::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

float SupportingMethods::loadFloatValue()
{
    string outcome = "";
    float number = 0;

    while (true)
    {
        getline(cin, outcome);
        for(int i = 0; i < outcome.length(); i++)
        {
            if(outcome[i] == ',')
                outcome[i] = '.';
        }
        stringstream myStream(outcome);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
