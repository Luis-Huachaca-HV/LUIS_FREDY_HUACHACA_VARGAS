// afin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "emisor_afin.h"
#include "receptor_afin.h"
using namespace std;

int fe_modulo(int a, int n) {
	
	int q = a / n;
	int r = a % n;

	if (r < 0)
	{
		q = q - 1;
		r = a - (q * n);
	}
	return r;
}
int mcd(int a, int b) {
	int r1 = a;
	int r2 = b;
	int q = 0;
	int r = 0;
	
	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - (q * r2);
		r1 = r2;
		r2 = r;
	}
	return r1;
}
int* mcd_ex(int a, int b) {
	int r1 = a;
	int s1 = 1;
	int t1 = 0;
	int r2 = b;
	int s2 = 0;
	int t2 = 1;
	int q, r, s, t;
	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - (q * r2);
		r1 = r2;
		r2 = r;
		s = s1 - (q * s2);
		s1 = s2;
		s2 = s;
		t = t1 - (q * t2);
		t1 = t2;
		t2 = t;
		
	}
	int val[] = { r1, s1, t1 };

	return val;
}
int inversa(int clave_a, int tam_alf) {
	clave_a = mcd_ex(clave_a, tam_alf)[1];
	if (clave_a < 0) {
		clave_a = fe_modulo(clave_a, tam_alf);
	}
	
	return clave_a;
}


int des_pos_afin(int lu, int a, int b) {
	int res = a * (lu - b);
	
	return res;
}
string cifrado_afin(string msj_claro, int clave_a, int clave_b) {
	string abc = "abcdefghijklmnopqrstuvwxyz";
	int size_t = abc.size() ;
	int lug = 0;
	int pos = 0;
	string new_str = "";
	for (int i = 0; i < msj_claro.size(); i++) {
		lug = abc.find(msj_claro[i]);
		pos = clave_a * lug + clave_b;
		
		if (pos >= size_t) {
			pos = fe_modulo(pos,size_t);
			
			new_str = new_str + abc[pos];
		}
		else {
			;
			new_str = new_str + abc[pos];
		}
	}
	return new_str;
}

string descifrado_afin(string msj_oculto, int clave_a,int clave_b) {
	string abc = "abcdefghijklmnopqrstuvwxyz";
	int size_t = abc.size();
	int lug = 0;
	int pos = 0;
	string new_str = "";
	for (int i = 0; i < msj_oculto.size(); i++) {
		lug = abc.find(msj_oculto[i]);
		pos = des_pos_afin(lug, clave_a, clave_b);
		if ((pos > 0) && (pos < size_t)) {
			new_str = new_str + abc[pos];
		}
		else {
			pos = fe_modulo(pos, size_t);
			new_str = new_str + abc[pos];
		}

	}
	return new_str;
}





int main()
{
	
	Emisor msj_claro("itscool", 0, 0);
	msj_claro.generar_claves(26);
	int clave_a = msj_claro.get_clave_a();
	int clave_b = msj_claro.get_clave_b();
	cout << "---------------------------------------------------" << endl;
	msj_claro.mostrar_mensaje();
	cout << "---------------------------------------------------" << endl;
	msj_claro.set_mensaje_claro(cifrado_afin(msj_claro.mensaje_claro,clave_a,clave_b));
	cout << "---------------------------------------------------" << endl;
	msj_claro.mostrar_mensaje();
	cout << "---------------------------------------------------" << endl;
	string msj = msj_claro.get_mensaje();
	Receptor msj_oculto(msj, inversa(clave_a, 26), clave_b);
	cout << "---------------------------------------------------" << endl;
	msj_oculto.mostrar_mensaje();
	cout << "---------------------------------------------------" << endl;
	int clavea_co = msj_oculto.get_clave_a();
	int claveb_co = msj_oculto.get_clave_b();
	msj_oculto.set_mensaje(descifrado_afin(msj_oculto.mensaje_oculto, clavea_co, claveb_co));
	cout << "---------------------------------------------------" << endl;
	msj_oculto.mostrar_mensaje();
	cout << "---------------------------------------------------" << endl;
	

	
}

