#include <cstdio>
#include <vector>
#include <iostream>
#include "nodo.h"
#include "pila.h"
#include "lista.h"
#include "cola.h"
class NodoEstr{
    public:
        void *val;
        int id_obj;
        int t_obj;
        NodoEstr *ant;
        NodoEstr *sig;
        NodoEstr(){val=NULL;id_obj = 0;t_obj = 0;ant=NULL;sig=NULL;}
        NodoEstr(void* o,int tipo,int id){
            val = o;t_obj = tipo; id_obj = id;ant=NULL;sig=NULL;}
};
class ListaEstr{
    public:
        NodoEstr *cabeza;
        NodoEstr *aux;
        NodoEstr *aux2;
        void insertar(void*,int,int);
        void *buscar(int,int);
        ListaEstr(){cabeza=NULL;aux=NULL;aux2=NULL;}
};
ListaEstr l;
using namespace std;
enum {LISTA=1,PILA,COLA,LDL} estructuras;
vector<Lista*> listas;
vector<Pila*> pilas;
vector<Cola*> colas;
void demostrar(){
    l.insertar(new Lista(),LISTA,1);
    void *tmp = l.buscar(LISTA,1);
    ((Lista*)(tmp))->mostrarTodo();
    Pila *p = new Pila();
    p->mostrar();
    l.insertar(p,PILA,1);
    tmp = l.buscar(PILA,1);
    ((Pila*)(tmp))->mostrar();
}
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
    aux = cabeza->sig;
    while(aux->sig!=NULL){
        if(aux->id_obj == id && aux->t_obj == tipo)
            return aux->val;
        aux = aux->sig;
    }
    if(aux->id_obj == id && aux->t_obj == tipo)
        return aux->val;
    return NULL;
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
                       l.insertar(new Lista(),LISTA,id);
                       printf("Lista #%d creada\n",id);
                   }
                   break;
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
char *mostrar(int obj,int id_obj){
    void *temp = l.buscar(obj,id_obj);
    switch(obj){
        case PILA: return ((Pila*)(temp))->mostrar();
                   break;
        case COLA: return ((Cola*)(temp))->mostrar();
                   break;
        case LISTA:((Lista*)(temp))->mostrarTodo();return NULL;
                   break;
    }
}
int insertar(int obj,int id_obj,char *s){
    void *temp = l.buscar(obj,id_obj);
    //No existe el objeto
    if(temp == NULL){
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
int borrar(int obj,int id_obj){
    switch(obj){
        case PILA: pilas.erase(pilas.begin()+id_obj-1);
                   break;
        case COLA: colas.erase(colas.begin()+id_obj-1);
                   break;
        case LISTA: listas.erase(listas.begin()+id_obj-1);
                    break;
    }
}
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

