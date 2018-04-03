#include <cstdlib>
#include <cstdio>
#include <cctype>
/*Función que cambia una cadena 's' con terminador '\0' a letras mayusculas*/
void mayusculas(char *s){
    while(*s!='\0')
        *(s++)=toupper(*s);
}
/* Parte la cadena 's' en diferentes cadenas, una por cada ocurrencia
 * u ocurrencias de espacios
 * Argumentos:
 * -s:cadena ingresada por el usuario
 * Regresa:
 *  -un arreglo de punteros 't' de tipo char a diferentes partes de 's',
 *  que *t[-1] contiene el número de cadenas que contiene
 */
unsigned char **partir(unsigned char *s){
    int i,j,k,espacios;i=j=k=espacios=0;
    unsigned char **tor,**t;
    while(s[i]!='\0'){
        if(s[i++]==' '){
            espacios++;
            while(s[i++]==' ');
        }
    }
    tor=(unsigned char**)calloc(espacios+2,sizeof(char*));
    tor[0]=(unsigned char*)calloc(1,sizeof(char));
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
/*Función que verifica si un char* es un número entero
 * o decimal con notación científica e.g. 3e-4 */
int esnum(unsigned char *s){
    while(*s!='\0'){
        if((*s!='e' && *s!='-' && *s!='.') && (*s > '9' || *s < '0')){
            return 0;
        }
        s++;
    }
    return 1;
}
/*Regresa la secuencía de números que se encuetra dentro
 * de la cadena *s, de existir alguna*/
int rem_nums(unsigned char *s){
    int i=0;
    char buff[8];//Buffer de digitos
    while(*s!='\0'){
        if(*s>='0' && *s <= '9'){
            buff[i++] = *s;
            *s = '\0';
        }
        s++;
    }
    buff[i]='\0';
    return (i>0)?atoi(buff):i;
};
