#include <iostream>
#include <string>
#include <vector>
#include "Emisor.h"
#include "Receptor.h"

using namespace std;

int main()
{


    //Aun no terminado, parte donde se usan las clases emisor y receptor.

    Emisor Luis("", "Hola amigos", 34);
    Luis.ocultar_mensaje(Luis.get_clave());

    string moc = Luis.mensaje_oc;
    Receptor Juan(moc, "", 34);
    Juan.descifrar_mensaje(Juan.get_clave());
    Juan.mostrar_mensaje();


    /*
    //parte del envío
    string mensaje;
    int clave;
    cout << "Escriba su mensaje \n";
    getline(cin, mensaje);
    cout << "Ingrese su clave, debe ser un numero de dos cifras y la multiplicacion entre ella debe ser mayor a: " << mensaje.size();
    cin >> clave;
    int espacios_vacios = ((clave % 10) * (clave / 10)) - mensaje.size();
    for (int i = 0; i < espacios_vacios; i++)
        mensaje.push_back('_');



    string mensaje_oc;//cambie de vector
    int e = 0;

    for (int i = 0; i < clave % 10; i++) {
        e = i;
        for (int j = 0; j < clave / 10; j++) {

            mensaje_oc.push_back(mensaje[e]);
            e = e + clave % 10;
        }
    }

    for (int i = 0; i < mensaje_oc.size(); i++) {
        cout << mensaje_oc[i] << " ";//cambie de vector, índice
    }

    cout << endl;

    //parte para recibir

    string mensaje_corregido;//cambie de vector
    int a = 0;

    for (int i = 0; i < clave / 10; i++) {
        a = i;
        for (int j = 0; j < clave % 10; j++) {
            mensaje_corregido.push_back(mensaje_oc[a]);
            a = a + clave / 10;
        }
    }

    for (int i = 0; i < mensaje_corregido.size(); i++) {
        cout << mensaje_corregido[i] << " ";
    }*/


    return 0;
}
