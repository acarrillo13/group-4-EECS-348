#include <iostream>
using namespace std;

int add(int n1, int n2){
    int sum = n1 + n2;
    return sum;
}

int subtract(int n1, int n2){
    int subed = n1 - n2;
    return subed;
}

int multiply(int n1, int n2){
    int mult = n1 * n2;
    return mult;
}

int divide(int n1, int n2){
    int div = n1 / n2;
    return div;
}

int modulate(int n1, int n2){
    int mod = n1 % n2;
    return mod;
}
/*
int exponent(int n1, int  n2){
    int ex;
    for(i=0,i<n2,i++){
        ex = n1 * n1;
    }
    return ex;
}
*/

int main(){
    int t = modulate(4,3);
    cout << t;
    return 0;
}