#ifndef LISTAESTR_H
#define LISTAESTR_H
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
#endif
