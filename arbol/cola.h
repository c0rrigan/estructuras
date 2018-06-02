#ifndef COLA_H
#define COLA_H
#include "nodocola.h"
#include "nodo.h"
class Cola{
    public:
    Cola(){
        entrada=NULL;
        salida=NULL;
        aux=NULL;
    }
        NodoCola *entrada;
        NodoCola *salida;
        NodoCola *aux;
        void insertar(Nodo*);
        Nodo *extraer();
        void mostrar();
};
#endif
