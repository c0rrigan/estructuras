/*
 * Nava López Sebastián
 * Estructuras de Datos
 *
 * Programa que lee un archivo .csv el cual es el primer agrgumento del programa
 * y lo imprime
 */
#include <stdio.h>
#include <stdlib.h>

#define BUFFER 10 //Número de caracteres que quedarían en buffer

void **matriz(char*);
float **iniciar_fmatriz(int,int);
int **iniciar_imatriz(int,int);
void **crea_matriz(int,int,int,FILE*);
void **matrix(char *s){
    int pres=0;//Indica si la matriz necesita ser float o int
    int i,m,n=i=m=0;
    char c;
    FILE *f = fopen(s,"r");
    /**
     * En este primer recorrido del archivo se detecta el número máximo de
     * caracteres en cada fila, así como la presencia de números decimales
     * en tal caso se activa la bandera 'pres'
     */
    while((c=getc(f))!=EOF){
        if(c=='.'||c=='e')
            pres=1;
        if(c==',')
            i++;
        if(c=='\n'){
            i++;
            m++;
            n=(i>n)?i:n;
            i=0;
        }
    }
    rewind(f);
    printf("m=%d,n=%d\n",m,n);
    if(pres){
        float **mtr=(float**)crea_matriz(pres,m,n,f);
        return mtr;
        //int a,b;
        //for(a=0;a<m;a++){
        //    for(b=0;b<n;b++){
        //        printf("%.3f\t",mtr[a][b]);
        //    }
        //    printf("\n");
        //}
    }else{
        int **mtr=(int**)crea_matriz(pres,m,n,f);
        return mtr;
        //int a,b;
        //for(a=0;a<m;a++){
        //    for(b=0;b<n;b++){
        //        printf("%d\t",mtr[a][b]);
        //    }
        //    printf("\n");
        //}
    }
    //printf("%.1f\n",mtr[6][4]);
    //char **r=(char**)suede();
    //printf("%c",r[0][4]);
}
/**
 * Crea una matriz m*n de tipo float o int dependiendo si la bandera 'pres'
 * es activada en el primer recorrido al archivo
 */
void **crea_matriz(int pres,int m,int n,FILE *f){
    unsigned short int j,k,i=k=j=0;
    char c;
    char *buffer=(char *)malloc(sizeof(char)*BUFFER);
    if(pres){
        printf("Press on\n");
        float **mtr=(float**)iniciar_fmatriz(m,n);
        while((c=getc(f))!=EOF){
            if(c!='\n'){
                if(c!=','){
                    buffer[k++]=c;
                }else{
                    buffer[k]='\0';
                    //printf("%s | i:%d,j:%d\n",buffer,i,j);
                    mtr[i][j++]=(float)atof(buffer);
                    for(;k>0;k--)
                        buffer[k]=' ';
                }
            }else{
                buffer[k]='\0';
                //printf("%s | i:%d,j:%d\n",buffer,i,j);
                mtr[i][j++]=(float)atof(buffer);
                for(;k>0;k--)
                    buffer[k]=' ';
                j=0;
                i++;
            }
        }
        return mtr;
    }else{
        printf("Normal mode\n");
        int **mtr=(int**)iniciar_imatriz(m,n);
        while((c=getc(f))!=EOF){
            if(c!='\n'){
                if(c!=','){
                    buffer[k++]=c;
                }else{
                    buffer[k]='\0';
                    printf("%s | i:%d,j:%d\n",buffer,i,j);
                    mtr[i][j++]=(int)atoi(buffer);
                    for(;k>0;k--)
                        buffer[k]=' ';
                }
            }else{
                buffer[k]='\0';
                printf("%s | i:%d,j:%d\n",buffer,i,j);
                mtr[i][j++]=(int)atoi(buffer);
                for(;k>0;k--)
                    buffer[k]=' ';
                j=0;
                i++;
            }
        }
        return mtr;
    }
}
float **iniciar_fmatriz(int m,int n){
    float **mtr=(float**)malloc(sizeof(float*)*m);
    unsigned short int i=0;
    --m;
    for(;m>=0;--m){
        float *num=(float*)malloc(sizeof(float)*n);
        mtr[m]=num;
        for(;i<n;i++)
            mtr[m][i]=0;
    }
    return mtr;
}
int **iniciar_imatriz(int m,int n){
    int **mtr=(int**)malloc(sizeof(int*)*m);
    unsigned short int i=0;
    --m;
    for(;m>=0;--m){
        int *num=(int*)malloc(sizeof(int)*n);
        mtr[m]=num;
        for(;i<n;i++)
            mtr[m][i]=0;
    }
    return mtr;
}
