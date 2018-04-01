#ifndef PILA_H
#define PILA_H
class Pila{
    public:
        Nodo *aux;
        Nodo *pos;
    Pila(){
        pos=new(Nodo); 
        pos->rel=pos;
    }
    void insertar(char*);
    void extraer();
    void mostrar();
};
#endif
