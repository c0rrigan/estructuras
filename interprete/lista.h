#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
class Lista{
    public:
        Lista(){cabeza=NULL;aux=NULL;aux2=NULL;}
        Nodo *cabeza;
        Nodo *aux;
        Nodo *aux2;
        void insertar(char*);
        char *mostrar();
        char *extraer();
        //void ordenar();
        //void insOrd(int);
        void mostrarTodo();
        int tam();
};
#endif
