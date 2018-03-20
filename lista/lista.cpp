#include <cstdio>
using namespace std;
class Nodo{
    public:
        Nodo *sig;
        int val;
        Nodo(int a){
            val=a;
            sig=NULL;};
};
class Lista{
    public:
        Nodo *cabeza;
        Nodo *aux;
        Nodo *aux2;
        Lista(){cabeza=NULL;aux=NULL;aux2=NULL;};
        void insertar(int);
        void mostrar();
        void extraer();
        void ordenar();
        void insOrd(int);
        void mostrarTodo();
        int tam();
};
void Lista::insertar(int a){
    aux2=new Nodo(a);
    aux=cabeza;
    if(!cabeza){
        cabeza=aux2;
        return;
    }else{
    while(aux->sig!=NULL)
        aux=aux->sig;
    }
    aux->sig=aux2;
}
int Lista::tam(){
    aux=cabeza;
    int i;
    for(i=0;aux!=NULL;i++,aux=aux->sig);
    return i;
}
void Lista::mostrarTodo(){
    printf("Mostrar Todo\n");
    aux=cabeza;
    while(aux!=NULL){
        printf("val:%d\n",aux->val);
        aux=aux->sig;
    }
}
//considerar caso con cabeza=NULL
void Lista::extraer(){
    printf("Extraer:%d\n",cabeza->val);
    aux=cabeza;
    cabeza=cabeza->sig;
    delete(aux);
}
//considerar caso con cabeza=NULL
void Lista::insOrd(int val){
    aux2=new Nodo(val);
    aux = cabeza;
    if(aux->val>aux2->val){
        aux2->sig=aux;
        cabeza=aux2;
        return;
    }
    while((aux2->val)>(aux->sig->val)){
        if(aux->sig->sig==NULL){
            insertar(val);
            return;
        }
        aux = aux->sig;
    }
    aux2->sig=aux->sig;
    aux->sig=aux2;
}
void Lista::ordenar(){
    int temp,s,t;
    for(s=tam()-1;s>0;s--){
        aux=cabeza;
        for(t=s;t>0;t--){
            aux2=aux->sig;
            if(aux->val>aux2->val){
                temp=aux2->val;
                aux2->val=aux->val;
                aux->val=temp;
            }
            aux=aux->sig;
        }
    }
}
int main(){
    Lista l;
    l.ordenar();
    l.mostrarTodo();
    l.insertar(3);
    l.insertar(1);
    l.insertar(25);
    l.insertar(2);
    l.insertar(100);
    l.insertar(21);
    l.mostrarTodo();
    l.ordenar();
    l.mostrarTodo();
    return 0;
}
