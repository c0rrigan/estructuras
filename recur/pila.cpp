#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "punto.h"
#include "pila.h"
void Pila::insertar(Punto *pt){
    printf("Insertar punto x:%d,y:%d\n",pt->x,pt->y);
    aux = new Nodo(pt);
    aux->rel=pos;
    pos=aux;
    //printf("Insertado:%s\n",pt);
}
void Pila::extraer(){
    if(!(pos->rel==pos)){
        printf("Extraer punto x:%d,y:%d\n",pos->pt->x,pos->pt->y);
        aux=pos;
        pos=pos->rel;
        delete(aux);
    }
}
Punto *Pila::mostrar(){
    if(pos->rel==pos){
        return NULL;//printf("Pila vacia\n");
    }else{
        printf("Mostrar punto x:%d,y:%d\n",pos->pt->x,pos->pt->y);
        return pos->pt;//printf("\t-%s\n",pos->val);
    }
}
//int main(){
//    Pila p;
//    p.insertar("globulo");
//    p.mostrar();
//    p.insertar("ventana");
//    p.insertar("amarillo");
//    p.mostrar();
//    p.extraer();
//    p.extraer();
//    p.extraer();
//    p.extraer();
//}
