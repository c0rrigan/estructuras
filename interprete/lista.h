#ifndef LISTA_H
#define LISTA_H
class Lista{
    public:
        Lista();
        Nodo *cabeza;
        Nodo *aux;
        Nodo *aux2;
        void insertar(char*);
        void mostrar();
        void extraer();
        //void ordenar();
        //void insOrd(int);
        void mostrarTodo();
        int tam();
};
#endif
