#include <cstdio>
#include <vector>
#include <iostream>
#include "nodo.h"
#include "pila.h"
#include "lista.h"
#include "cola.h"
#include "listaestr.h"
ListaEstr l;
using namespace std;
enum {LISTA=1,PILA,COLA,LDL} estructuras;
enum {FINAL=1,MITAD,INICIO} pos;
void *verificar(int obj,int id){
    void *temp = NULL;
    if(obj == LISTA)
        temp = l.buscar(LDL,id);
    if(obj == LDL)
        temp = l.buscar(LISTA,id);
    if(temp)
        printf("Lista ya existe con diferente configuración\n");
    return temp;
}
int nuevo_obj(int obj,int id){
    switch(obj){
        case PILA:{
                      l.insertar(new Pila(),PILA,id);
                      printf("Pila #%d creada\n",id);
                  }
                  break;
        case COLA:{
                      l.insertar(new Pila(),COLA,id);
                      printf("Cola #%d creada\n",id);
                  }
                  break;
        case LISTA:{
                       if(!verificar(obj,id)){
                           l.insertar(new Lista(),LISTA,id);
                           printf("Lista #%d creada\n",id);
                       }
                   }
                   break;
        case LDL:{
                     if(!verificar(obj,id)){
                         //l.insertar(new Lista(),LISTA,id);
                         printf("Lista #%d creada\n",id);
                     }
                 }
    }
}
char *extraer(int obj,int id_obj){
    void *temp = l.buscar(obj,id_obj);
    switch(obj){
        case PILA: return ((Pila*)(temp))->extraer();
                   break;
        case COLA: return ((Cola*)(temp))->extraer();
                   break;
        case LISTA: return ((Lista*)(temp))->extraer();
                    break;
    }
}
void mostrar(int obj,int id_obj){
    void *temp = l.buscar(obj,id_obj);
    switch(obj){
        case PILA: ((Pila*)(temp))->mostrar();
                   break;
        case COLA: ((Cola*)(temp))->mostrar();
                   break;
        case LISTA:((Lista*)(temp))->mostrarTodo();
                   break;
    }
}
int insertar(int obj,int id_obj,char *s){
    void *temp = l.buscar(obj,id_obj);
    //No existe el objeto
    if(temp == NULL){
        if(obj == LISTA || obj == LDL)
            if(verificar(obj,id_obj))
                return 0;
        nuevo_obj(obj,id_obj);
        temp = l.buscar(obj,id_obj);
    }
    switch(obj){
        case PILA: ((Pila*)(temp))->insertar(s);
                   break;
        case COLA: ((Cola*)(temp))->insertar(s);
                   break;
        case LISTA: ((Lista*)(temp))->insertar(s);
                    break;
    }
}
int ins_n(int obj,int id_obj,int n,char **s){
    void *temp = l.buscar(obj,id_obj);
    //No existe el objeto
    if(temp == NULL){
        nuevo_obj(obj,id_obj);
        temp = l.buscar(obj,id_obj);
    }
    switch(obj){
        case PILA:
            for(;n>0;n--){
                ((Pila*)(temp))->insertar(s[n-1]);
            }
            break;
        case COLA:
            for(;n>0;n--){
                ((Cola*)(temp))->insertar(s[n-1]);
            }
            break;
        case LISTA:
            for(;n>0;n--){
                ((Lista*)(temp))->insertar(s[n-1]);
            }
            break;
    }
}
int mostrar_tipo(int obj,int id_obj,int tipo){
    void *temp = l.buscar(obj,id_obj);
    switch(obj){
        //case PILA: return ((Pila*)(temp))->mostrar();
        //           break;
        //case COLA: return ((Cola*)(temp))->mostrar();
        break;
        case LISTA:((Lista*)(temp))->mostrarTipo(tipo);
                   break;
    }
}
//insertar t1 en t2 según pos
int insertar_objs(int t_obj1,int id_obj1,int t_obj2,int id_obj2,int pos){
    void *temp = l.buscar(t_obj2,id_obj2);
    switch(t_obj1){
        case LISTA: printf("tam:%d\n",((Lista*)(temp))->tam());
                    break;
    }
}
void demostrar(){
    insertar(LISTA,1,"snk");
    insertar(LDL,1,"snk");
}
//int borrar(int obj,int id_obj){
//    switch(obj){
//        case PILA: pilas.erase(pilas.begin()+id_obj-1);
//                   break;
//        case COLA: colas.erase(colas.begin()+id_obj-1);
//                   break;
//        case LISTA: listas.erase(listas.begin()+id_obj-1);
//                    break;
//    }
//}
/*Ordena de menor a mayor(0)
 *Ordena de mayor a menor(1)*/
int ordenar(int obj,int id_obj,int orden){
    void *temp = l.buscar(obj,id_obj);
    switch(obj){
        //case PILA: return ((Pila*)(temp))->mostrar();
        //           break;
        //case COLA: return ((Cola*)(temp))->mostrar();
        break;
        case LISTA:((Lista*)(temp))->ordenar(orden);
                   break;
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

