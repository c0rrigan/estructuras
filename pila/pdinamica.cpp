#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#include <stdio.h>
using namespace std;
class Nodo{
    public:
        int datos;
        Nodo *anterior;
};
class Pila{
    public:
        Nodo *aux;
        Nodo *pos;
    Pila(){
        pos=new(Nodo); 
        pos->anterior=pos;
    }
    void insertar(int);
    void extraer();
    void mostrar();
};
void Pila::insertar(int datos){
    aux=new(Nodo);
    aux->datos=datos;
    aux->anterior=pos;
    pos=aux;
}
void Pila::extraer(){
    if(pos->anterior==pos){
        printf("%sNo hay elementos%s\n",KRED,KNRM);
    }else{
        printf("Extrayendo:%d\n",pos->datos);
        aux=pos;
        pos=pos->anterior;
        delete(aux);

    }
}
void Pila::mostrar(){
    if(pos->anterior==pos){
        printf(KRED"No hay elementos\n" KNRM);
    }else{
        printf("Mostrar:%d\n",pos->datos);
    }
}
int main(){
    int continuar = 1;
    int temp,op=0; 
    Pila p;
    do{
        printf("Elegir operacion:\n1)Insertar \n2)Extraer \n3)Mostrar \n4)Salir\n");
        scanf("%d",&op);
        switch(op){
            case 1: 
                printf("Introducir número :");
                scanf("%d",&temp);
                p.insertar(temp); 
            break;
            case 2: 
                p.extraer();
            break;
            case 3: 
                p.mostrar();
            break;
            case 4:
                continuar=0;
            break;
        }
    }while(continuar);
}
