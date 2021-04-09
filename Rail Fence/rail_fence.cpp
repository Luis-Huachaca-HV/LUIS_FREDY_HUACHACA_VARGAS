
#include <iostream>
#include<string>

using namespace std;



int main()
{

    //Parte del cifrado
    string o_str = "hola_amigos";
    int r_cla = 5;
    int c_cla = 5;
    int cla = 0;
    const int for_cla = (2 * c_cla) - 2;
    int pos = 0;
    string str = "";
    for (int i = 0; i < c_cla; i++) {
        str = str + o_str[i];
        cla = (2 * r_cla) - 2;
        if (cla == 0) {
            if (for_cla + i < o_str.size()) 
                str = str + o_str[i+for_cla];
        break;
        }
        pos = i;
        while ((pos + cla < o_str.size() ) && (str.size()-1 + cla < o_str.size() )) {
            str = str + o_str[pos + cla];
            pos = pos + cla;
            cla = for_cla - cla;
            if (cla == 0)
                cla = for_cla;
        }
        r_cla = r_cla - 1;
        if (pos == c_cla - 1)
            break;
        
    }

    //impresion
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }

    cout << endl;
    

    //parte del descifrado
    r_cla = 5;
    c_cla = 5;
    cla = 0;
    pos = 0;
    int o = 0;
    string c_str = "";

    //lenado del string con guiones
    for (int i = 0; i < str.size(); i++) {
        c_str = c_str+'_';
    }

    for (int i = 0; i < c_cla; i++) {
        c_str[i] =  str[o];
        o++;
        pos = i;
        cla = (2 * r_cla) - 2;
        while (pos + cla < str.size()) {
            c_str[cla+pos] = str[o];
            pos = pos + cla;
            cla = for_cla - cla;
            if (cla == 0)
                cla = for_cla;
            o++;
        }
        r_cla = r_cla - 1;

    }

    //impresion
    for (int i = 0; i < str.size(); i++) {
        cout << c_str[i] << " ";
    }

    return 0;

}




