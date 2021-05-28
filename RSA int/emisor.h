#pragma once
#include "rsa.h"
#include "receptor.h"
#include <iostream>
using namespace std;
class Emisor
{
public:
	int clave_publica;
	Emisor(int _clave_a=0, int _clave_b=0, int _clave_publica=0, int _n = 0, int _eu_n=0, int _D=0, int _texto=0) {
		clave_a = _clave_a;
		clave_b = _clave_b;
		clave_publica = _clave_publica;
		n = _n;
		D = _D;
		eu_n = _eu_n;
		texto = _texto;

	};
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
			D = func.inversa(E, eu_n);
		}
	};
	void cifrar(Receptor reseptor, RSA func) {
		int clave_publi = reseptor.clave_publica;
		//int texto_cifrar = reseptor.get_claves()[5];
		int eu_n = reseptor.get_claves()[4];
		//int texto_desc =
		int texto_cifr = func.powermod(texto, clave_publi, eu_n);
		reseptor.set_texto(texto_cifr);
	};
	

private:
	int clave_a,clave_b,eu_n,n,D;
};

Emisor::Emisor()
{
}

Emisor::~Emisor()
{
}