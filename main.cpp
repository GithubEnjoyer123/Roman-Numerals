/* Program name: main.cpp
* Author: Justin Phillips
* Date last updated: 3/25/2024
* Purpose: Convert roman numerals to decimal
*/
#include <iostream>
#include <string>
#include "roman.h"
#include <cstring>

using namespace std;

int main(){
    //Our values to store info
    string text, rNumeral;
    int conversion;
    //Constructor
    romanType convert(text);

    //We loop and later ask to exit program in our menu, that way we can keep converting
    while(true){
        //We set our roman number to uppercase to avoid inconsistencies, then set our rNumeral value to it
        convert.setNumber(convert.upper());
        rNumeral = convert.getNumeral();

        //We then reprint the numerals back to user for confirmation
        cout << "\nYour roman numerals are: " << rNumeral << "\n";

        //We set our conversion int to our rNumeral string toInt conversion number (this function holds the logic that actually converts)
        conversion = convert.toInt(rNumeral);

        //We print out our number and then enter our menu to see if we want to continue or not
        cout << "Your converted number is: " << conversion << "\n";
        menu();
    }     
}