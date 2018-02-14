#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"
#include "puntos.h"

int CENTROIDES=2;
char *s = "datos.csv";
int main(int argc,char *argv[]){
    //Estructura para argumentos -f
    if(argc>1&&argv[1][0]=='-'){
        switch(argv[1][1]){
            case 'f':
                s=argv[2];
                break;
        }

    }
    Matriz *mtr=matriz(s);
    printf("Dimensiones\n");
    printf("m=%d,n=%d\n",mtr->m,mtr->n);
    int a,b;
    printf("Datos\n");
    for(a=0;a<mtr->m;a++){
        for(b=0;b<mtr->n;b++){
            printf("%.2f\t",mtr->data[a][b]);
        }
        printf("\n");
    }

    centroides(mtr,CENTROIDES);

    return 0;
}
