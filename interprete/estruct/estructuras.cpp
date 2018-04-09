#include <cstdio>
#include <vector>
#include <iostream>
#include "nodo.h"
#include "pila.h"
#include "lista.h"
#include "cola.h"
using namespace std;
enum {LISTA=1,PILA,COLA} estructuras;
vector<Lista*> listas;
vector<Pila*> pilas;
vector<Cola*> colas;
int existe(int x){
    return x>0 && (x <= listas.size() || x <= colas.size() || x <= pilas.size());
}

int nuevo_obj(int obj){
    switch(obj){
        case PILA:{
            pilas.insert(pilas.end(),new Pila());
            printf("Pila #%d creada\n",pilas.size());
        }
        break;
        case COLA:{
            colas.insert(colas.end(),new Cola());
            printf("Cola #%d creada\n",colas.size());
        }
        break;
        case LISTA:{
            listas.insert(listas.end(),new Lista());
            printf("Lista #%d creada\n",listas.size());
        }
        break;
    }
}
char *extraer(int obj,int id_obj){
    if(existe(id_obj)){
        switch(obj){
            case PILA: return pilas[id_obj-1]->extraer();
            break;
            case COLA: return colas[id_obj-1]->extraer();
            break;
            case LISTA: return listas[id_obj-1]->extraer();
            break;
        }
    }
}
char *mostrar(int obj,int id_obj){
    if(existe(id_obj)){
        switch(obj){
            case PILA: return pilas[id_obj-1]->mostrar();
            break;
            case COLA: return colas[id_obj-1]->mostrar();
            break;
            case LISTA:listas[id_obj-1]->mostrarTodo();return NULL;
            break;
        }
    }
}
int insertar(int obj,int id_obj,char *s){
    if(existe(id_obj)){
        switch(obj){
            case PILA: pilas[id_obj-1]->insertar(s);
            break;
            case COLA: colas[id_obj-1]->insertar(s);
            break;
            case LISTA: listas[id_obj-1]->insertar(s);
            break;
        }
    }else{
        printf("No se pudo completar la operación");
    }
}
int ins_n(int obj,int id_obj,int n,char **s){
    if(existe(id_obj)){
        switch(obj){
            case PILA: 
                for(;n>0;n--){
                    pilas[id_obj-1]->insertar(s[n-1]);
                }
            break;
            case COLA: 
                for(;n>0;n--){
                    colas[id_obj-1]->insertar(s[n-1]);
                }
            break;
            case LISTA:
                for(;n>0;n--){
                    listas[id_obj-1]->insertar(s[n-1]);
                }
            break;
        }
    }else{
        printf("No se pudo completar la operación\n");
    }
}
int borrar(int obj,int id_obj){
    if(existe(id_obj)){
        switch(obj){
            case PILA: pilas.erase(pilas.begin()+id_obj-1);
            break;
            case COLA: colas.erase(colas.begin()+id_obj-1);
            break;
            case LISTA: listas.erase(listas.begin()+id_obj-1);
            break;
        }
    }
}
int anexar(int obj1,int id_obj1,int obj2,int id_obj2){
    char *temp;
    while((temp = extraer(obj1,id_obj1))!=NULL){
        printf("extraer :%s\n",temp);
        insertar(obj2,id_obj2,temp);
    }

}
//int main(){
//    char s[] = "tigre";
//    nuevo_obj(COLA);
//    printf("existe:%d",existe(1));
//    insertar(COLA,1,s);
//    cout << extraer(COLA,1) << endl;
//    cout << mostrar(COLA,1) << endl;
//    return 0;
//}

