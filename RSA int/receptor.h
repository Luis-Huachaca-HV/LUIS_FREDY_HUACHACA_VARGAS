#pragma once
#include "rsa.h"
#include "emisor.h"
#include <iostream>
class Receptor
{
public:
	int clave_publica;
	
	Receptor(int _clave_a =0, int _clave_b=0, int _clave_publica=0, int _n = 0, int _eu_n=0, int _D=0, int _texto=0) {
		clave_a = _clave_a;
		clave_b = _clave_b;
		clave_publica = _clave_publica;
		n = _n;
		D = _D;
		eu_n = _eu_n;
		texto = _texto;
	};
	//~Receptor();
	void generar_claves(RSA func) {

		clave_a = func.generar_primos();
		clave_b = func.generar_primos();
		cout << "ingrese su clave publica " << endl;
		cin >> clave_publica;
	};
	void calcular_eu_n() {
		eu_n = (clave_a - 1) * (clave_b - 1);
	};
	void calcular_n() {
		n = clave_a * clave_b;
	};
	void calcular_d(RSA func) {
		bool comp = func.inversa_comp(E, eu_n);
		if (comp == 1) {
			D = func.inversa(E,eu_n);
		}
	};
	int* get_claves() {
		int values[] = { clave_a , clave_b , D , n , eu_n , texto };
		return values;
	};
	void descifrar(RSA func, Emisor emicor) {
		int texto_desc = func.powermod(texto, D, eu_n);
		texto = texto_desc;
	};
	void set_texto(int value) {
		texto = value;
	};
private:
	int clave_a;
	int clave_b;
	int D;
	int n;
	int eu_n;
	int texto;
};
