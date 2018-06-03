#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

#include "nodo.h"
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
                    n->val = atoi(buffer.c_str()); 
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

void errorLector(){
    cout << "ERROR - Revisar sintaxis del archivo del arbol" << endl;
    exit(EXIT_FAILURE);
}
int main(){
    FILE *f = fopen("txtfile","r");
    leerNodo(f);
    arb.niveles();
    return 0;
}
