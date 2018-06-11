#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>

#include "expr.h"
#include "arb-bin.h"
#include "nodo.h"
#include "nodoabin.h"
#include "pila.h"
#include "arbol.h"

using namespace std;

string VAL_STRING = "val";
string HIJOS_STRING = "hijos";

Nodo *leerNodo(FILE*);
void errorLector();

Arbol arb;

string leerCadena(FILE *f){
    string buffer;
    char c;
    if((c = fgetc(f)) == '"'){
        while((c = fgetc(f))!='"'){
            //Sí pasa por estos carácteres significa que
            //posiblemente falto cerrar con comillas la variable
            if(c == ':' || c == '}' || c == '{')
                buffer.clear();
            else
                buffer.push_back(c);
        }
    }
    return buffer;
}
void leerHijos(FILE *f,Nodo *padre){
    char c;
    Nodo *hijo;
    //Buscar el corchete de los 'hijos'
    while((c = fgetc(f)) != '[');
    //Si no se llego al final del archivo buscando los corchetes
    //continua
    if(c!= EOF){
        while((c = fgetc(f)) != ']'){
            if(c == '{'){
                //Regresar las llaves que abren para cumplir con el
                //requisito de la funcion 'leerNodo'
                ungetc(c,f);
                hijo = leerNodo(f);
                //Regresar al nodo padre anterior para seguir
                //añadiendo al mismo nodo padre
                arb.regresar();
            }
        }
    }else{
        errorLector();
    }
}
Nodo *leerNodo(FILE *f){
    char c;
    string buffer;
    Nodo *n = new Nodo();
    //Recorrer hasta buscar la llave que abre
    while((c = fgetc(f)) != '{');
    //Recorrer todos los carácteres hasta llegar a la
    //llave que cierra
    while((c = fgetc(f)) != '}'){
        //Empezar a leer a partir de que empiezan las comillas
        ungetc(c,f);
        buffer = leerCadena(f);
        if(buffer.empty()){
            errorLector();
        }else{
            //Verificar si el valor el para el campo 'val'
            if(!buffer.compare(VAL_STRING)){
                //Buscar los dos punto y comenzar a leer el
                //siguiente valor
                while((c = fgetc(f)) != ':');
                buffer = leerCadena(f);
                if(buffer.empty())
                    errorLector();
                else
                    n->val = buffer;
            }else{
                errorLector();
            }
        }
        arb.insertar(n);
        //Si el nodo no tiene hijos, regresa
        if((c = fgetc(f)) == '}')
            return n;
        ungetc(c,f);
        //Buscar la ',' despues de 'val'
        while((c = fgetc(f)) != ',');
        //Buscar las comas que abren 'hijos'
        while((c = fgetc(f)) != '"');
        if(c != EOF){
            ///Buscar la cadena correspondiente a 'hijos'
            ungetc(c,f);
            buffer = leerCadena(f);
            if(buffer.empty()){
                errorLector();
            }else{
                while((c = fgetc(f)) != ':');
                if(c != EOF){
                    if(!buffer.compare(HIJOS_STRING))
                        leerHijos(f,n);
                }else{
                    errorLector();
                }
            }
        }else{
            errorLector();
        }
    }
    return n;
}
//Recibe el renglón del csv con los datos de la carrera y los
//convierte en un objeto 'Carrera'
Carrera *crearCarrera(string s){
    Carrera *c = new Carrera();
    vector<string> carreras;
    char *buffer = strtok((char*)s.c_str(),",");
    c->nombre = buffer;
    buffer = strtok(NULL,",");
    c->idGrupo = atoi(buffer);
    buffer = strtok(NULL,",");
    while(buffer != NULL){
        carreras.push_back(buffer);
        buffer = strtok(NULL,",");
    }
    c->plant = carreras;
    return c;
}
//Función que lee los grupos de escuelas encontrados
//en los archivos 'GRUPO_FM.csv','GRUPO_MB.csv','GRUPO_SA.csv'
//del directorio 'datos'
ArbolBinario leerEscuelas(FILE *f,ArbolBinario *arbol){
    string buffer;
    char c;
    while((c = getc(f)) != EOF){
        if(c == '\n'){
            arbol->insertar(crearCarrera(buffer));
            buffer.clear();
            continue;
        }
        buffer.push_back(c);
    }
    
}
//Lee el arbol almacenado en el archivo 'f'
Arbol leerArbol(FILE *f){
    leerNodo(f);
    return arb;
}
void errorLecturaArchivo(string s){
    cout << "ERROR - Revisar se el archivo" << s << "en el directorio 'datos'" << endl;
    exit(EXIT_FAILURE);
}
void errorLector(){
    cout << "ERROR - Revisar sintaxis del archivo del arbol" << endl;
    exit(EXIT_FAILURE);
}
//Lee el arbol
int main(){
//    FILE *f = fopen("txtfile","r");
//    Arbol a = leerArbol(f);
//    a.niveles();
//    cout << "recorrido:" << a.recorrido() << endl;
FILE *f = fopen("./datos/GRUPO_FM.csv","r");
ArbolBinario *arb = new ArbolBinario();
leerEscuelas(f,arb);
arb->niveles();
}
