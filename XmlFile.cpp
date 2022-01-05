#include "XmlFile.h"

int XmlFile::findMaxId(string attribute)
{

    int temporaryMaxId = 0;
    int incomeId;

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem(SupportingMethods::changeTheFirstLetterToUppercaseAndTheRestToLowercase(attribute)))
    {
        xml.IntoElem();
        xml.FindElem(attribute + "Id");
        incomeId = SupportingMethods::convertStringToInt(xml.GetData());
        if(incomeId > temporaryMaxId)
            temporaryMaxId = incomeId;
        xml.OutOfElem();
    }

    return temporaryMaxId;
}


