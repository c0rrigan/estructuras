#include <cstdlib>
#include <cstdio>
#include "listaestr.h"
void ListaEstr::insertar(void *o,int tipo,int id){
    aux = new NodoEstr(o,tipo,id);
    if(cabeza == NULL){
        cabeza = aux;
        return;
    }
    aux2 = cabeza;
    while(aux2->sig!=NULL)
        aux2 = aux2->sig;
    aux2->sig = aux;
    aux->ant = aux2;
}
void *ListaEstr::buscar(int tipo,int id){
    if(cabeza==NULL){
        printf("No hay estructuras\n");
        return NULL;
    }
    if(cabeza->id_obj == id && cabeza->t_obj == tipo)
        return cabeza->val;
    aux = cabeza;
    while(aux->sig!=NULL){
        if(aux->id_obj == id && aux->t_obj == tipo)
            return aux->val;
        aux = aux->sig;
    }
    if(aux->id_obj == id && aux->t_obj == tipo)
        return aux->val;
    return NULL;
}
