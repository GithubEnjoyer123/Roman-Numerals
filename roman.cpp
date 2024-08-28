#include <string>
#include <iostream>
#include <cstring>
#include "roman.h"

using namespace std;

romanType::romanType(string t){
    text = t;
}

string romanType::getNumeral() const{
    return text;
}

//This function is our logic to convert the numerals to int
int romanType::toInt(string s) const{
    //We set a dynamic array since we don't know how many numerals the user input
    int* arr = new int;
    
    //We loop through the array, setting each roman numeral equivalent value to its decimal value
    for(int i = 0; i < s.size(); i++){
        switch(s[i]){
            case 'M':
                arr[i] = 1000; break;
            case 'D':
                arr[i] = 500; break;
            case 'C':
                arr[i] = 100; break;
            case 'L':
                arr[i] = 50; break;
            case 'X':
                arr[i] = 10; break;
            case 'V':
                arr[i] = 5; break;
            case 'I':
                arr[i] = 1; break;
        }
    }
    
    //We initialize two number values for comparison, and a total for our total output
    int n1, n2, total;

    for(int i = 0; i < s.size(); i++){
        //We set our first number to the array value that we're on
        n1 = arr[i];

        //Here we see if there is anymore numbers in the array so we know if there will be anything else to potentially subtract
        if(i + 1 < s.size()){
            //We set our 2nd number to the array number in front of us
            n2 = arr[i + 1];

            //If our first number is greater than the 2nd, we add the first number. Else we subtract is from our 2nd number and skip an iteration.
            if(n1 >= n2){
                total += n1;
            }else{
                total = total + n2 - n1;
                i++;
            }
        }else{
            total += n1;
        }
    }

    //We free up memory before leaving the scope of our function, returning the total decimal conversion
    delete[] arr;
    arr = nullptr;
    return total;
}

void romanType::setNumber(string t){
    text = t;
}

//This function handles the logic of sending our numerals to uppercase
string romanType::upper() const{
    int length;
    bool b = false;

    //We have a dynamic array here since we don't know the size of our string set by the user
    char* arr = new char;

    //We have a goto here in case the user enters a non roman numeral, to retry our loop
    rCheck:
    while(b == false){
        cout << "\nPlease enter a roman numeral: ";
        cin >> arr;
        //We save our length size here so we know how many times to iterate through our loop
        length = strlen(arr);

        //This loop goes through each value in our array and sets it to uppercase. If a non roman numeral is entered we reset our loop and ask the user to reinput.
        for(int i = 0; i < length; i++){
            switch(arr[i]){
                case 'm':
                case 'M':
                case 'd':
                case 'D':
                case 'c':
                case 'C':
                case 'l':
                case 'L':
                case 'x':
                case 'X':
                case 'v':
                case 'V':
                case 'i':
                case 'I':
                    arr[i] = toupper(arr[i]);
                    b = true;
                    break;
                default:
                    cout << "\nNon roman numeral entered. Roman numerals can only have the Values: M, D, C, L, X, V, I\n";
                    b = false;
                    goto rCheck;
            }
        } 
    }

    //We save our output to the array, then delete it to free up memory.
    string out = arr;
    delete[] arr;
    arr = nullptr;
    return out;
}

//This is our menu to see if the user wants to continue or not. If y we go through the loop in main again, if n we exit the program, if something else we ask the user to reinput a value.
void menu(){
    char choice;
    start:
    cout << "Would you like to continue converting? (Y/N): ";
    cin >> choice;
    switch(choice){
        case 'y':
        case 'Y':
            break;
        case 'n':
        case 'N':
            exit(0);
        default:
            cout << "\nInvalid choice. Please enter Y for yes or N for no.\n";
            cin.ignore(256, '\n');
            cin.clear();
            goto start;
    }
}