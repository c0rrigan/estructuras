#include <cstdio>
#include "punto.h"
#include "load.h"
#include "pila.h"
//Definiciones de caracteres
#define CAM '.'
#define PAR '1'
#define SAL 'S'
#define ENT 'E'
#define RUT '+'
Pila lpt;//Estructura para almacenar pasos
Matrix *mapa;//Mapa del laberinto

void print_matrix(Matrix *mtr){
    int i,j = i = 0;
    for(;i<mtr->m;i++){
        for(;j<mtr->n;j++){
            printf("%c",mtr->data[i][j]);
        }
        j = 0;
        printf("\n");
    }
}
Punto *busc_inicio(Matrix *mapa){
    int i,j;
    for(i = 0;i < mapa->m;i++){
        for(j = 0;j< mapa->n;j++){
            if(mapa->data[i][j] == ENT)
                return new Punto(j,i);
        }
    }
}
Punto *camina(Punto *p){
    Punto *pret;
    //Arriba hay camino
    if(mapa->data[p->y-1][p->x] == CAM && !lpt.mostrar()->comp(p->x,p->y-1)){
        lpt.insertar(p);
        pret = camina(new Punto(p->x,p->y-1));
        if(!pret->vacio()){
            return pret;
        }
    }
    //Abajo hay camino
    if(mapa->data[p->y+1][p->x] == CAM && !lpt.mostrar()->comp(p->x,p->y+1)){
        lpt.insertar(p);
        pret = camina(new Punto(p->x,p->y+1));
        if(!pret->vacio()){
            return pret;
        }
    }
    //Izquierda hay camino
    if(mapa->data[p->y][p->x-1] == CAM && !lpt.mostrar()->comp(p->x-1,p->y)){
        lpt.insertar(p);
        pret = camina(new Punto(p->x-1,p->y));
        if(!pret->vacio()){
            return pret;
        }
    }
    //Derecha hay camino
    if(mapa->data[p->y][p->x+1] == CAM && !lpt.mostrar()->comp(p->x+1,p->y)){
        lpt.insertar(p);
        pret = camina(new Punto(p->x+1,p->y));
        if(!pret->vacio()){
            return pret;
        }
    }
    //Arriba hay salida
    if(mapa->data[p->y-1][p->x] == SAL){
        lpt.insertar(p);
        return new Punto(p->x,p->y-1);
    }
    //Abajo hay salida
    if(mapa->data[p->y+1][p->x] == SAL){
        lpt.insertar(p);
        return new Punto(p->x,p->y+1);
    }
    //Izquierda hay salida
    if(mapa->data[p->y][p->x-1] == SAL){
        lpt.insertar(p);
        return new Punto(p->x-1,p->y);
    }
    //Derecha hay salida
    if(mapa->data[p->y][p->x+1] == SAL){
        lpt.insertar(p);
        return new Punto(p->x+1,p->y);
    }
    lpt.extraer();
    return new Punto();
}

int main(int argc,char *argv[]){
    if(argc == 2){
        mapa = load_matrix(argv[1]);
    }else{
        mapa = load_matrix("mapa");
    }
    Punto *ent = busc_inicio(mapa);
    lpt.insertar(ent);
    camina(ent);
    Punto *p;
    while(p = lpt.mostrar()){
        mapa->data[p->y][p->x] = RUT;
        lpt.extraer();
    }
    print_matrix(mapa);
    return 0;
}
