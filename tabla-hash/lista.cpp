#include <cstdio>
#include "lista.h"
using namespace std;
int Lista::tam(){
    aux=cabeza;
    int i;
    for(i=0;aux!=NULL;i++,aux=aux->sig);
    return i;
}
void Lista::insertar(int val){
    aux2 = new Nodo(val);
    if(cabeza==NULL){
        cabeza = aux2;
        return;
    }
    aux = cabeza;
    if(aux2->val <= aux->val){
        aux2->sig = aux;
        cabeza = aux2;
        return;
    }
    if(aux->sig == NULL){
        aux->sig = aux2;
        return;
    }
    while((aux2->val) >= (aux->sig->val)){
        if(aux->sig->sig == NULL){
            aux->sig->sig = aux2; 
            return;
        }
        aux = aux->sig;
    }
    aux2->sig=aux->sig;
    aux->sig=aux2;
}
int Lista::buscar(int val){
    if(cabeza==NULL){
        return 0;
    }
    //if(cabeza->
    aux = cabeza;
    while(aux->sig!=NULL){
        if(val == aux->val)
            return val;//printf("encontrado\n");
        aux = aux->sig;
    }
    if(val == aux->val)
        return val;
    return 0;
}
int Lista::extraer(int val){
    aux = cabeza;
    if(cabeza == NULL)
        return 0;
    if(aux->val == val){
        cabeza = aux->sig;
        delete(aux);
        return 1;
    }
    if(aux->sig != NULL){
        while(aux->sig->sig != NULL){
            if(aux->sig->val == val){
                aux2 = aux->sig;
                aux->sig = aux2->sig;
                delete(aux2);
                return 1;
            }
            aux = aux->sig;
        }
        if(aux->sig->val == val){
            aux->sig = aux->sig->sig;
            delete(aux->sig);
            return 1;
        }
    }
    return 0;
}
void Lista::mostrarTodo(){
    printf("Mostrar Todo\n");
    aux = cabeza;
    while(aux!=NULL){
        printf("\t%d\n",aux->val);
        aux = aux->sig;
    }
}
