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
void Lista::mostrarTodo(){
    printf("Mostrar Todo\n");
    aux=cabeza;
    while(aux->sig!=NULL){
        printf("val:%d\n",aux->val);
        aux=aux->sig;
    }
    printf("val:%d\n",aux->val);
}
void Lista::extraer(){
    printf("Extraer:%d\n",cabeza->val);
    aux=cabeza;
    cabeza=cabeza->sig;
    delete(aux);
}
int main(){
    Lista l;
    l.insertar(23);
    l.insertar(24);
    l.mostrarTodo();
    l.insertar(25);
    l.extraer();
    l.mostrarTodo();
    l.insertar(26);
    l.extraer();
    l.mostrarTodo();
    l.insertar(27);
    return 0;
}
