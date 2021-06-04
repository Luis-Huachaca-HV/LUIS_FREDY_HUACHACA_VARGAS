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




ZZ poww(ZZ a, ZZ b){
    ZZ res;
    res = ZZ(1);
    for(ZZ i = ZZ(0); i < b; i++){
        res = res * a;
    }
    return res;
}
ZZ Modulo(ZZ Div, ZZ d){
    ZZ q = Div/d;
    ZZ res = Div - (d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
ZZ mcdBinario(ZZ u, ZZ v){
    ZZ t,g,a,b;
    g= 1;
    a = abs(u);
    b = abs(v);
    while((Modulo(a,ZZ(2)) == ZZ(0)) && (Modulo(b,ZZ(2)) == ZZ(0))){
        cout << a << " " << b << " " << g << endl;
        a = a/2;
        b = b/2;
        g = 2*g;

    }
    while(a!=0){
        cout << a << " " << b << " " << g << endl;
        if(Modulo(a,ZZ(2)) == ZZ(0))
            a = a/2;
        else if(Modulo(b,ZZ(2)) == ZZ(0))
            b = b/2;
        else{
            t = abs(a-b) / 2;
            if ( a >= b)
                a = t;
            else
                b = t;
        }
    }
    return g * b;
}


int main()
{
    ZZ dos = ZZ(2);
    ZZ bit8 = poww(dos,ZZ(8)) - 1;
    ZZ bit16 = poww(dos,ZZ(16)) -1;
    ZZ bit32 = poww(dos,ZZ(32)) -1;
    ZZ bit256 = poww(dos,ZZ(256)) -1;
    ZZ bit1024 = poww(dos,ZZ(1024)) -1;
    ZZ bit2048 = poww(dos,ZZ(2048)) -1;

    cout << mcdBinario(bit8, ZZ(8)) << endl;
    cout << mcdBinario(bit16, ZZ(16)) << endl;
    cout << mcdBinario(bit32, ZZ(32)) << endl;
    cout << mcdBinario(bit256, ZZ(256)) << endl;
    cout << mcdBinario(bit1024, ZZ(1024)) << endl;
    cout << mcdBinario(bit2048, ZZ(2048)) << endl;
    return 0;
}
