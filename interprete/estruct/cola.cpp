#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "nodo.h"
#include "cola.h"
//Nodo::Nodo(char *s){
//    val = s;
//    rel = NULL;
//}
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
char *Cola::extraer(){
    if(salida){
        char *tmp = (char *)malloc((strlen(salida->val)+1)*sizeof(char));
        strcpy(tmp,salida->val);
        aux=salida->rel;
        delete(salida);
        salida=aux;
        return tmp;
    }else{
        return (char*)"No hay elementos";
    }
}
void Cola::mostrar(){
    if(salida)
        printf("\t%s\n",salida->val);
    else
        printf("No hay elementos\n");
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
