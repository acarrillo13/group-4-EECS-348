#include "extra348.h"
#include <iomanip>
#include <string>
using namespace std;
/*
Turns a given string of a number into a double number
*/
double extractNumeric(const string& str)   {    //function to parse string for a double
    int length = str.length();
    bool hasDecimal = false;  //if it has decimal point
    bool hasDigits = false;   //if there are digits in the string
    int signCount = 0;        //tracks the sign
    string numberStr = "";    //holds string

    for (int i = 0; i < length; ++i) {
        char c = str[i];
        if (c == '+' || c == '-') {
            if (i > 0 || signCount > 0) {   //checks if sign is at front
                return -999999.99;
            }
            signCount++;
            numberStr += c;
        } else if (c == '.') {
            if (hasDecimal) {   //checks to see if there are more than one decimal
                return -999999.99;
            }
            hasDecimal = true;
            numberStr += c;
        } else if (isdigit(c)) {
            hasDigits = true;
            numberStr += c;
        } else {//invalid character
            return -999999.99;
        }
    }

    //check for digits
    if (!hasDigits) {
        return -999999.99;
    }

    //convert string to double
    try {
        return stod(numberStr);
    } catch (...) {
        return -999999.99;
    }
}
