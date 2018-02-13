#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "load.h"
#include "puntos.h"

int CENTROIDES=3;
char *s = "file.csv";
int main(int argc,char *argv[]){
    //Estructura para argumentos -v
    if(argc>1&&argv[1][0]=='-'){
        printf("%c",argv[1][1]);
        switch(argv[1][1]){
            case 'f':
                s=argv[2];
                break;
        }

    }
    Matriz *mtr=matriz(s);
    printf("m=%d,n=%d\n",mtr->m,mtr->n);
    int a,b;
    for(a=0;a<mtr->m;a++){
        for(b=0;b<mtr->n;b++){
            printf("%05.2f\t",mtr->data[a][b]);
        }
        printf("\n");
    }

    centroides(mtr,3);

    return 0;
}
