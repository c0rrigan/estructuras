#include <cstring>
#include <cstdio>
#include "../utils/cadenas.h"
class NodoD{
    public:
        char *val;
        NodoD *ant;
        NodoD *sig;
        NodoD(){val=NULL;ant=NULL;sig=NULL;}
        NodoD(char* s){val=s;ant=NULL;sig=NULL;}
};
class ListaDoble{
    public:
        NodoD *cabeza;
        NodoD *aux;
        NodoD *aux2;
        void insertar(char*);
        char *mostrar();
        char *extraer();
        void mostrarTodo();
        int tam();
        void ordenar(int);
        void buscar(char*);
        void borrar(char*);
        ListaDoble(){cabeza=NULL;}
};
int ListaDoble::tam(){
    aux = cabeza;
    int i;
    for(i=0;aux!=NULL;i++,aux=aux->sig);
    return i;
}
/*Ordena de menor a mayor(0)
 *Ordena de mayor a menor(1)*/
void ListaDoble::ordenar(int modo){
    char* temp;
    int s,t,comp;
    for(s=tam()-1;s>0;s--){
        aux=cabeza;
        for(t=s;t>0;t--){
            aux2=aux->sig;
            comp = (modo)?!comparaTodo(aux->val,aux2->val):comparaTodo(aux->val,aux2->val);
            if(comp){
                temp=aux2->val;
                aux2->val=aux->val;
                aux->val=temp;
            }
            aux=aux->sig;
        }
    }
}
void ListaDoble::insertar(char *s){
    printf("Insertar:%s\n",s);
    aux = new NodoD(s);
    if(cabeza==NULL){
        cabeza = aux;
        return;
    }
    aux2 = cabeza;
    while(aux2->sig!=NULL)
        aux2 = aux2->sig;
    aux2->sig = aux;
    aux->ant = aux2;
}
char *ListaDoble::extraer(){
    if(cabeza==NULL){
        printf("Vacio\n");
        return NULL;
    }
    printf("Extraer:%s\n",cabeza->val);
    aux = cabeza;
    if(cabeza->sig)
        cabeza->sig->ant = cabeza->ant;
    cabeza = aux->sig;
    delete(aux);
    return NULL;
}
char *ListaDoble::mostrar(){
    if(cabeza==NULL){
        printf("Vacio\n");
        return NULL;
    }
    printf("Mostrar:%s\n",cabeza->val);
    return cabeza->val;
}
void ListaDoble::mostrarTodo(){
    if(cabeza==NULL){
        printf("Vacio\n");
        return;
    }
    aux = cabeza;
    while(aux->sig!=NULL){
        printf("Mostrar:%s\n",aux->val);
        aux = aux->sig;
    }
    printf("Mostrar:%s\n",aux->val);
}
void ListaDoble::buscar(char *s){
    if(cabeza==NULL){
        printf("No hay estructuras\n");
    }
    aux = cabeza;
    while(aux->sig!=NULL){
        if(strcmp(s,aux->val)==0)
            printf("encontrado\n");
        aux = aux->sig;
    }
    if(strcmp(s,aux->val)==0)
        printf("encontrado en el final\n");
}
void ListaDoble::borrar(char *s){
    if(cabeza==NULL){
        printf("No hay estructuras\n");
    }
    aux = cabeza;
    if(strcmp(s,cabeza->val)==0){
        cabeza = cabeza->sig;
        delete(aux);
        return;
    }
    while(aux->sig->sig!=NULL){
        if(strcmp(s,aux->sig->val)==0){
            aux2 = aux->sig;
            aux->sig = aux->sig->sig;
            delete(aux2);
            return;
        }else{
            aux = aux->sig;
        }
    }
    if(strcmp(s,aux->sig->val)==0){
        aux2 = aux->sig;
        aux->sig = aux->sig->sig;
        delete(aux2);
        return;
    }
}
    int main(){
        ListaDoble ld;
        ld.insertar("1234");
        ld.insertar("90.2");
        ld.insertar("9e6");
        printf("%d\n",ld.tam());
        ld.mostrarTodo();
        printf("orden mayor a menor");
        ld.ordenar(1);
        ld.mostrarTodo();
        printf("orden menor a mayor");
        ld.ordenar(0);
        ld.mostrarTodo();
        ld.borrar("9e6");
        //printf("Mostrar todo\n");
        //ld.mostrarTodo();
        ld.borrar("1234");
        //printf("Mostrar todo\n");
        //ld.mostrarTodo();
        ld.borrar("90.2");
        ld.mostrarTodo();
        return 0;
    }
