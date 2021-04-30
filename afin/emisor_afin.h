#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int mcd_(int a, int b) {
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


class Emisor {
private:
	int clave_a;
	int clave_b;
public:
	string mensaje_claro;
	Emisor(string _mensaje_claro = "", int _clave_a = 0,int _clave_b = 0) {
		mensaje_claro = _mensaje_claro;
		clave_a = _clave_a;
		clave_b = _clave_b;
	};
	void generar_claves(int tam_alf) {
		int clave_a_g = rand() % tam_alf + 1;
		while (mcd_(clave_a_g, tam_alf) != 1) {
			clave_a_g = rand() % tam_alf + 1;
		}
		clave_a = clave_a_g;
		clave_b = rand() % tam_alf + 1;
	};

	void set_mensaje_claro(string msj) {
		mensaje_claro = msj;
	};
	string get_mensaje() {
		return mensaje_claro;
	};

	void mostrar_mensaje() {
		cout << mensaje_claro << endl;

	};
	const int get_clave_a() {
		return clave_a;
	};
	const int get_clave_b() {
		return clave_b;
	};
};