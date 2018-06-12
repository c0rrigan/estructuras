#ifndef ARBBIN_H
#define ARBBIN_H
#include "nodoabin.h"
class ArbolBinario{
    void ins(Carrera*,NABin*);
    GpoCarreras *buscar(int idGpo,NABin *raiz);
    public:
    NABin *raiz;
    void insertar(Carrera*);
    void inOrden(NABin *n);
    void preOrden(NABin *n);
    void postOrden(NABin *n);
    GpoCarreras *buscarGrupo(int);
    void niveles();
    ArbolBinario(){
        raiz = NULL;
    }
};
#endif
