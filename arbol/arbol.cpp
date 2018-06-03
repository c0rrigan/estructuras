#include <cstdio>
#include <iostream>
#include <cstdlib>

#include "nodo.h"
#include "pila.h"
#include "cola.h"
#include "arbol.h"

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
