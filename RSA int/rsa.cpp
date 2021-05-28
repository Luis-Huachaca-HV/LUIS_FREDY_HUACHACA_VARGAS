// rsa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "emisor.h"
#include "receptor.h"
#include "rsa.h"
using namespace std;

int main()
{
	Emisor emicor;
	Receptor reseptor;
	RSA resa;

	//parte de claves del emisor
	reseptor.generar_claves(resa);
	reseptor.calcular_n();
	reseptor.calcular_eu_n();
	reseptor.calcular_d(resa);
	//parte de claves
	emicor.generar_claves(resa);
	emicor.calcular_n();
	emicor.calcular_eu_n();
	emicor.calcular_d(resa);
	
	//funcion
	emicor.cifrar(reseptor, resa);
	//funcion
	reseptor.descifrar(resa, emicor);


}

