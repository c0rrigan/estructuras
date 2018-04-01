#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define BUFF_C 90 //Buffer de carcteres
#define BUFF_D 30 //Buffer de definiciones por grupo
/* INSERTAR : 616
 * MOSTRAR : 552
 * EXTRAER : 539
 * ORDENAR : 523
 * ANEXAR : 447
 */
char *OP[]={"INSERTAR","MOSTRAR","ANEXAR","ORDENAR","EXTRAER"};
unsigned int **OPH;
typedef enum {INSERTAR=2,MOSTRAR,ANEXAR,ORDENAR,EXTRAER} OP_IND;

/*Función que cambia una cadena 's' con terminador '\0' a letras mayusculas*/
void mayusculas(char *s){
    while(*s!='\0')
        *(s++)=toupper(*s);
}
/*Función que crea arreglos de 'y' dimensiones y 'x' espacios*/
unsigned int **n_matr(int x,int y){
    unsigned int **tab_o;
    tab_o = (unsigned int**)calloc(x+1,sizeof(int*));
    *tab_o = (unsigned int*)calloc(2,sizeof(int));
    tab_o[0][0] = x;
    tab_o[0][1] = y;
    while(--x>=0)
        tab_o[x+1] = (unsigned int*)calloc(y,sizeof(int));
    return tab_o+1;
}
/*Función de comparación para implementar qsort()*/
int cmp(const void *a,const void *b){
    const unsigned int *v_a = *(const unsigned int **)a;
    const unsigned int *v_b = *(const unsigned int **)b;
    return v_a[0] - v_b[0];
}
/*Función hash simple*/
unsigned int hash(char *s){
    unsigned int i,sum;
    for(i=0,sum=0;s[i]!='\0';i++)
        sum+=s[i];
    return sum;
}
/*Función para contar caracteres*/
unsigned int cc(char *s){
    unsigned int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}
/* Función de busqueda binaria que se acerca a al elemento de 'm'
 * mas cercano al entero 'h' en el rango de 'n' a 'q' siendo 'n' y 'q'
 * indices del arreglo bidimensional 'm'*/
int bb(int h,int n,int q,unsigned int **m){
    if(n==q){
        return n;
    }else{
        int p = (n+q)/2;
        if(**(m+p)<h)
            return bb(h,p+1,q,m);
        else
            return bb(h,n,p,m);
    }
}
/*Funcion que retorna el tipo de operación que tiene cierta palabra
 * dado su valor resultado de la función hash()*/
int busc_op(unsigned int hash,unsigned int **tab){
    int p = bb(hash,0,**(tab-1)-1,tab);
    return (**(tab+p)==hash)?tab[p][1]:-1;
}
/*Función que guarda la tabla de hash de operaciones OPH en el archivo
 * tabla*/
int guardar_tab(){
    FILE *o = fopen("tabla","w+");
    int n = **(OPH-1);
    fwrite(OPH[-1],sizeof(int),1,o);
    for(;n >= 0;n--){
        fwrite(&(OPH[n][0]),sizeof(int),1,o);
        fwrite(&(OPH[n][1]),sizeof(int),1,o);
        fputc('\n',o);
    }
    fputc(EOF,o);
    return fclose(o);
}
/*Función que genera la tabla de operaciones primitivas basada en los
 * el arreglo OP, donde se enlistas las operaciones básicas del programa*/
unsigned int **tab_prim(){
    int n = sizeof(OP)/sizeof(OP[0]);
    unsigned int **mtr = n_matr(n,2);
    while(--n>=0){
        mtr[n][0] = hash(OP[n]);
        mtr[n][1] = n;
    }
    qsort(mtr,mtr[-1][0],sizeof(mtr[0]),cmp);
    return mtr;
}
void nuevo_reg(unsigned int hash,unsigned int op,unsigned int **t){
    if(**t >= BUFF_D){
        //t = (unsigned int**)realloc(t,n*sizeof(int*));
    }
    int n = ++(**t);
    t[n-1] = (int*)calloc(2,sizeof(int));
    t[n-1][0]=hash;
    t[n-1][1]=op;
}
unsigned int **ingr_regs(FILE *f,unsigned int op,unsigned int **tab){
    char c;int i=0;
    unsigned char *buff = (unsigned char *)calloc(BUFF_C,sizeof(char));
    while((buff[i++]=fgetc(f))!='}' && i < BUFF_C){
        if(buff[i-1]=='\n')
            i--;
        if(buff[i-1]==','){
            buff[i-1] = '\0';
            mayusculas(buff);
            printf("%s : %d\n",buff,hash(buff));
            nuevo_reg(hash(buff),op,tab);
            i=0;
            memset(buff,0,BUFF_C*sizeof(*buff));
        }
    }
    //Utilizar la cadena que se queda en el buffer al acabar
    buff[i-1] = '\0';
    mayusculas(buff);
    printf("%s : %d\n",buff,hash(buff));
    nuevo_reg(hash(buff),op,tab);
}
/*Combina las definiciones globales de OPH con las resultantes en el
 * archivo de configuración*/
void combinar_conf(unsigned int **oph,unsigned int **conf){
    int i,j;
    i=**conf;
    j = **(oph-1)+i;
    conf = (unsigned int**)realloc(conf,j*sizeof(unsigned int*));
    for(i++;i<=j;i++){
        conf[i-1] = (unsigned int*)calloc(2,sizeof(int));
        conf[i-1][0] = oph[j-i][0]; 
        conf[i-1][1] = oph[j-i][1];
    }
    **conf = j-1;
}
/*Función quee agrega las registros de archivo 'conf' al arreglo
 * global OPH*/
unsigned int **tab_conf(FILE *f,unsigned int **tab_base){
    char c;int i=0;
    char *buff = (char *)calloc(BUFF_C,sizeof(char));
    unsigned int **tab_temp = (unsigned int**)calloc(BUFF_D,sizeof(unsigned int*));
    *tab_temp = (unsigned int*)calloc(1,sizeof(int));
    **tab_temp = 1;
        while((buff[i++] = getc(f)) != EOF && i < BUFF_C){
            if(buff[i-1]=='\n')
                i--;
            if(buff[i-1]=='{'){
                buff[i-1]='\0';
                int id_op;
                if((id_op = busc_op(hash(buff),OPH))>-1){
                    printf("Grupo:%s\n",buff);
                    ingr_regs(f,id_op,tab_temp);
                    i=0;
                    memset(buff,0,BUFF_C*sizeof(*buff));
                }
            }
        }
    printf("!!!!%d\n",**tab_temp);
    combinar_conf(OPH,tab_temp);
    tab_temp = tab_temp+1;
    //Al final hay que ordenar todos los registros de la matriz
    qsort(tab_temp,tab_temp[-1][0],sizeof(tab_temp[0]),cmp);
    return tab_temp;
}
unsigned int **leer_tabla(FILE *t){
    int i;unsigned int **tab;
    //Lee el número de datos que contiene la tabla de definiciones,
    //el cual esta en el primer byte del archivo
    fread(&i,sizeof(int),1,t);
    tab = n_matr(i,2);
    i--;
    for(;i>=0;i--){
        fread(&(tab[i][0]),sizeof(int),1,t);
        fread(&tab[i][1],sizeof(int),1,t);
        fgetc(t);
    }
    return tab;
}
unsigned int **generar_tabla(){
    FILE *f;
    unsigned int **tab = tab_prim();
    OPH = tab;
    if((f=fopen("config","r+"))){
        return tab_conf(f,tab);
    }
    return tab;
}
unsigned int cargar_datos(){
    FILE *f;
    if((f=fopen("tabla","r+"))){
        //Cargar todas las definiciones de la tabla al arreglo global OPH
        OPH = leer_tabla(f);
        fclose(f);
        return **(OPH-1);
    }else{
        OPH = generar_tabla();
        guardar_tab();
        return **(OPH-1);
    }
}

int main(){
    //generar_tabla();
    //unsigned int **t = leer_tabla();
    cargar_datos();
    int i = **(OPH-1);
    printf("leidos:%d\n",i);
    char s[] = "SACAR";
    printf("palabra:%s\n",s);
    mayusculas(s);
    printf("mayus:%s\n",s);
    printf("hash:%d",hash(s));
    printf("id:%d\n",busc_op(hash(s),OPH));
    printf("operación:%s\n",OP[busc_op(hash(s),OPH)]);
    //for(i--;i>=0;i--){
    //    printf("%d | %d | %d \n",i,OPH[i][0],OPH[i][1]);
    //}
    //guardar_tab();
    return 0;
}
