#ifndef NODO_H
#define NODO_H
#include <string>
#include <cstdlib>
class Nodo{
    public:
        std::string val;
        int numHijos;
        Nodo** hijos;
        void nuevoHijo(Nodo*);
        Nodo(){
            this->val = "";
            this->numHijos = 0;
            this->hijos = (Nodo **)std::calloc(1,sizeof(Nodo**));
        }
        Nodo(std::string val){
            this->val = val;
            this->numHijos = 0;
            this->hijos = (Nodo **)std::calloc(1,sizeof(Nodo**));
        }
};
#endif
