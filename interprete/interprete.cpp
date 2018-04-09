#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "utils/cadenas.h"
#include "estruct/estructuras.h"
extern "C"{
#include "utils/datos.h"
}
#define BUFF_C 16
#define BUFF_LINEA 120
enum {INSERTAR,MOSTRAR,EXTRAER,ANEXAR,ORDENAR,OBJETOS,UNIDADES,LIMPIAR,CREAR,SALIR} OP_ID;
using namespace std;
/*Generar arreglo de enteros 'n' enteros con el tamaño en *(n-1)*/
char **n_arr(int n){
    char **nums = (char**)calloc(n+1,sizeof(char*));
    for(--n;n>=0;n--)
        nums[n] = (char*)calloc(BUFF_C,sizeof(char));
    return nums;
}
char **gen_nums(int n,int tipo,int orden){
    int aumento = 2;
    char **nums = n_arr(n);
    int temp;
    if(orden){
        if(tipo){
            for(--n;n >= 0;n--){
                temp = ((temp = rand()%10000)%aumento==0)?temp:temp+1;
                sprintf(*(nums+n),"%d",temp);
            }
        }else{
            for(--n;n >= 0;n--){
                temp = ((temp = rand()%10000)%aumento==1)?temp:temp+1;
                sprintf(*(nums+n),"%d",temp);
            }
        }
    }else{
        if(tipo){
            temp = ((temp = rand()%10000)%aumento==0)?temp:temp-1;
            for(--n;n >= 0;n--){
                temp += aumento;
                sprintf(*(nums+n),"%d",temp);
            }
        }else{
            for(--n;n >= 0;n--){
                temp = ((temp = rand()%10000)%aumento==1)?temp:temp+1;
                sprintf(*(nums+n),"%d",temp);
            }
        }
    }
    return nums;
}
//Retorna un arreglo de números de acuerdo a los modificadores detectados en args
//a partir de args[in]
char **nums(char **args,int in,int n){
    //Asumimos que el número de elementos es el número anterior
    //a la unidad
    int orden = 0;//por defecto el orden es consecutivo(0),aleatorio es 1
    int tipo = 0;//por impar(0),par(1)
    for(in++; in < **(args-1)-1;in++){
        mayusculas(args[in]);
        if(strcmp(args[in],"ALEATORIOS")==0){
            orden = 1;
            continue;
        }
        if(strcmp(args[in],"PARES")==0){
            tipo = 1;
            continue;
        }
    }
    printf("numeros\nORDEN:%d ,TIPO:%d\n",orden,tipo);
    return gen_nums(n,tipo,orden);
}
/*Insertar N número con los modificadores necesarios al objeto*/
int insertar_n(char **args,int in,int obj,int id_obj){
    int n = atoi(args[in-1]);
    char **ins = nums(args,in,n);
    printf("insertar %d elementos en obj tipo%d id:%d\n",n,obj,id_obj);
    ins_n(obj,id_obj,n,ins);
}
int insertar_simple(char **args,int obj,int id_obj){
    int n;
    for(n = 0;n < **(args-1); n++){
        if(esnum(args[n]))
            break;
    }
    printf("insertar número%s en obj:%d id:%d\n",args[n],obj,id_obj);
    insertar(obj,id_obj,copiar(args[n]));
}
//Retorna el tipo de objeto que tiene la cadena,
//notar que ya no debe de contar con el identificador al final
int busc_obj(char **args){
    /*Desconocido(0),Lista(1),Pila(2),Cola(3)*/
    int obj = 0;
    mayusculas((char*)args[**(args-1)-1]);
    if(busc_op(args[**(args-1)-1],OPH)==OBJETOS){
        if(strcmp(args[**(args-1)-1],"LISTA")==0)
            obj = 1;
        else if(strcmp(args[**(args-1)-1],"PILA")==0)
            obj = 2;
        else
            obj = 3;
    }
    return obj;
}
int busc_obj(char *arg){
    /*Desconocido(0),Lista(1),Pila(2),Cola(3)*/
    int obj = 0;
    mayusculas(arg);
    if(busc_op(arg,OPH)==OBJETOS){
        if(strcmp(arg,"LISTA")==0)
            obj = 1;
        else if(strcmp(arg,"PILA")==0)
            obj = 2;
        else if(strcmp(arg,"COLA")==0)
            obj = 3;
    }
    return obj;
}
int asig_ins(char **args,int in){
    for(in++;in < **(args-1); in++){
        //insertar n UNIDADES $mod1 $mod2 en #obj
        if(busc_op(args[in],OPH)==UNIDADES){
            int id_o = rem_nums(args[**(args-1)-1]);
            int obj = busc_obj(args);
            printf("insert simple obj:%d, id_o:%d\n",obj,id_o);
            if(obj&&id_o)
                insertar_n(args,in,obj,id_o);
            break;
        }else{
            mayusculas(args[in]);
            if(strcmp(args[in],"EN")==0){
                int id_o = rem_nums(args[**(args-1)-1]);
                int obj = busc_obj(args);
                if(obj&&id_o)
                    printf("insert simple obj:%d, id_o:%d\n",obj,id_o);
                    insertar_simple(args,obj,id_o);
                break;
            }
        }
    }
}
int asig_ins(char *,char **s){

}
int insertar(char **s){
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
int mostrar(char **args){
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
            mayusculas(args[n]);
            if(strcmp(args[n],"PARES")==0){
                tipo = 1;
                break;
            }
        }
        printf("mostrar numeros tipo.%d obj:%d,id:%d\n",tipo,obj,id_o);
        mostrar_tipo(obj,id_o,tipo);
    }
}
int anexar(char **args){
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
int ordenar(char **args){
    int i;
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    int orden[] = {0,0};
    if(id_o && obj){
        //ascendente(0),descendente(1)
        int j = 0;
        for(i = 1;i < **(args-1)-1;i++){
            mayusculas(args[i]);
            if(strcmp(args[i],"MAYOR") == 0)
                orden[j++] = 3;
            if(strcmp(args[i],"MENOR") == 0)
                orden[j++] = 2;
        }
        if(orden[0] && orden[1] && orden[0]!=orden[1])
            printf("imprimir de %d a %d obj:%d,id:%d\n",orden[0],orden[1],obj,id_o);
    }
}
int extraer(char **args){
    int i;
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    if(id_o && obj){
        printf("Extraer:%s\n",extraer(obj,id_o));
    }
}
int crear(char **args){
    int i;
    int id_o = rem_nums(args[**(args-1)-1]);
    int obj = busc_obj(args);
    if(obj){
        printf("Crear:%d\n",obj);
        nuevo_obj(obj);
    }
}
void asignar(char **s){
    int n = busc_op(s[0],OPH);
    printf("%d\n",n);
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
    char buff[BUFF_LINEA];
    for(;;){
        fgets(buff,BUFF_LINEA,stdin);
        asignar(partir(buff));
        memset(buff,0,BUFF_LINEA);
    }
    return 0;
}
