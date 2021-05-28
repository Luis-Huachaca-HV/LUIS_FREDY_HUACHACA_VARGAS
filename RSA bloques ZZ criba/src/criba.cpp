#include "criba.h"
//#include "mathOp.h"
criba::criba()
{
    //ctor
}
criba::~criba()
{
    //dtor
}

ZZ criba::expo(ZZ a,ZZ b){
    ZZ res;
    ZZ n;
    n=0;
    res =1;
    while (n != b){
        res *= a;
        n++;
    }
    return res;
}

ZZ criba::Mod_f(ZZ Div,ZZ d){
    ZZ q = Div/d;
    ZZ res = Div-(d*q);
    if (res < 0){
        res += d;
        q--;
    }
    return res;
}
vector <ZZ> criba::primerGenerator(ZZ end_num){
    ZZ j;//iteradores
    ZZ i;//iteradores

    i=3;//era el primer elemento a evaluar
    vector <ZZ> arr_primos;
    j=1;//j que seran los primeros primos en aladirse
    arr_primos.push_back(j);
    j=2;
    arr_primos.push_back(j);
    string prime_bol;//comprobador de primalidad
    int z;//iteradores
    while(i < end_num){//se añadira hasta llegar al tope requerido
        z=1;
        for(;z < arr_primos.size(); z++){//for que comprueba la division con sus anteriore elementos primos
            if( Mod_f(i,arr_primos.at(z)) != 0){//modulo de division entera
                prime_bol = "primo";
            } else{
                prime_bol = "no_primo";
                break;//si no es primo se rompe el bucle for
            }
        }

        if(prime_bol == "primo")
            arr_primos.push_back(i);//si es primo se añadira al array
        i++;

    }

    z=0;
    for(;z < arr_primos.size(); z++){
        cout << arr_primos.at(z) << " ";
    }

    cout << endl << "Array de primos completado" << endl;


    return arr_primos;
}

vector <ZZ> criba::obtenerArrPrimos(){
    //creacion del arreglo con numero de bits n° 16
    vector <ZZ> primer_arreglo;
    ZZ cero;
    cero = 0;
    ZZ a,b;
    a = 2;
    b = 16;
    ZZ ini = expo(a,b) / 2;
    ZZ fin = expo(a,b) - 1;
    while(ini != fin){
        primer_arreglo.push_back(ini);
        ini++;

    }


    ZZ mitad_primo;
    mitad_primo = 1;
    while(expo(mitad_primo,a) < primer_arreglo.back()){
        mitad_primo++;
    }

    //----------------------------------------------------
    vector <ZZ> arr_primos;
    arr_primos = primerGenerator(mitad_primo);



    for(int it_arr_primos = 1;it_arr_primos < arr_primos.size(); it_arr_primos++){
        for(int it_arr_claves = 0; it_arr_claves < primer_arreglo.size(); it_arr_claves++){
            if (Mod_f(primer_arreglo.at(it_arr_claves),arr_primos.at(it_arr_primos)) == cero){

                primer_arreglo.erase(primer_arreglo.begin() + it_arr_claves);

            }

        }

    }
    cout << endl << " impresion del arreglo con claves en primo " << endl;

    for(int i = 0; i < primer_arreglo.size(); i++){
        cout << primer_arreglo.at(i) << " ";
    }
    return primer_arreglo;
}




