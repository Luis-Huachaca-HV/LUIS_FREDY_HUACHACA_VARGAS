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

ZZ euclidesClasico(ZZ a, ZZ b) {
	ZZ r1 = a;
	ZZ r2 = b;
	ZZ q = ZZ(0);
	ZZ r = ZZ(0);

	while (r2 > ZZ(0)) {
		q = r1 / r2;
		r = r1 - (q * r2);
		r1 = r2;
		r2 = r;
		cout << r1 << " " << r2 << " " << q << " " << r << endl;
	}
	return r1;
}

string numberToString(ZZ num){
    stringstream buffer;
    //stringstream buffer;
    buffer << num;
    return buffer.str();
}
ZZ stringToNumber(string str)
{
    ZZ result(NTL::INIT_VAL, str.c_str());
    return result;
}
ZZ prima(ZZ a, ZZ b){
    string res;
    string number = numberToString(a);
    string bstr = numberToString(b);
    int bIt = bstr.size();
    for(int i = 0; i < bIt; i++){
        res+=number[i];
    }
    ZZ nRes = stringToNumber(res);
    return nRes;
}
ZZ LEHMER(ZZ x, ZZ y, ZZ b) {
    ZZ Xpri,Ypri,A,B,C,D,t,T,U,q,qpri;
    while( y > b){
        Xpri = prima(x,b);
        Ypri = prima(y,b);
        A =ZZ(1);
        B =ZZ(0);
        C =ZZ(1);
        D =ZZ(0);
        while((Ypri + C != ZZ(0)) && ( Xpri + D != ZZ(0))){
            cout << Xpri << " " << Ypri << endl;
            q = (Xpri + A)/(Ypri + C);
            qpri = (Xpri + B)/(Ypri + D);
            if(q == qpri){
                t = A - q*C;
                A = C;
                C = t;
                t = B - q*D;
                B =  D;
                D = t;
                t = Xpri - q*Ypri;
                Xpri = Ypri;
                Ypri = t;
            }
            else{
                break;
            }
        }
        if ( B == 0){
            T = x%y;
            x = y;
            y = T;
        }
        else{
            T = A*x + B*y;
            U = C*x +D*y;
            x = T;
            y = U;
        }
    }
    ZZ V = euclidesClasico(x,y);
    cout << V << endl;
    return V;
}



int main(){
    
    cout << LEHMER( ZZ(768454923), ZZ(542167514), ZZ(103)) << endl;
    
    return 0;
}
