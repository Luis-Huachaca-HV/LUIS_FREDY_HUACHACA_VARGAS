#include <iostream>
#include <sstream>
#include <math.h>
#include <NTL/ZZ.H>
#include <NTL/RR.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <string>

using namespace NTL;
using namespace std;

ZZ Min(ZZ a, ZZ b){
    ZZ m;
    m = a;
    if(a > b) {
        m = b;
    }
    return m;
}
ZZ poww(ZZ a, ZZ b){
    ZZ res;
    res = ZZ(1);
    for(ZZ i = ZZ(0); i < b; i++){
        res = res * a;
    }
    return res;
}

ZZ LSBMCD(ZZ u, ZZ v){
    ZZ a, b, t, aux, s;
    a = abs(u);
    b = abs(v); //rem debe ser a>b
    while(b != ZZ(0)){
        s = ZZ(0);
        while(b*poww(ZZ(2),s) <= a){
            s = s + 1;
            //cout << a << " " << b << " " << t << endl;
        }
        cout << a << " " << b << " " << t << endl;
        s = s - 1;
        t = Min(a - b*poww(ZZ(2),s), b*poww(ZZ(2),s+1)-a);
        a = b;
        b = t;
        if(a < b){
            aux = a;
            a = b;
            b = aux;
        }
    }
    return a;
}

int main() {


    cout << LSBMCD(ZZ(55367), ZZ(28731)) << endl;


    return 0;
}