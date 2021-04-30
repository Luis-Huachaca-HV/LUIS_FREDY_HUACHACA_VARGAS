#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;



class Receptor {
private:
	int clave_a;
	int clave_b;
public:
	string mensaje_oculto;
	

	Receptor(string _mensaje_oculto, int _clave_a,int _clave_b) {
		mensaje_oculto = _mensaje_oculto;
		clave_a = _clave_a;
		clave_b = _clave_b;

	};



	int get_clave_a() {
		return clave_a;
	};
	int get_clave_b() {
		return clave_b;
	};

	string get_mensaje_oculto() {
		return mensaje_oculto;
	};
	void set_mensaje(string msj) {
		mensaje_oculto = msj;
	};


	void mostrar_mensaje() {
		cout << mensaje_oculto << endl;
	}
};