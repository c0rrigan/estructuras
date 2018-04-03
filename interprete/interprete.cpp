#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "cadenas.h"
#include "estructuras.h"
extern "C"{
#include "datos.h"
}
#define BUFF_C 16
enum {INSERTAR,MOSTRAR,EXTRAER,ANEXAR,ORDENAR,OBJETOS,UNIDADES,LIMPIAR,CREAR,SALIR} OP_ID;
using namespace std;
/*Generar arreglo de enteros 'n' enteros con el tamaño en *(n-1)*/
unsigned char **n_arr(int n){
    unsigned char **nums = (unsigned char**)calloc(n+1,sizeof(char*));
    for(--n;n>=0;n--)
        nums[n] = (unsigned char*)calloc(BUFF_C,sizeof(char));
    return nums;
}
unsigned char **gen_nums(int n,int tipo,int orden){
    int aumento = 2;
    unsigned char **nums = n_arr(n);
    int temp;
    if(orden){
        if(tipo){
            for(--n;n >= 0;n--){
                temp = ((temp = rand()%10000)%aumento==0)?temp:temp+1;
                sprintf((char*)*(nums+n),"%d",temp);
            }
        }else{
            for(--n;n >= 0;n--){
                temp = ((temp = rand()%10000)%aumento==1)?temp:temp+1;
                sprintf((char*)*(nums+n),"%d",temp);
            }
        }
    }else{
        if(tipo){
            temp = ((temp = rand()%10000)%aumento==0)?temp:temp-1;
            for(--n;n >= 0;n--){
                temp += aumento;
                sprintf((char*)*(nums+n),"%d",temp);
            }
        }else{
            for(--n;n >= 0;n--){
                temp = ((temp = rand()%10000)%aumento==1)?temp:temp+1;
                sprintf((char*)*(nums+n),"%d",temp);
            }
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
    printf("numeros\nORDEN:%d ,TIPO:%d\n",orden,tipo);
    return gen_nums(n,tipo,orden);
}
/*Insertar N número con los modificadores necesarios al objeto*/
int insertar_n(unsigned char **args,int in,int obj,int id_obj){
    int n = atoi((char*)args[in-1]);
    unsigned char **ins = nums(args,in,n);
    printf("insertar %d elementos en obj tipo%d id:%d\n",n,obj,id_obj);
    ins_n(obj,id_obj,n,(char**)ins);
}
int insertar_simple(unsigned char **args,int obj,int id_obj){
    int n;
    for(n = 0;n < **(args-1); n++){
        if(esnum(args[n]))
            break;
    }
    printf("insertar número%s en obj:%d id:%d\n",args[n],obj,id_obj);
    insertar(obj,id_obj,(char*)args[n]);
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
int busc_obj(unsigned char *arg){
    /*Desconocido(0),Lista(1),Pila(2),Cola(3)*/
    int obj = 0;
    mayusculas((char*)arg);
    if(busc_op(arg,OPH)==OBJETOS){
        if(strcmp((char*)arg,"LISTA")==0)
            obj = 1;
        else if(strcmp((char*)arg,"PILA")==0)
            obj = 2;
        else if(strcmp((char*)arg,"COLA")==0)
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
            if(obj&&id_o)
                insertar_n(args,in,obj,id_o);
            break;
        }else{
            mayusculas((char*)args[in]);
            if(strcmp((char*)args[in],"EN")==0){
                int id_o = rem_nums(args[**(args-1)-1]);
                int obj = busc_obj(args);
                if(obj&&id_o)
                    //printf("insert simple obj:%d, id_o:%d\n",obj,id_o);
                    insertar_simple(args,obj,id_o);
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
            //casos:
            //-insertar en la lista1 15 números aleatorios
            //-insertar lista2 en pila1
            if(rem_nums(s[i])){
                printf("s:%s,pos:%d\n",s[i],i);
                break;
            }
        }
    }
}
int mostrar_tipo(int obj,int id_obj,int tipo){
    int temp;
    char *s;
    if(tipo){
        while((s = extraer(obj,id_obj))!=NULL){
            temp = atoi(s);
            if(temp%2==0)
                printf("%d\n",temp);
        }
    }else{
        while((s = extraer(obj,id_obj))!=NULL){
            temp = atoi(s);
            if(temp%2==1)
                printf("%d\n",temp);
        }
    }
}
int mostrar(unsigned char **args){
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    if(**(args-1) > 1 && **(args-1) <= 3){
        if(id_o&&obj){
            printf("mostrar obj:%d,id:%d\n",obj,id_o);
            printf("mostrar:%s\n",mostrar(obj,id_o));
        }
    }else{
        int n;
        int tipo = 0;//por impar(0),par(1)
        for(n = 0; n < **(args-1)-1;n++){
            mayusculas((char*)args[n]);
            if(strcmp((char*)args[n],"PARES")==0){
                tipo = 1;
                break;
            }
        }
        printf("mostrar numeros tipo.%d obj:%d,id:%d\n",tipo,obj,id_o);
        mostrar_tipo(obj,id_o,tipo);
    }
}
int anexar(unsigned char **args){
    int i;
    int ids[] = {0,0};int j = 0;
    int objs[] = {0,0};int k = 0;
    for(i = 1;i < **(args-1);i++){
        if((ids[j] = rem_nums(args[i]))>0){
            if(objs[k] = busc_obj(args[i])){
                j++;k++;
            }
        }
    }
    if(objs[0] && objs[1]){
        printf("anexar obj:%d id:%d a obj:%d id:%d",objs[0],ids[0],objs[1],ids[1]);
        anexar(objs[0],ids[0],objs[1],ids[1]);
    }
}
int ordenar(unsigned char **args){
    int i;
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    int orden[] = {0,0};
    if(id_o && obj){
        //ascendente(0),descendente(1)
        int j = 0;
        for(i = 1;i < **(args-1)-1;i++){
            mayusculas((char*)args[i]);
            if(strcmp((char*)args[i],"MAYOR") == 0)
                orden[j++] = 3;
            if(strcmp((char*)args[i],"MENOR") == 0)
                orden[j++] = 2;
        }
        if(orden[0] && orden[1] && orden[0]!=orden[1])
            printf("imprimir de %d a %d obj:%d,id:%d\n",orden[0],orden[1],obj,id_o);
    }
}
int extraer(unsigned char **args){
    int i;
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    if(id_o && obj){
        printf("Extraer:%s\n",extraer(obj,id_o));
    }
}
int crear(unsigned char **args){
    int i;
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    if(obj){
        printf("Crear:%d\n",obj);
        nuevo_obj(obj);
    }
}
void asignar(unsigned char **s){
    int n = busc_op(s[0],OPH);
    switch(n){
        case INSERTAR: insertar(s); break;
        case MOSTRAR: mostrar(s); break;
        case EXTRAER: extraer(s); break;
        case ANEXAR: anexar(s); break;
        case ORDENAR: ordenar(s); break;
        case CREAR: crear(s); break;
        case LIMPIAR: printf("%s\n",s[0]); break;
        case SALIR: exit(0); break;
    }
}

int main(){
    cargar_datos();
    //unsigned char s3[] = "mostrar pila1";
    //!!!Revisar generador de nums
    //implementar casos de números aleatorios sin modificador
    unsigned char s[] = "salir";
    unsigned char s2[] = "insertar 5.67 en lista1";
    unsigned char s3[] = "mostrar la lista1"; 
    unsigned char **sp = partir(s);
    asignar(sp);
  //  sp = partir(s2);
  //  asignar(sp);
  //  sp = partir(s3);
  //  asignar(sp);
    return 0;
}
