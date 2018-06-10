#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
#include <string>
class Arbol{
    Nodo *raiz;
    Nodo *aux;
    std::string recorrer(Nodo*);
    public:
        Pila pilaPos;
        void insertar(Nodo *);
        void regresar();
        void niveles();
        std::string recorrido();
        Arbol(){
            raiz = NULL;
            aux = NULL;
        }
};
#endif
