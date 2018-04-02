#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "cadenas.h"
#include "nodo.h"
#include "cola.h"
#include "pila.h"
#include "lista.h"
extern "C"{
#include "datos.h"
#define BUFF_C 16
}
enum {INSERTAR,MOSTRAR,EXTRAER,ANEXAR,ORDENAR,OBJETOS,UNIDADES} OP_ID;
using namespace std;
/*Generar arreglo de enteros 'n' enteros con el tamaño en *(n-1)*/
unsigned char **n_arr(int n){
    unsigned char **nums = (unsigned char**)calloc(n+1,sizeof(char*));
    for(--n;n>=0;n--)
        nums[n] = (unsigned char*)calloc(BUFF_C,sizeof(char));
    return nums;
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
unsigned char **gen_nums(int n,int tipo,int orden){
    int aumento = (tipo) ? 2 : 3;
    unsigned char **nums = n_arr(n);
    int temp;
    if(orden){
        for(--n;n >= 0;n--){
            temp = ((temp = rand()%10000)%aumento==0)?temp:temp-temp%aumento;
            sprintf((char*)*(nums+n),"%d",temp);
        }
    }else{
        temp=rand()%10000;
        for(--n;n >= 0;n--){
            temp += aumento;
            sprintf((char*)*(nums+n),"%d",temp);
        }
    }
    return nums;
}
//Retorna un arreglo de números de acuerdo a los modificadores detectados en args
//a partir de args[in]
unsigned char **nums(unsigned char **args,int in,int n){
    //Asumimos que el número de elementos es el número anterior
    //a la unidad
    int orden = 0;//por defecto el orden es consecutivo(0),aleatorio es 1
    int tipo = 0;//por impar(0),par(1)
    for(in++; in < **(args-1)-1;in++){
        mayusculas((char*)args[in]);
        if(strcmp((char*)args[in],"ALEATORIOS")==0){
            orden = 1;
            continue;
        }
        if(strcmp((char*)args[in],"PARES")==0){
            tipo = 1;
            continue;
        }
    }
    printf("numeros\nORDEN:%d ,TIPO:%d",orden,tipo);
    return gen_nums(n,tipo,orden);
}
/*Insertar N número con los modificadores necesarios al objeto*/
int insertar_n(unsigned char **args,int in,int obj,int id_obj){
    int n = atoi((char*)args[in-1]);
    unsigned char **ins = nums(args,in,n);
    Lista l;
    for(--n; n >= 0; n--)
        l.insertar((char*)*(ins+n));
    l.mostrarTodo();
}
//Retorna el tipo de objeto que tiene la cadena,
//notar que ya no debe de contar con el identificador al final
int busc_obj(unsigned char **args){
    /*Desconocido(0),Lista(1),Pila(2),Cola(3)*/
    int obj = 0;
    mayusculas((char*)args[**(args-1)-1]);
    if(busc_op(args[**(args-1)-1],OPH)==OBJETOS){
        if(strcmp((char*)args[**(args-1)-1],"LISTA")==0)
            obj = 1;
        else if(strcmp((char*)args[**(args-1)-1],"PILA")==0)
            obj = 2;
        else
            obj = 3;
    }
    return obj;
}
int asig_ins(unsigned char **args,int in){
    for(in++;in < **(args-1); in++){
        //insertar n UNIDADES $mod1 $mod2 en #obj
        if(busc_op(args[in],OPH)==UNIDADES){
            int id_o = rem_nums(args[**(args-1)-1]);
            int obj = busc_obj(args);
            if(obj)
                insertar_n(args,in,obj,id_o);
                //printf("ins%d elementos #id elem:%d, obj:%d\n",n,ne,id_obj);
            break;
        }else{
            mayusculas((char*)args[in]);
            if(strcmp((char*)args[in],"EN")==0){
                printf("insert simple");
                    break;
            }
        }
    }
}
int asig_ins(unsigned char *,unsigned char **s){

}
int insertar(unsigned char **s){
    printf("func:%s\n",*s);
    int i,temp = 0;
    for(i = 1;i < **(s-1);i++){
        //Insertar n ...
        if(esnum(s[i])){
            printf("es número,pos:%d\n",i);
            asig_ins(s,i);
            break;
        }else{
            //Insertar ... obj ...
            if(rem_nums(s[i])){
                printf("s:%s,pos:%d\n",s[i],i);
                break;
            }
        }
    }
}
void asignar(unsigned char **s){
    int n = busc_op(s[0],OPH);
    switch(n){
        case 0: insertar(s); break;
        //case 1: //mostra break;
        //case 2: //extrae break;
        //case 3: //anexa break;
        //case 4: //ordena break;
    }
}

int main(){
    cargar_datos();
    unsigned char s[] = "insertar   2   numeros  en  la lista1";
    unsigned char s2[] = "insertar en lista1 15 números aleatorios";
    unsigned char **sp = partir(s);
    asignar(sp);
    return 0;
}
