#include <iostream>
#include <string>
#include <vector>
class Emisor {
	private:
		int clave;
	public:
		Emisor(vector <char> _mensaje_oc,string _mensaje, int _clave) {
			mensaje = _mensaje;
			mensaje_oc = _mensaje_oc;
			clave = _clave;
		}

		

		void ocultar_mensaje(int clave = get_clave()) {
			new int e = 0;

			new int espacios_vacios = ((clave % 10) * (clave / 10)) - mensaje.size();
			for (int i = 0; i < espacios_vacios; i++)
				mensaje.push_back('_');

			for (int i = 0; i < clave % 10; i++) {
				e = i;
				for (int j = 0; j < clave / 10; j++) {

					mensaje_oc.push_back(mensaje[e]);
					e = e + clave % 10;
				}
			}
			delete e;
		};
		void mostrar_mensaje() {
			for (int i = 0; i < mensaje.size(); i++) {
				cout << mensaje.at(i) << " ";
			}
		};
		int get_clave() {
			return clave;
		};

};

class Receptor {
	private:
		int clave;
	public:
		Receptor(vector <char> _mensaje_oc,vector <char> _mensaje_co, int _clave) {
			mensaje_oc = _mensaje_oc;
			mensaje_co = _mensaje_co;
			clave = _clave;
		};

		int get_clave() {
			return clave;
		};
		void descifrar_mensaje(int clave = get_clave()) {
			new int a = 0;


			for (int i = 0; i < clave / 10; i++) {
				a = i;
				for (int j = 0; j < clave % 10; j++) {
					mensaje_co.push_back(mensaje_oc.at(a));
					a = a + clave / 10;
				}
			}
			delete a;
		};
		void mostrar_mensaje() {
			for (int i = 0; i < mensaje_co.size(); i++) {
				cout << mensaje_co.at(i) << " ";
			}
		};

};