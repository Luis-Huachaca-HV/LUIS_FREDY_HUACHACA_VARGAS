// Practica1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Emisor.h"
#include "Receptor.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    /*
	
    //Aun no terminado, parte donde se usan las clases emisor y receptor.

    Emisor Luis("hola amigos",34);
    vector <char> mensaje_oc = Luis.ocultar_mensaje();
    Receptor Juan(mensaje_oc,"mensaje to receive",34);
    Juan.descifrar_mensaje();
    Juan.mostrar_mensaje();
    */
    
    //parte del envío
    string mensaje;
    int clave;
    cout << "Escriba su mensaje \n";
    getline(cin,mensaje);
    cout << "Ingrese su clave, debe ser un numero de dos cifras y la multiplicacion entre ella debe ser mayor a: " << mensaje.size();
    cin >> clave;
    int espacios_vacios = ((clave%10)*(clave/10)) - mensaje.size();
    for (int i = 0; i < espacios_vacios; i++) 
        mensaje.push_back('_');
    

    
    vector <char> mensaje_oc;
    int e = 0;
    
    for (int i = 0; i < clave % 10; i++) {
        e = i;
        for (int j = 0; j < clave / 10; j++) {
            
            mensaje_oc.push_back(mensaje[e]);
            e = e + clave % 10;
        }
    }

    for (int i = 0; i < mensaje_oc.size(); i++) {
        cout << mensaje_oc.at(i) << " ";
    }
    
    cout << endl;

    //parte para recibir

    vector <char> mensaje_corregido;
    int a = 0;

    for (int i = 0; i < clave/10; i++) {
        a = i;
        for (int j = 0; j < clave%10; j++) {
            mensaje_corregido.push_back(mensaje_oc.at(a));
            a = a + clave/10;
        } 
    }

    for (int i = 0; i < mensaje_corregido.size(); i++) {
        cout << mensaje_corregido.at(i) << " ";
    }

    
    return 0;
}

