#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "nodo.h"
#include "nodocola.h"
#include "cola.h"
class ArbolBinario{
    void ins(Nodo*,Nodo*);
    public:
        Nodo *raiz;
        void insertar(int);
        void inOrden(Nodo *n);
        void preOrden(Nodo *n);
        void postOrden(Nodo *n);
        void niveles();
        ArbolBinario(){
            raiz = NULL;
        }
};
using namespace std;
//Función que verifica si hay raíz e inicia el proceso de incerción
void ArbolBinario::insertar(int valor){
    //Verficar si la raíz del arbol esta vacia
    if(raiz == NULL){
        raiz = new Nodo(valor);
        return;
    }
    //Sí el arbol tiene raíz, se usa la función ins
    ins(new Nodo(valor),raiz);
}
/*Función recursiva que inserta 'n' en el nodo adecuado
dependiendo de 'padre'*/
void ArbolBinario::ins(Nodo *n,Nodo *padre){
    //Si el valor del nuevo nodo es mayor, se va a la derecha
    if(n->valor > padre->valor){
        //Si el nodo der. de 'padre' esta libre, el nuevo nodo es colocado
        if(padre->der == NULL)
            padre->der = n;
        else
        /*Si el nodo der. de 'padre' esta ocupado, vuelve a entrar a la función
        con el nodo derecho de 'padre' como el nuevo 'padre' al entrar a la func.*/
        ins(n,padre->der);
    }else{
        /*Si el valor nuevo es inferior, se añade a la izquierda con un proceso
        similar al usado en la derecha*/
        if(padre->izq == NULL)
            padre->izq = n;
        else
            ins(n,padre->izq);
    }
}
//Función recursiva que recorre el arbol en preOrden(P,I,D)
void ArbolBinario::preOrden(Nodo *n){
    if(n == NULL)
        return;
    printf("%d,",n->valor);
    preOrden(n->izq);
    preOrden(n->der);
}
//Función recursiva que recorre el arbol en inOrden(I,P,D)
void ArbolBinario::inOrden(Nodo *n){
    if(n == NULL)
        return;
    inOrden(n->izq);
    printf("%d,",n->valor);
    inOrden(n->der);
}
//Función recursiva que recorre el arbol en postOrden(I,D,P)
void ArbolBinario::postOrden(Nodo *n){
    if(n == NULL)
        return;
    postOrden(n->izq);
    postOrden(n->der);
    printf("%d,",n->valor);
}
//Función de recorrido por niveles
void ArbolBinario::niveles(){
    Cola c;
    Nodo *aux;
    c.insertar(raiz);
    while((aux = c.extraer())){
        cout << aux->valor << ",";
        if(aux->izq)
            c.insertar(aux->izq);
        if(aux->der)
            c.insertar(aux->der);
    }
}
int main(){
    ArbolBinario ab;
    int num = 0;
    for(;;){
        cin >> num;
        if(num == -1)
            break;
        ab.insertar(num);
    }
    cout << "Pre Orden:" << endl;
    ab.preOrden(ab.raiz);
    cout << "\nIn Orden:" << endl;
    ab.inOrden(ab.raiz);
    cout << "\nPost Orden:" << endl;
    ab.postOrden(ab.raiz);
    cout << "\nNiveles:" << endl;
    ab.niveles();
    cout << endl;
    return 0;
}
