#include "operators.h"
#include "extra348.h"
#include <cmath>
using namespace std;
//E values mean that an error has occured or an error was given as input, returns error in both cases
//All take in string as input, turn string into doubles (or integers in the case of moduluous) and output strings of the answer
string add(const string& n1, const string& n2){
    /*For adding n1 and n2*/
    //If an error was given
    if(n1 == "e" || n2 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{
        double dn1 = extractNumeric(n1);
        double dn2 = extractNumeric(n2);
        double sum = dn1 + dn2;
        return to_string(sum);
    }
}

string subtract(const string& n1, const string& n2){
    /*For subtracting n2 from n1*/
    //If an error was given
    if(n1 == "e" || n2 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{
        double dn1 = extractNumeric(n1);
        double dn2 = extractNumeric(n2);
        double subed = dn1 - dn2;
        return to_string(subed);
    }
}

string multiply(const string& n1, const string& n2){
    /*For multiplying n1 and n2*/
    //If an error was given
    if(n1 == "e" || n2 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{    
        double dn1 = extractNumeric(n1);
        double dn2 = extractNumeric(n2);
        double mult = dn1 * dn2;
        return to_string(mult);
    }
}

string divide(const string& n1, const string& n2){
    /*For dividing n2 from n1*/
    //If an error was given
    if(n1 == "e" || n2 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{    
        double dn1 = extractNumeric(n1);
        double dn2 = extractNumeric(n2);
        //Dividing by 0
        if(dn2 == 0){
            string err = "e";
            return err;
        //Dividing by non-0
        }else{
            double div = dn1 / dn2;
            return to_string(div);
        }
    }  
}

string modulate(const string& n1, const string& n2){
    /*For modulating n1 by n2*/
    //If an error was given
    if(n1 == "e" || n2 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{
        double dn1 = extractNumeric(n1);
        double dn2 = extractNumeric(n2);
        int in1 = static_cast<int>(dn1);
        int in2 = static_cast<int>(dn2);
        //Modulating by 0
        if(in2 == 0){
            string err = "e";
            return err;
        //Returns error if non-integer number was given
        }else if(dn1 != in1 || dn2 != in2){
            string err = "e";
            return err;
        //Proper moduluous
        }else{
            int modu = in1 / in2;
            return to_string(modu);
        }
    }
}

string exponent(const string& n1, const string& n2){
    /*For raising n1 to the power of n2*/
    //Also used for radicals
    //If an error was given
    if(n1 == "e" || n2 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{
        double dn1 = extractNumeric(n1);
        double dn2 = extractNumeric(n2);
        double exp = pow(dn1,dn2);
        return to_string(exp);
    }
}

string positive(const string& n1){
    /*For assigning a positive value to a number*/
    //If an error was given
    if(n1 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{
        double dn1 = extractNumeric(n1);
        double adn1 = abs(dn1);
        return to_string(adn1);
    }
}

string negative(const string& n1){
    /*For assigning a negative value to a number*/
    //If an error was given
    if(n1 == "e"){
        string err = "e";
        return err;
    //If no error was given
    }else{    
        double dn1 = extractNumeric(n1);
        double ndn1 = abs(dn1) * -1;
        return to_string(ndn1);
    }
}
