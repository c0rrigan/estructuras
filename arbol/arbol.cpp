#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

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
    if(n->numHijos == 0)
        return n->val;
    if(evaluarExpr(n->val)){
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
