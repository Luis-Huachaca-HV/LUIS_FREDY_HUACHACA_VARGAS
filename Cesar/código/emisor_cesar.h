#pragma once
#include <iostream>
#include <string>
using namespace std;



class Emisor {
private:
	int clave;
public:
	string mensaje;
	string mensaje_oc;

	Emisor(string _mensaje_oc, string _mensaje, int _clave) {
		mensaje_oc = _mensaje_oc;
		mensaje = _mensaje;
		clave = _clave;
	};

	string get_mensaje_oc() {
		return mensaje_oc;
	};
	string get_mensaje() {
		return mensaje;
	};

	void mostrar_mensaje() {
		cout << mensaje << endl;
		
	};
	const int get_clave() {
		return clave;
	};

};