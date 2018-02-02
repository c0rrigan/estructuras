/*
 * Nava López Sebastián
 * Estructuras de Datos
 *
 * Programa que lee un archivo .csv el cual es el primer agrgumento del programa
 * y lo imprime
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    char c;
    FILE *f = fopen(argv[1],"r");
    while((c=getc(f))!=EOF){
        if(c==',')
            printf("\t");
        else
            printf("%c",c);
    }
    printf("\n");
}
