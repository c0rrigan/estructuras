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
        void mostrar();
        char *extraer();
        void ordenar(int);
        //void insOrd(int);
        void mostrarTodo();
        int tam();
        void mostrarTipo(int);
};
#endif
