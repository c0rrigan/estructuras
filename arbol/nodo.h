#ifndef NODO_H
#define NODO_H
class Nodo{
    public:
        int val;
        int numHijos;
        Nodo** hijos;
        void nuevoHijo(Nodo*);
        Nodo(int val){
            this->val = val;
            this->numHijos = 0;
            this->hijos = (Nodo **)calloc(1,sizeof(Nodo**));
        }
};
#endif
