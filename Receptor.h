#include <iostream>
#include <string>
#include <vector>

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
	void descifrar_mensaje(int clave ) {
		int a = 0;


		for (int i = 0; i < clave / 10; i++) {
			a = i;
			for (int j = 0; j < clave % 10; j++) {
				mensaje_co.push_back(mensaje_oc[a]);
				a = a + clave / 10;
			}
		}
	
	};
	void mostrar_mensaje() {
		for (int i = 0; i < mensaje_co.size(); i++) {
			cout << mensaje_co[i] << " ";
		}
	};

};