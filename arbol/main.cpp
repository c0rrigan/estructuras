#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "main.h"
#include "pila.h"
#include "nodoabin.h"
#include "arb-bin.h"
#include "arbol.h"
#include "lector.h"
#include "cuestionarios.h"
using namespace std;

Arbol arbol;
ArbolBinario *fm;
ArbolBinario *mb;
ArbolBinario *sa;
//Declaraciones de funciones
void errorArchivo(string);
int leerDatos();
vector<Carrera*> grupoCarreras(string);

//Función que lee el arbol y los datos de las escuelas
int main(){
    string buffer;
    vector <Carrera*> opciones;
    leerDatos();//Cargar datos a arboles
    aplicarCuestionario1(); 
    buffer = arbol.recorrido();
    if(buffer.empty()){
        cout << "Error de recorrido de arbol" << endl;
        exit(EXIT_FAILURE);
    }
    opciones = grupoCarreras(buffer);
    for(auto op :opciones){
        cout << op->nombre << ",";
    }
}
//Función que regresa el grupo de carreras dado el nombre
//de un grupo en formado 'grupo.num', donde 'grupo' es fm,sa,mb
//y 'num' es el número del grupo en esa área
vector<Carrera*> grupoCarreras(string grupo){
    GpoCarreras *aux;
    char *area = strtok((char*)grupo.c_str(),".");
    char *sid = strtok(NULL,".");  
    if(!strcmp(area,"fm")){
        aux = fm->buscarGrupo(atoi(sid));
    }
    if(!strcmp(area,"mb")){
        aux = mb->buscarGrupo(atoi(sid));
    }
    if(!strcmp(area,"sa")){
        aux = sa->buscarGrupo(atoi(sid));
    }
    if(!aux){
        cout << "Error de grupos de carreras" << endl;
        exit(EXIT_FAILURE);
    }
    return aux->carreras;
}
int leerDatos(){
    FILE *f = fopen(DIR_ARBOL.c_str(),"r");
    if(!f){
        errorArchivo(DIR_ARBOL);
    }else{
        arbol = leerArbol(f);
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
