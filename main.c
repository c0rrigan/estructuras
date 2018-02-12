#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"
#include "puntos.h"

int CENTROIDES=2;

int main(int argc,char *argv[]){
    //Estructura para argumentos -v
    //if(argc>1&&(*++argv)[0]=='-'){
    //    printf("verbose");
    //}
    Matriz *mtr=matriz("file.csv"); 
    centroides();
    //printf("m=%d,n=%d\n",mtr->m,mtr->n);  
    //int a,b;
    //for(a=0;a<mtr->m;a++){
    //    for(b=0;b<mtr->n;b++){
    //        printf("%d\t",mtr->data.idata[a][b]);
    //    }
    //    printf("\n");
    //}
    

    return 0;
}
