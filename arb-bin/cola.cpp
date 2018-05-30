#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "nodo.h"
#include "nodocola.h"
#include "cola.h"

void Cola::insertar(Nodo *val){
    aux = new NodoCola(val);
    if(!salida){
        salida = aux;
        aux->rel = NULL;
    }else{
        aux->rel = entrada->rel;
        entrada->rel = aux;
    }
    entrada = aux;
}
Nodo *Cola::extraer(){
    if(salida){
        NodoCola *temp = salida;
        aux = salida->rel;
        salida = aux;
        return temp->val;
    }else{
        return NULL;
    }
}
void Cola::mostrar(){
    //if(salida)
    //    printf("\t%s\n",salida->val);
    //else
    //    printf("No hay elementos\n");
}
