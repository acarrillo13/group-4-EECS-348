#include "operators.h"
#include "extra348.h"
#include <cmath>
using namespace std;

string add(const string& n1, const string& n2){
    double dn1 = extractNumeric(n1);
    double dn2 = extractNumeric(n2);
    double sum = dn1 + dn2;
    return to_string(sum);
}

string subtract(const string& n1, const string& n2){
    double dn1 = extractNumeric(n1);
    double dn2 = extractNumeric(n2);
    double subed = dn1 - dn2;
    return to_string(subed);
}

string multiply(const string& n1, const string& n2){
    double dn1 = extractNumeric(n1);
    double dn2 = extractNumeric(n2);
    double mult = dn1 * dn2;
    return to_string(mult);
}

string divide(const string& n1, const string& n2){
    double dn1 = extractNumeric(n1);
    double dn2 = extractNumeric(n2);
    double div = dn1 / dn2;
    return to_string(div);
}

string modulate(const string& n1, const string& n2){
    double dn1 = extractNumeric(n1);
    double dn2 = extractNumeric(n2);
    int in1 = static_cast<int>(dn1);
    int in2 = static_cast<int>(dn2);
    int modu = in1%in2;
    return to_string(modu);
}

string exponent(const string& n1, const string& n2){
    double dn1 = extractNumeric(n1);
    double dn2 = extractNumeric(n2);
    double exp = pow(dn1,dn2);
    return to_string(exp);
}

string positive(const string& n1){
    double dn1 = extractNumeric(n1);
    double adn1 = abs(dn1);
    return to_string(adn1);
}

string negative(const string& n1){
    double dn1 = extractNumeric(n1);
    double ndn1 = abs(dn1) * -1;
    return to_string(ndn1);
}
