#ifndef COLA_H
#define COLA_H
#include "nodo.h"
class Cola{
    public:
    Cola(){
        entrada=NULL;
        salida=NULL;
        aux=NULL;
    }
        Nodo *entrada;
        Nodo *salida;
        Nodo *aux;
        void insertar(char*);
        char *extraer();
        void mostrar();
};
#endif
