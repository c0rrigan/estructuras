#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

#include "nodo.h"
#include "pila.h"
#include "cola.h"
#include "arbol.h"
#include "expr.h"

using namespace std;

void Nodo::nuevoHijo(Nodo *n){
    this->hijos = (Nodo **) realloc(this->hijos,(numHijos+1)*sizeof(Nodo**));
    this->hijos[numHijos] = n;
    numHijos++;
}

void Arbol::insertar(Nodo *n){
    if(!raiz){
        raiz = n;
    }else{
        aux = pilaPos.mostrar();
        aux->nuevoHijo(n);
    }
    pilaPos.insertar(n);
}

void Arbol::regresar(){
    pilaPos.extraer();
}
void Arbol::niveles(){
    Cola c;
    Nodo *aux;
    c.insertar(raiz);
    while((aux = c.extraer())){
        cout << aux->val << ",";
        if(aux->numHijos > 0){
            int j,i = aux->numHijos;
            for(j = 0;j < i; j++){
                c.insertar(aux->hijos[j]);
            }
        }
    }
}
//Función que inicia el recorrido y regresa 
//un string según sea el resultado
string Arbol::recorrido(){
    return recorrer(this->raiz);
}
string Arbol::recorrer(Nodo *n){
    string val = n->val;
    char *cbuff;
    cout << "nodo:val" << n->val << '\n';
    cbuff = strtok((char*)n->val.c_str(),"=");
    if(strlen(cbuff) == 2){
        cbuff = strtok(NULL,"=");
        val = cbuff;
    }
    if(n->numHijos == 0)
        return n->val;
    if(evaluarExpr(val)){
        cbuff = strtok((char*)n->val.c_str(),"=");
        if(!strcmp(cbuff,"fm")){
            //TODO:Cuestionario fm 
            cbuff = strtok(NULL,"=");
            cout << "La rama que podría interesarle es:" << "Físico-matemáticas" << "\n";
            cout << "a continuación se le haran unas preguntas para decidir que carreras le podrían gustar" << endl;
            aplicarCuestionarioFM(); 
        }
        if(!strcmp(cbuff,"sa")){
            cbuff = strtok(NULL,"=");
            cout << "La rama que podría interesarle es:" << "Sociales-administrativas" << "\n";
            cout << "a continuación se le haran unas preguntas para decidir que carreras le podrían gustar" << endl;
            aplicarCuestionarioSA(); 
        }
        if(!strcmp(cbuff,"mb")){
            cbuff = strtok(NULL,"=");
            cout << "La rama que podría interesarle es:" << "Médico-biológicas" << "\n";
            cout << "a continuación se le haran unas preguntas para decidir que carreras le podrían gustar" << endl;
            aplicarCuestionarioMB(); 
        }
        int i;
        Nodo *aux;
        string sAux;
        for(i = 0; i < n->numHijos; i++){
            aux = n->hijos[i];
            sAux = recorrer(aux);
            if(!sAux.empty()){
                return sAux;
            }
        }
    }
    return ""; 
}
