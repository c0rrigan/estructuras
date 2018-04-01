#include <cstdio>
using namespace std;
#include "nodo.h"
#include "cola.h"
//Nodo::Nodo(char *s){
//    val = s;
//    rel = NULL;
//}
Cola::Cola(){
    entrada=NULL;
    salida=NULL;
    aux=NULL;
}
void Cola::insertar(char *val){
    aux=new Nodo(val);
    if(!salida){
        salida=aux;
        aux->rel=NULL;
    }else{
        aux->rel=entrada->rel;
        entrada->rel=aux;
    }
    entrada=aux;
    printf("Insertar:%s\n",val);
}
void Cola::extraer(){
    if(salida){
        printf("Extraer :%s\n",salida->val);
        aux=salida->rel;
        delete(salida);
        salida=aux;
    }else{
        printf("Cola vacia\n");
    }
}
void Cola::mostrar(){
    if(salida)
        printf("Mostrar :%s\n",salida->val);
    else
        printf("Vacio\n");
}
//int main(){
//    Cola c;
//    c.mostrar();
//    c.extraer();
//    c.insertar("bmw");
//    c.insertar("violencia");
//    c.extraer();
//    c.extraer();
//    c.extraer();
//}
