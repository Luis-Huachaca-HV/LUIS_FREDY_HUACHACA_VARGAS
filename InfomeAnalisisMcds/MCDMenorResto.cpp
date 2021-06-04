#include <iostream>
#include <math.h>
#include <NTL/ZZ.H>
#include <NTL/RR.h>

using namespace NTL;
using namespace std;


ZZ srem(ZZ a,ZZ b){
    RR aa = conv<RR> (a);
    RR bb = conv<RR> (b);
    RR val = floor(((RR)aa/(RR)bb) + 0.5);
    //cout << vconval<< endl;
    ZZ v = conv<ZZ>(val);
    ZZ resa = conv<ZZ>(aa);
    ZZ resb = conv<ZZ>(bb);
    return resa - (resb*v);
}

ZZ poww(ZZ a, ZZ b){
    ZZ res;
    res = ZZ(1);
    for(ZZ i = ZZ(0); i < b; i++){
        res = res * a;
    }
    return res;
}

ZZ mcdMenorResto(ZZ a, ZZ b){
    ZZ c,d,r;
    if(a == ZZ(0)){
        c =b;
    }
    else{
        c= a;
        d=b;
        //cout << b << " = " << a << "." << c << " - " << r << endl;
        while (d != ZZ(0) ){
            r = srem(c,d);
            c = d;
            d =r;
            //cout << d << " = " << c << "." << "val" << " - " << r << endl;//estas impresiones estan mal, pero sale
        }
    }
    return abs(c);
}

int main()
{
    //cout << (86/1/5) << endl;
    ZZ dos = ZZ(2);
    ZZ bit8 = poww(dos,ZZ(8)) - 1;
    ZZ bit16 = poww(dos,ZZ(16)) -1;
    ZZ bit32 = poww(dos,ZZ(32)) -1;
    ZZ bit256 = poww(dos,ZZ(256)) -1;
    ZZ bit1024 = poww(dos,ZZ(1024)) -1;
    ZZ bit2048 = poww(dos,ZZ(2048)) -1;

    cout << mcdMenorResto(bit8, ZZ(8)) << endl;
    cout << mcdMenorResto(bit16, ZZ(16)) << endl;
    cout << mcdMenorResto(bit32, ZZ(32)) << endl;
    cout << mcdMenorResto(bit256, ZZ(256)) << endl;
    cout << mcdMenorResto(bit1024, ZZ(1024)) << endl;
    cout << mcdMenorResto(bit2048, ZZ(2048)) << endl;
    return 0;
}
