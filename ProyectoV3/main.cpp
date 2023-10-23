#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

map<char, vector<string>> transitions;
vector<char> noTerminals;
string cadena;

vector<char> final;

const char *cursor = cadena.c_str();

void NTparser (const char A);

void parser(char A){
    while (*cursor != '\0') {

        for (const string& trans: transitions[A]){
            cout<< "Procesando: " << trans << "\n";
            cout<< "\n";


            for (char letra: trans){
                cout<< "Letra: " << letra<< "\n";
                cout<< "Cursor: " << *cursor<< "\n";
                for (char nt: noTerminals){


                    if (letra == nt) {
                        cout << "Coincide con un elemento de noTerminals: " << nt << "\n";

                        cout <<"-----------------------------------------------------------------------------------------\n";
                        NTparser(letra);




                    }else if(letra == *cursor){
                        cout<< letra <<" = " << *cursor<<"\n";
                        cout <<"-----------------------------------------------------------------------------------------\n";
                        cursor++;



                    } else {
                        std::cout << "Debug: no  era el cursor.";

                    }


                }

            }
            cout<< "------------------------------------------------------------------------------\ntamaño cadena" << (cadena.c_str() + (cadena.size()-1 )* sizeof(char)) << "\nCursor: " << cursor << "\n";
        }
    }

}

void NTparser (const char A) {
    for (const string& trans: transitions[A]){
        cout<< "Procesando: " << trans << "\n";
        cout<< "\n";


        for (char letra: trans){
            cout<< "Letra: " << letra<< "\n";
            cout<< "Cursor: " << *cursor<< "\n";
            for (char nt: noTerminals){


                if (letra == nt) {
                    cout << "Coincide con un elemento de noTerminals: " << nt << "\n";

                    cout
                            << "-----------------------------------------------------------------------------------------\n";
                    NTparser(letra);

}

int main() {

    cadena = "aacbb";

    noTerminals.push_back('S');

    bool procesado = false;
    bool procesado2 = false;

    transitions['S'].push_back("c");
    transitions['S'].push_back("aSb");

    parser('S');


}
