#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "nodo.h"
#include "pila.h"
//Nodo::Nodo(char *s){
//    val = s;
//    rel = NULL;
//}
//Nodo::Nodo(){
//    val = NULL;
//    rel = NULL;
//}
void Pila::insertar(char *datos){
    aux = new Nodo(datos);
    aux->rel=pos;
    pos=aux;
    printf("Insertado:%s\n",datos);
}
char *Pila::extraer(){
    if(pos->rel==pos){
        return NULL;
    }else{
        char *tmp = (char *)malloc((strlen(pos->val)+1)*sizeof(char));
        strcpy(tmp,pos->val);
        aux=pos;
        pos=pos->rel;
        delete(aux);
        return tmp; 
    }
}
void Pila::mostrar(){
    if(pos->rel==pos){
        printf("Pila vacia\n");
    }else{
        printf("\t-%s\n",pos->val);
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
