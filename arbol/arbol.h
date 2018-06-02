#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
class Arbol{
    Nodo *raiz;
    Nodo *aux;
    Pila pilaPos;
    public:
        void insertar(Nodo *);
        void regresar();
        void niveles();
        Arbol(){
            raiz = NULL;
            aux = NULL;
        }
};
#endif
