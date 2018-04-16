#ifndef LISTA_H
#define LISTA_H
class Nodo{
    public:
        int val;
        Nodo *sig;
        Nodo(){val = 0;sig = NULL;}
        Nodo(int s){val = s;sig = NULL;}
};
class Lista{
    public:
        Lista(){cabeza=NULL;aux=NULL;aux2=NULL;}
        Nodo *cabeza;
        Nodo *aux;
        Nodo *aux2;
        void insertar(int);
        void mostrar();
        int extraer(int);
        int buscar(int);
        void insOrd(int);
        void mostrarTodo();
        int tam();
};
#endif
