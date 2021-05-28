#include <NTL/ZZ.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "criba.h"
#include "RSA.h"



using namespace std;
using namespace NTL;
int Module(int Div, int d){
     int q;
     q = Div/d;
     int res ;
     res = Div-(d*q);
     if (res < 0){
         res += d;
         q--;
     }
     return res;
   }

int main()
{
   ZZ a, b, c, p , q,N,fiN,d,e;
   //ME FALTA COMPLETAR LAS CLAVES EN CRIBA, de ahi debo hacer la exponenciacion modular
    a = ZZ(3);

    b=ZZ(1003);
    c = ZZ(619);


   RSA emisor;

   string msj_cifrado = emisor.vectorPosiciones("tocayobest");
   RSA receptor;
   receptor.descifrar(msj_cifrado,emisor.get_N(),emisor.get_d());


}
