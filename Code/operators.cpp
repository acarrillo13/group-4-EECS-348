#include "operators.h"
#include <cmath>
using namespace std;

double add(double n1, double n2){
    double sum = n1 + n2;
    return sum;
}

double subtract(double n1, double n2){
    double subed = n1 - n2;
    return subed;
}

double multiply(double n1, double n2){
    double mult = n1 * n2;
    return mult;
}

double divide(double n1, double n2){
    double div = n1 / n2;
    return div;
}

int modulate(int n1, int n2){
    int modu = n1 % n2;
    return modu;
}

double exponent(double n1, double  n2){
    double exp = pow(n1,n2);
    return exp;
}
