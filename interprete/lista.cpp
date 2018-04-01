#include <cstdio>
using namespace std;
#include "nodo.h"
#include "lista.h"
//Nodo::Nodo(char *s){val = s;rel = NULL;}
Lista::Lista(){cabeza=NULL;aux=NULL;aux2=NULL;}

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
void Lista::mostrarTodo(){
    printf("Mostrar Todo\n");
    aux = cabeza;
    while(aux!=NULL){
        printf("\t-%s\n",aux->val);
        aux = aux->rel;
    }
}
//considerar caso con cabeza=NULL
void Lista::extraer(){
    if(!cabeza){
        printf("Vacio\n");
    }else{
        printf("Extraer:%s\n",cabeza->val);
        aux = cabeza;
        cabeza = cabeza->rel;
        delete(aux);
    }
}
void Lista::mostrar(){
    if(!cabeza){
        printf("Vacio\n");
    }else{
        printf("Mostrar:%s\n",cabeza->val);
    }
}
//int main(){
//    Lista l;
//    l.extraer();
//    l.mostrar();
//    l.insertar("nortec");
//    l.mostrar();
//    l.insertar("revolución");
//    l.insertar("consciencia");
//    printf("tamaño:%d\n",l.tam());
//    l.mostrarTodo();
//    l.mostrar();
//    l.extraer();
//    l.extraer();
//    l.extraer();
//    l.extraer();
//    printf("tamaño:%d\n",l.tam());
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
//void Lista::ordenar(){
//    int temp,s,t;
//    for(s=tam()-1;s>0;s--){
//        aux=cabeza;
//        for(t=s;t>0;t--){
//            aux2=aux->rel;
//            if(aux->val>aux2->val){
//                temp=aux2->val;
//                aux2->val=aux->val;
//                aux->val=temp;
//            }
//            aux=aux->rel;
//        }
//    }
//}
