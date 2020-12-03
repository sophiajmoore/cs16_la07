// Converter.cpp
// By: Sophia Moore
// Created on: 11/20/20

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string convertFromDec(unsigned int decnum, unsigned int base);
// Pre-condition: takes an unsigned int and the chosen base
// Post-condition: returns a string of the converted number
bool ValidInput(string the_string);
// Pre-condition: takes in a string
// Post-condition: returns false if it detects a non-int
string DecToBin(int dec_number);
// Pre-condition: takes in an int
// Post-condition: returns the converted to binary number as a string
string DecToOct(int dec_number);
// Pre-condition: takes in an int
// Post-condition: returns the converted to octal number as a string
string DecToHex(int dec_number);
// Pre-condition: takes in an int
// Post-condition: returns the converted to hex number as a string

int main()
{
    string decnum;
    cout << "Enter positive decimal number (anything else quits): ";
    cin >> decnum;

    while ( (ValidInput(decnum) != 0) && stoi(decnum) > 0) // checking that it's valid and if its >0
    {
        cout << decnum << " in binary is: " << convertFromDec(stoi(decnum), 2) << endl;
        cout << decnum << " in octal is: " << convertFromDec(stoi(decnum), 8) << endl;
        cout << decnum << " in hex is: " << convertFromDec(stoi(decnum), 16) << endl;

        cout << endl << "Enter positive decimal number (anything else quits): ";
        cin >> decnum;
    }

    return 0;
}

bool ValidInput(string the_string)
{
    for (int i = 0; i < the_string.length(); i++)
    {
        if (isdigit(the_string[i]) == 0)
        {
            return 0; // return false, the string is bad
        }
    }
    return true; // if it passes thru the loop, it must be ok
}

string convertFromDec(unsigned int decnum, unsigned int base)
{
    // just calling functions and returning answers
    string answer;
    if (base == 2)
    {
        answer =  DecToBin(decnum);
    }

    else if (base == 8)
    {
        answer = DecToOct(decnum);
    }
    else if (base == 16)
    {
        answer =  DecToHex(decnum);
    }
    return answer;
}

string DecToBin(int dec_number)
{
    string number;
    while (dec_number > 0)
    {
        number += to_string(dec_number % 2);
        dec_number = dec_number/2;
    }

    string better_number; // better number is the number in reverse
    for (int i = number.length()-1; i >= 0; i--)
    {
        better_number += number[i];
    }

    return better_number;
}

string DecToOct(int dec_number)
{
    string number;
    while (dec_number > 0)
    {
        number += to_string(dec_number % 8);
        dec_number = dec_number/8;
    }

    string better_number;
    for (int i = number.length()-1; i >= 0; i--)
    {
        better_number += number[i];
    }

    return better_number;
}

string DecToHex(int dec_number)
{
    string number;
    int numbers[6] = {10,11,12,13,14,15};
    char letters[6] = {'A','B','C','D','E','F'};

    while (dec_number > 0)
    {
        if (dec_number % 16 >= 10)
        {
            for (int i = 0; i < 6; i++)
            {
                if (dec_number % 16 == numbers[i])
                {
                    number +=  letters[i]; // letter is added to string if corresponding number is found
                }   
            }
        }

        else
        {
            number += to_string(dec_number % 16);
        }
        dec_number = dec_number/16;
    }
    
    string better_number;
    for (int i = number.length()-1; i >= 0; i--)
    {
        better_number += number[i];
    }

    return better_number;
}


