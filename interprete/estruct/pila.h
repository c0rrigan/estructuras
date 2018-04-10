#ifndef PILA_H
#define PILA_H
#include "nodo.h"
class Pila{
    public:
        Nodo *aux;
        Nodo *pos;
    Pila(){
        pos=new Nodo(); 
        pos->rel=pos;
    }
    void insertar(char*);
    char *extraer();
    char *mostrar();
};
#endif
