#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include "nodoabin.h"
#include "arb-bin.h"
using namespace std;
//Función que verifica si hay raíz e inicia el proceso de inserción
void ArbolBinario::insertar(Carrera *carr){
    //Verficar si la raíz del arbol esta vacia
    if(raiz == NULL){
        raiz = new NABin(new GpoCarreras(carr->idGrupo));
        raiz->val->carreras.push_back(carr);
        return;
    }
    //Sí el arbol tiene raíz, se usa la función ins
    ins(carr,raiz);
}
/*Función recursiva que inserta 'n' en el nodo adecuado
  dependiendo de 'padre'*/
void ArbolBinario::ins(Carrera *nc,NABin *padre){
    //Si el valor de la nueva carrera es igual, se agrega
    if(nc->idGrupo == padre->val->idGrupo){
        padre->val->carreras.push_back(nc);
        return;
    }
    //Si el valor del nuevo nodo es mayor, se va a la derecha
    if(nc->idGrupo > padre->val->idGrupo){
        //Si el nodo der. de 'padre' esta libre, el nuevo nodo es colocado
        if(padre->der == NULL){
            padre->der = new NABin(new GpoCarreras(nc->idGrupo));
            padre->der->val->carreras.push_back(nc);
            return;
        }else{
            /*Si el nodo der. de 'padre' esta ocupado, vuelve a entrar a la función
              con el nodo derecho de 'padre' como el nuevo 'padre' al entrar a la func.*/
            ins(nc,padre->der);
        }
    }else{
        /*Si el valor nuevo es inferior, se añade a la izquierda con un proceso
          similar al usado en la derecha*/
        if(padre->izq == NULL){
            padre->izq = new NABin(new GpoCarreras(nc->idGrupo));
            padre->izq->val->carreras.push_back(nc);
            return;
        }else{
            ins(nc,padre->izq);
        }
    }
}
//void ArbolBinario::inOrden(NABin *n){
//    if(n == NULL)
//        return;
//    inOrden(n->izq);
//    cout << n->nombre << endl;
//    inOrden(n->der);
//}
//Función de recorrido por niveles
void ArbolBinario::niveles(){
    stack<NABin*> c;
    NABin *aux;
    c.push(raiz);
    while(!c.empty()){
        aux = c.top();
        c.pop();
        cout << aux->val->idGrupo << ",";
        if(aux->izq)
            c.push(aux->izq);
        if(aux->der)
            c.push(aux->der);
    }
}
//Falta hacer mecanismo de busqueda
