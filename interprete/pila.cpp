#include <stdio.h>
using namespace std;
#include "nodo.h"
#include "pila.h"
Nodo::Nodo(char *s){
    val = s;
    rel = NULL;
}
Nodo::Nodo(){
    val = NULL;
    rel = NULL;
}
void Pila::insertar(char *datos){
    aux = new Nodo(datos);
    aux->rel=pos;
    pos=aux;
    printf("Insertado:%s\n",datos);
}
void Pila::extraer(){
    if(pos->rel==pos){
        printf("No hay elementos\n");
    }else{
        printf("Extrayendo:%s\n",pos->val);
        aux=pos;
        pos=pos->rel;
        delete(aux);

    }
}
void Pila::mostrar(){
    if(pos->rel==pos){
        printf("No hay elementos\n");
    }else{
        printf("Mostrar:%s\n",pos->val);
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
