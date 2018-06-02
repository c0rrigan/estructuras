#ifndef PILA_H
#define PILA_H
#include "nodo.h"
class NodoPila{
    public:
        Nodo *val;
        NodoPila *rel;
        NodoPila(){
            val = NULL;
            rel = NULL;
        }
        NodoPila(Nodo *val){
            this->val = val;
            rel = NULL;
        }
};
class Pila{
    public:
        NodoPila *aux;
        NodoPila *pos;
        Pila(){
            pos = new NodoPila(); 
            pos->rel = pos;
        }
        void insertar(Nodo*);
        Nodo *extraer();
        Nodo *mostrar();
};
#endif
