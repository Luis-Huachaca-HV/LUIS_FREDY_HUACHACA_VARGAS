#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ expo(ZZ a,ZZ b){
    ZZ res;
    ZZ n;
    n=0;
    res =1;
    while (n != b){
        res *= a;
        n++;
    }
    return res;
}

ZZ Modulo(ZZ Div, ZZ d){
    ZZ q = Div/d;
    ZZ res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
int Modulo(int Div, int d){
    int q = Div/d;
    int res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}


ZZ mcd(ZZ a, ZZ b){
    if(a>b){swap(a,b);}
    ZZ r = Modulo(a,b);
    while(r != 0){
        r = Modulo(a,b);
        a = b;
        b = r;
        if(r == ZZ(0)){return a;}
    }
    return b;
}
ZZ EuclidesExtendido(ZZ a, ZZ b){
    if(a>b){swap(a,b);}
    ZZ s = ZZ(0), s1 = ZZ(1), s2 = ZZ(0);
    while(b > 0){
        ZZ q = a/b;
        ZZ r = a - (q*b);
        a = b;
        b=r;
        s = s1 - (q*s2);
        s1 = s2;
        s2 = s;
    }
    s = s1;
    //cout << s;
    return s;
}
ZZ InversaMultiplicativa(ZZ a, ZZ b){
    if(mcd(a,b) == ZZ(1)){
        ZZ x = EuclidesExtendido(a,b);
        ZZ IM = Modulo(x,b);
        return IM;
    }
    else{cout << "no tiene inversa multiplicativa"<< endl;}
}

ZZ ExpoMod2(ZZ base,ZZ exp, ZZ mod){
    ZZ result = ZZ(1);
    ZZ dos;
    dos = 2;
    for( ; exp > 0; exp /= 2){
        if(Modulo( exp , dos ) == ZZ(1)){result = Modulo(result*base,mod);}
        base = Modulo(base*base,mod);
    }
    return result;
}
