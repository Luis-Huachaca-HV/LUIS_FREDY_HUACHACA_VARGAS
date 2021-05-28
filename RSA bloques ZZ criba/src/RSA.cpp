#include "RSA.h"
//#include "criba.h"
#include "mathOp.h"

RSA::RSA()
{
    abc = "abcdefghijklmnopqrstuvwxyz ";
    criba cribaa;
    vector <ZZ> arr_primos;
    arr_primos = cribaa.obtenerArrPrimos();
    srand(time(NULL));
    int numPos = Modulo(rand(),arr_primos.size());
    p = arr_primos.at(numPos);
    numPos =  Modulo(rand(),arr_primos.size());
    q = arr_primos.at(numPos);
    numPos =  Modulo(rand(),arr_primos.size());
    e = arr_primos.at(numPos);
    N = p*q;
    fiN = (p-1)*(q-1);
    d = InversaMultiplicativa(e,fiN);
    cout <<endl << p << " " << q << " " <<  N<< " " << e<< " " << d<< endl;
    //ctor
}
RSA::RSA(ZZ _N, ZZ _e, ZZ _d){
    abc = "abcdefghijklmnopqrstuvwxyz ";
    N = _N;
    e = _e;
    d = _d;
}

RSA::~RSA()
{
    //dtor
}
ZZ RSA::get_N(){
    return N;
}
ZZ RSA::get_d(){
    return d;
}
ZZ RSA::stringToNumber(string str)
{
    ZZ result(NTL::INIT_VAL, str.c_str());
    return result;
}
int RSA::stringToNumberr(string str)
{
    int num;
    stringstream ss;
    ss << str;
    ss >> num;
    return num;
}
string RSA::numberToString(ZZ num){
    stringstream buffer;
    //stringstream buffer;
    buffer << num;
    return buffer.str();
}
string RSA::numberToString(int num){
    stringstream buffer;
    //stringstream buffer;
    buffer << num;
    return buffer.str();
}


void RSA::insDatos(string Nombre, ZZ N, ZZ e){
    fstream myFile;
    string a;
    string b;
    a = numberToString(N);
    b = numberToString(e);
    cout << a << " " << b << endl;
    myFile.open("directorio_publico.txt",ios::out);
    if(myFile.is_open()){
        myFile << Nombre + '\n';
        myFile << a + '\n';
        myFile << b + '\n';
        myFile.close();
    }
}
vector <string> RSA::outDatos(){
    fstream myFile;
    vector <string> data;
    myFile.open("directorio_publico.txt", ios::in);
    if(myFile.is_open()) {
        string line;
        while (getline(myFile,line)){
            data.push_back(line);
        }

    }
    return data;
}
string RSA::vectorPosiciones(string mensaje){
    //sacar el ancho mas significativo
    int significativo = abc.size()- 1;//26
    stringstream buffer;
    buffer << significativo;
    string ancho;
    ancho = buffer.str();//"26"
    significativo = ancho.size();//2

    //
    int i = 0;
    string numPosiciones = "";
    string posicion = "";
    while(i <= mensaje.size()-1){
        posicion = numberToString(abc.find(mensaje[i]));
        for(int j = posicion.size(); j < significativo; j++){
            posicion.insert(0,"0");
        }
        numPosiciones += posicion;
        i++;

    }
    cout << numPosiciones << endl;

    int anchoN = numberToString(N).size();

    for(int i = numPosiciones.size() ; Modulo(i,anchoN -1) != 0; i=numPosiciones.size()){
        numPosiciones += ancho;

    }
    cout << "num posiciones" << endl;
    cout << numPosiciones << endl;
    vector <string> vectorBloques;
    for(int i = 0; i < numPosiciones.size(); i+= anchoN -1){
        vectorBloques.push_back(numPosiciones.substr(i,anchoN-1));
    }
    for(int i= 0; i < vectorBloques.size(); i++){
        cout << vectorBloques.at(i) << " ";
    }
    string vectorBloquesZZ;

    ZZ val;
    string nVal;
    for(int i= 0; i < vectorBloques.size(); i++){
        val = stringToNumber(vectorBloques.at(i));
        val = ExpoMod2(val,e,N);
        nVal = numberToString(val);
        for(int j = nVal.size(); j < anchoN; j++){
            nVal.insert(0,"0");
        }
        vectorBloquesZZ += nVal;
    }
    cout << vectorBloquesZZ << endl;
    return vectorBloquesZZ;
}

string RSA::descifrar(string cifrado, ZZ N, ZZ d){
    int anchoN = numberToString(N).size();

    vector <ZZ> vectorBloques;
    for(int i = 0; i < cifrado.size(); i += anchoN ){
        vectorBloques.push_back( stringToNumber(cifrado.substr(i,anchoN)));
    }

    string vectorBloquesS;

    ZZ val;
    string nVal;
    for(int i= 0; i < vectorBloques.size(); i++){
        //val = stringToNumber(vectorBloques.at(i));
        val = ExpoMod2(vectorBloques.at(i),d,N);
        nVal = numberToString(val);
        for(int j = nVal.size(); j < anchoN - 1; j++){
            nVal.insert(0,"0");
        }
        vectorBloquesS += nVal;
    }
    cout << vectorBloquesS << " ";

    int significativo = abc.size()- 1;//26
    stringstream buffer;
    buffer << significativo;
    string ancho;
    ancho = buffer.str();//"26"
    significativo = ancho.size();//2


    string descifrado;
    int pos;
    for(int i = 0; i < vectorBloquesS.size(); i += significativo ){
        pos = stringToNumberr(vectorBloquesS.substr(i,significativo));
        descifrado += abc[pos];
    }
    cout << descifrado << endl;


}


