#ifndef PILA_H
#define PILA_H
#include "punto.h"
class Nodo{
    public:
        Punto *pt;
        Nodo *rel;
        Nodo(){pt = NULL;rel = NULL;}
        Nodo(Punto *p){pt = p;rel = NULL;}
};
class Pila{
    public:
        Nodo *aux;
        Nodo *pos;
    Pila(){
        pos=new Nodo(); 
        pos->rel=pos;
    }
    void insertar(Punto*);
    void extraer();
    Punto *mostrar();
};
#endif
