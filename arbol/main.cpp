#include <iostream>
#include <string>
#include "pila.h"
#include "nodoabin.h"
#include "arb-bin.h"
#include "arbol.h"
#include "lector.h"
using namespace std;

string DIR_ARBOL = "arbol.conf";//Constante del archivo del arbol
string DIR_FM = "./datos/GRUPO_FM.csv";//Dirrección del archivo de escuelas del grupo físico-matemáticas
string DIR_MB = "./datos/GRUPO_MB.csv";//Constante del l archivo de escuelas del grupo médico-biológicas
string DIR_SA = "./datos/GRUPO_SA.csv";//Constante del l archivo de escuelas del grupo sociales-administrativas


Arbol arbol;
ArbolBinario *fm;
ArbolBinario *mb;
ArbolBinario *sa;
//Declaraciones de funciones
void errorArchivo(string);
int leerDatos();

//Función que lee el arbol y los datos de las escuelas
int main(){
    leerDatos();//Cargar datos a arboles
    
//    int op = 1;
//    GpoCarreras *aux;
//    string buffer;
//    while(op != -1){ 
//        getline(cin,buffer);
//        aux = mb->buscarGrupo(atoi(buffer.c_str()));
//        if(aux){
//            for(auto val :aux->carreras){
//                cout << val->nombre << ",";
//            }
//        }
//        cout << endl;
//    }
}
int leerDatos(){
    FILE *f = fopen(DIR_ARBOL.c_str(),"r");
    if(!f){
        errorArchivo(DIR_ARBOL);
    }else{
        Arbol a = leerArbol(f);
        fclose(f);
    }
    //Físico-matemáticas
    f = fopen(DIR_FM.c_str(),"r");
    if(!f){
        errorArchivo(DIR_FM);
    }else{
        fm = leerEscuelas(f);
        fclose(f);
    }
    //Medico-biológicas
    f = fopen(DIR_MB.c_str(),"r");
    if(!f){
        errorArchivo(DIR_FM);
    }else{
        mb = leerEscuelas(f);
        fclose(f);
    }
    //Sociales-administrativas
    f = fopen(DIR_SA.c_str(),"r");
    if(!f){
        errorArchivo(DIR_SA);
    }else{
        sa = leerEscuelas(f);
        fclose(f);
    }
    
}
void errorArchivo(string s){
    cout << "Errror, no se puede leer:" << s << endl;
    exit(EXIT_FAILURE);
}
