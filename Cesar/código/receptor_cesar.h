#pragma once
#include <iostream>
#include <string>


using namespace std;



class Receptor {
private:
	int clave;
public:
	string mensaje_oc;
	string mensaje_co;

	Receptor(string _mensaje_oc, string _mensaje_co, int _clave) {
		mensaje_oc = _mensaje_oc;
		mensaje_co = _mensaje_co;
		clave = _clave;
	};
	int get_clave() {
		return clave;
	};

	string get_mensaje_oc() {
		return mensaje_oc;
	};
	string get_mensaje_co() {
		return mensaje_co;
	};

	
	void mostrar_mensaje() {
		cout << mensaje_co << endl;
	}
};