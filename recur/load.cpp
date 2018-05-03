/*
 * Nava López Sebastián
 * Estructuras de Datos
 *
 * Programa que lee un archivo .csv el cual es el primer agrgumento del programa
 * y lo imprime
 */
#include <stdio.h>
#include <stdlib.h>
#include "load.h"
    
char **iniciar_fmatriz(int,int);
char **crea_matriz(int,int,FILE*);
Matrix *load_matrix(char *s){
    Matrix *mtr=(Matrix*)calloc(1,sizeof(Matrix));
    int i,m,n=i=m=0;
    char c;
    FILE *f = fopen(s,"r");
    /**
     * En este primer recorrido del archivo se detecta el número máximo de
     * caracteres en cada fila, así como la presencia de números decimales
     * en tal caso se activa la bandera 'PRES'
     */
    while((c=getc(f))!=EOF){
        i++;
        if(c=='\n'){
            m++;
            n=(i>n)?i:n;
            i=0;
        }
    }
    rewind(f);
    mtr->m=m;
    mtr->n=n;
    mtr->data=crea_matriz(m,n,f);
    return mtr;
}
/**
 * Crea una matriz m*n de tipo float o int dependiendo si la bandera 'PRES'
 * es activada en el primer recorrido al archivo
 */
char **crea_matriz(int m,int n,FILE *f){
    unsigned int j,k,i=k=j=0;
    char c;
    char **mtr=iniciar_fmatriz(m,n);
    while((c=getc(f))!=EOF){
        if(c =='\n'){
            j++;
            i = 0;
        }else{
            mtr[j][i] = c; 
            i++;
        }
    }
    return mtr;
}
char **iniciar_fmatriz(int m,int n){
    char **mtr=(char**)calloc(m,sizeof(char*));
    --m;
    for(;m>=0;--m){
        char *num=(char*)calloc(n,sizeof(char));
        mtr[m]=num;
    }
    return mtr;
}
