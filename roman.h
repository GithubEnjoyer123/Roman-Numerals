#ifndef ROMANTYPE_H
#define ROMANTYPE_H
#include <string>
#include <iostream>

using namespace std;

class romanType{
    public:
        romanType(string text);
        string getNumeral() const;
        string upper() const;
        int toInt(string) const;

        void setNumber(string);
    private:
        string text;
};

void menu();
#endif