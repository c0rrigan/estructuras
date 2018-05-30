#ifndef NODO_H
#define NODO_H
class Nodo{
    public:
        int valor;
        Nodo *izq;
        Nodo *der;
        Nodo(int num){
            valor = num;
            izq = NULL;
            der = NULL;
        }
};
#endif
