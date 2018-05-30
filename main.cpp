#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define thanos 230000
using namespace std;


int main(){

int milanesa[thanos];

int aux;

string noni = "Filamentos.pgm";
string noni02 = "Filamentos02.pgm";

 ifstream file(noni);
    if(file.is_open()){

        cout << "Inicia " << endl;

        string mole[thanos];

        for(int i = 0; i < thanos; i++){

            file >> mole[i];
            if(mole[i] == "\0"){
                break;
            }
            aux++;
        }

        for(int i = 0; i < 4; i++){
            cout << mole[i] << endl;
        }

        cout << "Iniciando conversión: " << endl;
      for(int i = 3; i < aux-3; i++){

          milanesa[i-3] = abs(atoi(mole[i].c_str())-255);

      }
      cout << "Termina conversión " << endl;

      /*
       * Crear el segundo archivo
       * */

      cout << "Inicia creación del segundo archivo" << endl;
      ofstream fs(noni02);

      for(int i = 0; i < aux; i++){

          if(i < 4){
              fs << mole[i] << "\n";
          }else{
              fs << milanesa[i-4] <<"\n";
          }
      }
      fs.close();
      cout << "Se cierra el segundo archivo " << endl;

    }else{
        cout << "Fallo al abrir " << endl;
    }
}
