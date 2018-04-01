#include <iostream>
#include <ctype.h>
#include "nodo.h"
#include "cola.h"
#include "pila.h"
#include "lista.h"
extern "C"{
    #include "datos.h"
}
using namespace std;
int inicializar(){
    FILE *fconfig = fopen("config","r");
    if(!fconfig){
        printf("Archivo de configuración no encontrado\nCreando archivo de configuracion...");
    fconfig=fopen("config","rw+");
    }
}
/* Parte la cadena 's' en diferentes cadenas, una por cada ocurrencia
 * u ocurrencias de espacios
 * Argumentos:
 * -s:cadena ingresada por el usuario
 * Regresa:
 *  -un arreglo de punteros 't' de tipo char a diferentes partes de 's',
 *  que *t[-1] contiene el número de cadenas que contiene
 */
char **partir(char *s){
    int i,j,k,espacios;i=j=k=espacios=0;
    char **tor,**t;
    while(s[i]!='\0')
        if(s[i++]==' '){
            espacios++;
            while(s[++i]==' ');
        }
    tor=(char**)calloc(espacios+2,sizeof(char*));
    tor[0]=(char*)calloc(1,sizeof(char));
    tor[0][0]=espacios+1;
    t=tor+1;
    i=0;
    for(;s[i]!='\0';i++){
        if(s[i]==' '){
            s[i]='\0';
            t[k++]=s+j;
            while(s[++i]==' ');
            j=i;
        }
    }
    t[k]=&(s[j]);
    return t;
}
/* Cambia a minusculas la cadena 's'
 */
void mayusculas(char *s){
    while(*s!='\0')
        *(s++)=tolower(*s);
}
int buscar(char *s){
    
}

/*Determina el tipo de operación que se va a realizar dependiendo
 * de la primera frase i.e. s[0], y se invoca a la función
 * correspondiente
 * Argumentos:
 * -s: es el comando ingresado por el usuario dividido en
 *     partes, una por cada espacio o espacios
 */
void asignar(char **s){
    mayusculas(s[0]);
}
int main(){
    //cargar_datos();
    return 0;
}
