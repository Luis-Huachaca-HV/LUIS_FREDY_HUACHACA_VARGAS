#include <NTL/ZZ.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;
using namespace NTL;
/*
void criba(){
    vector <int> primer_arreglo;
    vector <int> segdo_arreglo;
    ZZ ini = pow(2,16) / 2;
    ZZ fin = pow(2,16) - 1;
    while(ini != fin){
        primer_arreglo.push_back(ini);
        ini++;
    }
    cout << primer_arreglo.size();

}
int generar_primos() {
		int val = 1;
		int* number = new int;
		srand(time(NULL));
		while (val == 1) {

			*number = rand();

			cout << *number << endl;
			for (int i = 2; i < *number; i++) {
				if (*number % i == 0) {
					val = 1;
					break;
				}
				else if (i == (*number) / 2) {

					val = 2;
				}


			}

		}
		return *number;
		delete number;
	};
*/
