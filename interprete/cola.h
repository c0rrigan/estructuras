#ifndef COLA_H
#define COLA_H
class Cola{
    public:
        Cola();
        Nodo *entrada;
        Nodo *salida;
        Nodo *aux;
        void insertar(char*);
        void extraer();
        void mostrar();
};
#endif
