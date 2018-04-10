#include <cstdio>
#include <cstdlib>
#include "nodo.h"
#include <cstring>
#include "../utils/cadenas.h"
#include "lista.h"
using namespace std;
//Nodo::Nodo(char *s){val = s;rel = NULL;}
//Lista::Lista(){cabeza=NULL;aux=NULL;aux2=NULL;}

void Lista::insertar(char *a){
    aux2 = new Nodo(a);
    aux = cabeza;
    if(!cabeza){
        cabeza = aux2;
        return;
    }else{
    while(aux->rel!=NULL)
        aux = aux->rel;
    }
    aux->rel = aux2;
}
int Lista::tam(){
    aux=cabeza;
    int i;
    for(i=0;aux!=NULL;i++,aux=aux->rel);
    return i;
}
//par(2),impar 1
void Lista::mostrarTipo(int tipo){
    printf("Mostrar Tipo\n");
    aux = cabeza;
    int temp,mod = 2-tipo;
    while(aux!=NULL){
        temp = atoi(aux->val);
        if(temp%2==mod)
            printf("\t-%s\n",aux->val);
        aux = aux->rel;
    }
}
void Lista::mostrarTodo(){
    printf("Mostrar Todo\n");
    aux = cabeza;
    while(aux!=NULL){
        printf("\t-%s\n",aux->val);
        aux = aux->rel;
    }
}
//considerar caso con cabeza=NULL
char *Lista::extraer(){
    if(!cabeza){
        return NULL;
    }else{
        char *tmp = (char*)malloc((strlen(cabeza->val)+1)*sizeof(char));
        strcpy(tmp,cabeza->val);
        aux = cabeza;
        cabeza = cabeza->rel;
        delete(aux);
        return tmp;
    }
}
char *Lista::mostrar(){
    if(!cabeza){
        return NULL;
    }else{
        return cabeza->val;
    }
}
/*Ordena de menor a mayor(0)
 *Ordena de mayor a menor(1)*/
void Lista::ordenar(int modo){
    char* temp;
    int s,t,comp;
    for(s=tam()-1;s>0;s--){
        aux=cabeza;
        for(t=s;t>0;t--){
            aux2=aux->rel;
            comp = (modo)?!comparaTodo(aux->val,aux2->val):comparaTodo(aux->val,aux2->val);
            if(comp){
                temp=aux2->val;
                aux2->val=aux->val;
                aux->val=temp;
            }
            aux=aux->rel;
        }
    }
}
//int main(){
//    Lista l;
//    l.insertar("18");
//    l.insertar("1");
//    l.insertar("120");
//    l.insertar("192.0e2");
//    l.insertar("ab");
//    l.insertar("ac");
//    l.mostrarTodo();
//    l.ordenar(1);
//    l.mostrarTodo();
//}
//considerar caso con cabeza=NULL
//-----Pendiente de adaptación para soporte de caracteres
//void Lista::insOrd(char *val){
//    aux2=new Nodo(val);
//    aux = cabeza;
//    if(aux->val>aux2->val){
//        aux2->rel=aux;
//        cabeza=aux2;
//        return;
//    }
//    while((aux2->val)>(aux->rel->val)){
//        if(aux->rel->rel==NULL){
//            insertar(val);
//            return;
//        }
//        aux = aux->rel;
//    }
//    aux2->rel=aux->rel;
//    aux->rel=aux2;
//}
