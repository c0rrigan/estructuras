#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "nodo.h"
#include "pila.h"
void Pila::insertar(Nodo *n){
    aux = new NodoPila(n);
    aux->rel = pos;
    pos = aux;
}
Nodo *Pila::extraer(){
    if(pos->rel==pos){
        return NULL;
    }else{
        Nodo *naux = pos->val;
        aux = pos;
        pos = pos->rel;
        delete(aux);
        return naux; 
    }
}
Nodo *Pila::mostrar(){
    if(pos->rel == pos){
        return NULL;
    }else{
        return pos->val;
    }
}
