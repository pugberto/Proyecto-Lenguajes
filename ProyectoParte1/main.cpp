#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

map<char, vector<string>> transitions;

vector<char> noTerminals;
string cadena;
string finalS;

vector<char> final;

const char *cursor = cadena.c_str();
bool opt = false;
bool VR = false;
bool pross = false;
short countV;


void parser(char A, bool procesado, short x){
    bool procesado2 = false;
    bool noTer = false;
    bool check = false;
    short intento = x + 1;
    short count;
    short countOpts = 0;
    while (*cursor != '\0') {
        for (const string& trans : transitions[A]){
            count = 0;
            countOpts++;
            procesado2 = false;
            if(*cursor == '\0'){
                return;
            }
            if(countV > 200){
                VR = true;
                return;
            }

            cout<<"-----------------------------------------------------------------------------------------\n";
            countV++;
            cout<<"Procesando: "   <<trans  <<"\n";
            cout<<"intento: " << x <<"\n";
            cout<<"\n";

            for (char letra : trans){
                count++;
                if(count == trans.length()){
                    cout<<"intento: " << x <<"\n";
                }
                cout<< "Letra: "  <<letra <<"\n";
                cout<< "cursor: "  <<*cursor <<"\n";
                    for (char nt : noTerminals){
                        if (letra == nt) {
                            cout<<"Coincide con un elemento de noTerminals: "  <<nt  <<"\n";
                            noTer = true;
                            pross = false;
                        }

                    }
                if(count == trans.length()) {
                    cout << "count: " << count << "\n";
                    procesado2 = true;
                }

                if(letra == *cursor) {
                    final.push_back(letra);
                    cout << letra << " = " << *cursor << "\n";
                }

                if(pross && letra != *cursor){
                    cout << "\n";
                    cout << "Leido  \n";
                    cout << "\n";
                    return;
                }


                if (noTer) {
                    procesado = true;
                    check = false;
                    cout<<"-----------------------------------------------------------------------------------------\n";
                    noTer = false;
                    parser(letra, procesado, intento);
                }else if(letra == *cursor && procesado && procesado2){
                    pross = true;
                    cout<<"Volviendo\n";
                    /*if(countOpts < transitions[A].size()){
                        opt = true;
                        NT = A;
                    }*/
                    cout<<"-----------------------------------------------------------------------------------------\n";
                    cursor++;
                    return;
                }else if (letra != *cursor ){
                    check = true;
                    cout<< "Break1 \n";

                    break;
                }else if(letra == *cursor){
                    cout<<"-----------------------------------------------------------------------------------------\n";
                    cursor++;

                }
            }
            if(check){
                opt = true;
                check = false;
                cout<<"Break2 \n";
                continue;
            }
        }

    }
}

vector<string> mascLast(vector<string> trans) {
    vector<string> transOut;
    vector<string>::iterator begin;
    for (unsigned char i = 0; i < trans.size(); i++) {
        for (unsigned char j = 0; j < trans[i].size(); j++) {
            if (trans[i][j] <= 'Z') {
                transOut.push_back(trans[i]);
                j = trans[i].size();
            }
            else if (j == (trans[i].size() - 1)) {
                begin = transOut.begin();
                transOut.insert(begin, trans[i]);
            }
        }
    }
    return transOut;
}


int main() {

    cadena = "aaabb";

    noTerminals.push_back('S');
    noTerminals.push_back('A');
    //noTerminals.push_back('B');

    bool procesado = false;


    transitions['S'].push_back("aSb");
    transitions['S'].push_back("A");
    transitions['A'].push_back("aA");
    transitions['A'].push_back("a");




    transitions['S'] = mascLast(transitions['S']);
    transitions['A'] = mascLast(transitions['A']);


    /*transitions['S'].push_back("AB");
    transitions['A'].push_back("a");
    transitions['A'].push_back("aA");
    transitions['B'].push_back("bc");
    transitions['B'].push_back("bBc");*/

    parser('S', procesado, 1);

    cout<< "\n";

    for(char l: final){
        finalS.push_back(l);
    }

    if(VR){
        cout<< "No";
    }else if(cadena == finalS){
        cout<<"Yes";
    }
}

