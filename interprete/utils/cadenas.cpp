#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
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
char **partir(char *s){
    int i,j,k,espacios;i=j=k=espacios=0;
    char **tor,**t;
    while(s[i]!='\0'){
        if(s[i++]==' '){
            espacios++;
            while(s[i++]==' ');
        }
    }
    //se apartan 'espacios+2' espacios de memoria para guardar el tamaño
    //en la primera posición
    tor=(char**)calloc(espacios+2,sizeof(char*));
    tor[0]=(char*)calloc(1,sizeof(char));
    tor[0][0]=espacios+1;
    t=tor+1;
    for(i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            s[i]='\0';
            t[k++]=s+j;
            while(s[++i]==' ');
            j=i;
        }
    }
    s[i-1]='\0';
    t[k]=&(s[j]);
    return t;
}
/*Función que verifica si un char* es un número entero
 * o decimal con notación científica e.g. 3e-4 */
int esnum(char *s){
    int ret = 0;
    while(*s!='\0'){
        if((*s!='e' && *s!='-' && *s!='.') && (*s > '9' || *s < '0')){
            return ret;
        }
        s++;
        if(*s=='e' || *s=='.')
            ret = 1;
    }
    return ret+1;
}
/*Regresa la secuencía de números que se encuetra dentro
 * de la cadena *s, de existir alguna*/
int rem_nums(char *s){
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
}
/*Convierte las cadenas 'a' y 'b' y las compara, considerando que
 * pueden ser números enteros y decimales así como cadenas simples,
 * en este caso, el resultado de la comparación esta dado por el 
 * orden lexicográfico de las cadenas*/
int comparaTodo(char *a,char *b){
    int tipo_a,tipo_b;
    tipo_a = esnum((char*)a);
    tipo_b = esnum((char*)b);
    if(tipo_a == 0){
        if(tipo_b == 0)
            return (strcmp(a,b)>0)?1:0;
        else
            return 0;
    }
    if(tipo_b == 0){
            return 1;
    }
    if(tipo_a == 1){
        if(tipo_b == 2)
            return atof(a)>atof(b);
        else
            return atoi(a)>atoi(b);
    }
    if(tipo_a == 2){
        if(tipo_b == 1)
            return atof(a)>atof(b);
        else
            return atoi(a)>atoi(b);
    }
}
char *copiar(char *s){
    int n = strlen(s)+1;
    char *ret = (char*)malloc(n*sizeof(char));
    strcpy(ret,s);
    return ret;
}
