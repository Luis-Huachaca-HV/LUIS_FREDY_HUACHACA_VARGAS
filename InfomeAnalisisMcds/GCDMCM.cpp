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

bool PrimeNumber(ZZ n)
{
    ZZ m = n/2;
    for (ZZ i = ZZ(2); i <= m ; i++)
    {
        if (n % i == 0)
        { return false; }
    } return true;
}

ZZ LCM(ZZ x, ZZ y)
{
    ZZ a = max(x, y); ZZ b = min(x, y); ZZ lcm = ZZ(1);
    ZZ i = ZZ(2);
    bool flag;
    while (a != 1 || b != 1)
    {
        if (a % i == 0 || b % i == 0)
        {
            cout << a << '\t' << "-" << '\t' << b << '\t' << " -----> " << i << endl;
            flag = true;
            if (a % i == 0 && b % i == 0)
            {
                a = a/i;
                b = b/i;
            }
            else if (a % i == 0)
                { a = a/i; }
            else if (b % i == 0)
                { b = b/i; }
            lcm = lcm * i;
        }
        else
            { flag = false; }
        if (!flag)
        {
            if ( PrimeNumber(min(a,b)) && min(a,b) != 1 && PrimeNumber(max(a,b)))
                { i = min(a,b); } //para hallar el menor primo
            else if ( PrimeNumber(max(a,b)) && max(a,b) != 1 && min(a,b) == 1)
                { i = max(a,b); } //para hallar el mayor primo
            else
                { i++; }
        }
    }
    cout << '\t' << "Minimo Comun Multiplo: " << lcm << endl;
    return  lcm;
}

ZZ UsingLCM(ZZ a, ZZ b)
{
    cout << "---------------------------------" << endl;
    ZZ mcm = LCM(a,b);
    cout << "---------------------------------" << endl;
    ZZ GDC = (a*b)/ mcm;
    cout << "MCD = " << a << " * " << b << " / " << mcm << endl;
    return GDC;
}

int main()
{
    ZZ a,b,res;
    a = 144; b = 89;
    res = UsingLCM(a,b);
    cout << "MCD = " << res << endl;
    cout << "---------------------------------" << endl;
    cout << "Fin del Programa" << endl;
    cout << "---------------------------------" << endl;
    return 0;
}
