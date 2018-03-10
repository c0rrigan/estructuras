#include <cstdio>
using namespace std;
class Nodo{
    public:
        int val;
        Nodo *ant;
};
class Cola{
    public:
        Nodo *entrada;
        Nodo *salida;
        Nodo *aux;
    Cola(){
        entrada=NULL;salida=NULL;aux=NULL;}
        void insertar(int);
        void extraer();
        void mostrar();
};
void Cola::insertar(int val){
    aux=new(Nodo);
    aux->val=val;
    if(!salida){
        salida=aux;
        aux->ant=NULL;
    }else{
        aux->ant=entrada->ant;
        entrada->ant=aux;
    }
    entrada=aux;
}
void Cola::extraer(){
    if(salida){
        printf("Extraer :%d\n",salida->val);
        aux=salida->ant;
        delete(salida);
        salida=aux;
    }else{
        printf("Cola vacia\n");
    }
}
void Cola::mostrar(){
    if(salida)
        printf("Mostrar :%d\n",salida->val);
    else
        printf("Vacio\n");
}
int main(){
    Cola c;
    int tmp,op=1;
    do{
        printf("Menu\n1)Insertar\n");
        if(c.salida)
            printf("2)Extraer\n3)Mostrar\n4)Salir\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Insertar número :");
                scanf("%d",&tmp);
                c.insertar(tmp);
                break;
            case 2:
                c.extraer();
                break;
            case 3:
                c.mostrar();
                break;
            case 4:
                op=0;
                break;
            default:
                printf("Opción no válida\n");
        }
    }while(op);
    return 0;
}
