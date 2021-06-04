
#include <iostream>
#include <NTL/ZZ.h>


using namespace std;
using namespace NTL;

ZZ mcdEucZz(ZZ a, ZZ b) {
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

ZZ poww(ZZ a, ZZ b){
    ZZ res;
    res = ZZ(1);
    for(ZZ i = ZZ(0); i < b; i++){
        res = res * a;
    }
    return res;
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

    cout << mcdEucZz(bit8, ZZ(8)) << endl;
    cout << mcdEucZz(bit16, ZZ(16)) << endl;
    cout << mcdEucZz(bit32, ZZ(32)) << endl;
    cout << mcdEucZz(bit256, ZZ(256)) << endl;
    cout << mcdEucZz(bit1024, ZZ(1024)) << endl;
    cout << mcdEucZz(bit2048, ZZ(2048)) << endl;

    return 0;
}