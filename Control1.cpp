// Control1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int entero(string str) {
	int num = 0;
	int size = str.size();
	for (int i = 0, j = str.size(); i < size; i++)
		num += (str[--j] - '0') * pow(10, i);
	return num;
}

int main()
{
	string str;
	cout << "ingrese su oración: ";
	getline(cin,str);
	//for (int i = 0; i < str.size(); i++) {
		//cout << str.at(i);
	//}
	int clave;
	cout << "ingrese su clave: ";
	cin >> clave;
	int flag = 0;
	int inicio = 0;
	int sobra = str.size() % clave;
	string separ;

	//imprimir con clave separada
	for (int i = 0; i < str.size(); i++) {
		if (flag == clave ) {
			for (int j = inicio; j < inicio + flag; j++) {
				cout << str[j] << " ";
			}
			inicio = i;
			cout << endl;
			flag = 0;
		}
		if (i == str.size() - sobra) {
			for (int j = i; j < str.size(); j++) {
				if (j < str.size())
					cout << str[j] << " ";
			}
			for (int z =0; z < clave - sobra ; ++z)
				cout << "X" << " ";
			break;
		}

		flag++;
	}
	flag = 0;
	inicio = 0;


	//concatenar con '*'
	for (int i = 0; i < str.size(); i++) {
		//divisiones
		if (flag == clave) {
			for (int j = inicio; j < inicio + flag; j++) {
				separ = separ +  str[j];
			}
			separ = separ + '*';
			inicio = i;
			cout << endl;
			flag = 0;
		}
		//final
		if (i == str.size() - sobra) {
			for (int j = i; j < str.size(); j++) {
				if (j < str.size())
					separ = separ + str[j];
			}
			for (int z = 0; z < clave - sobra; ++z)
				separ = separ+ 'X';
		}

		flag++;
	}
	for (int i = 0; i < separ.size(); i++) {
		cout << separ.at(i);
	}
	




	//intento de llenar a vector
	/*
	int n_veces;
	if (sobra == 0)
		n_veces = str.size() / clave;
	else
		n_veces = (str.size() / clave) + 1;
	
	vector <string> c_valores(n_veces);
	for (int i = 0; i < separ.size(); i++) {
		if (separ[i] == '*') {
			c_valores.push_back(separ.substr(i-clave-1,clave));
		}
	}
	for (int i = 0; i < c_valores.size(); i++) {
		for (int j = 0; j < c_valores[i].size(); j++) {
			cout << c_valores[i][j] << " ";
		}
		cout << " ";
	}*/

	//string a entero
	string stra;
	cout << "ingrese el numero";
	getline(cin, stra);
	int num = entero(stra);
	cout << "entero convertido" << num;
}

