// Cesar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include "emisor_cesar.h"
#include "receptor_cesar.h"

using namespace std;

int fe_modulo(int a, int n) {
	int q = a / n;
	int r = a - (n * q);

	if (r < 0) {
		if (q <= 0)
			q = q - 1;
		else
			q = q + 1;

		r = a - (n * q);
	}

	return r;
}
string cesar_encriptador( string frase, int clave) {
	string abc = "abcdefghijklmnopqrstuvwxyz";
	int lug = 0;
	string new_str = "";
	for (int i = 0; i < frase.size(); i++) {
		lug = abc.find(frase[i]);
		if (lug + clave < abc.size())
			new_str = new_str + abc[lug+clave];
		else {
			new_str = new_str + abc[fe_modulo((lug + clave), abc.size())];
		}
	}
	return new_str;
}


string cesar_desencriptador(string frase_oc, int clave) {
	string abc = "abcdefghijklmnopqrstuvwxyz";
	int ancho = abc.size();
	int lug = 0;
	int n_pos = 0;
	string fra_co = "";
	for (int i = 0; i < frase_oc.size(); i++) {
		n_pos = abc.find(frase_oc[i]);
		if ((n_pos - clave >= 0))
			fra_co = fra_co + abc[n_pos-clave];
		else {
			lug = fe_modulo(n_pos-clave, ancho);
			fra_co = fra_co + abc[lug];
		}
	}

	return fra_co;
	
}
long long powint(int base, int exp) {
	long long result = base;
	for (int i = 0; i < exp; i++) {
		result *= base;
	}
	return result;
}

void cesardescipher(string frase);

int main()
{
	//Cesar
	//string msje;
	string mensaje_inicial = "";
	cout << "ingrese su mensaje" << endl;
	getline(cin,mensaje_inicial);
	int clave;
	cout << "ingrese su clave: ";
	cin >> clave;
	Emisor emisor("",mensaje_inicial,clave);

	string emi_mensaje = emisor.get_mensaje();
	emisor.mostrar_mensaje();
	
	

	string msj_oc = cesar_encriptador(emi_mensaje,clave);
	cout << msj_oc << endl;
	Receptor receptor(msj_oc, "",clave);
	cout << receptor.mensaje_oc << endl;
	
	receptor.mensaje_co = cesar_desencriptador(msj_oc,clave);
	receptor.mostrar_mensaje();


	cout << "\n descifrado por fuerza bruta\n";

	//parte de descifrador por fuerza bruta
	cesardescipher("hols");
	
	return 0;
}


//descifrador por fuerza bruta

void cesardescipher(string frase){
	string msj = "";
	int val = 0;
	for (int i = 0; i < 26; i++) {
		msj = cesar_desencriptador(frase, i);
		
		cout << msj << " "<< i <<  endl;
		}	
}
	
	

