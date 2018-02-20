/*
 * Nava López Sebastián
 * Estructuras de Datos
 *
 * Programa que lee un archivo .csv el cual es el primer agrgumento del programa
 * y lo imprime
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "load.h"
#include "puntos.h"
/**
 * -Hay que encontrar una forma para sacar la tabla de centroídes,puntos y distancia
 *  para poder seguir a la siguiente fase del algoritmo
 */
typedef struct Par{
    int p1;
    int p2;
}Par;
int step=0;
float nabs(float);
int buscar_pto(int,int,int);
void ordenar(DistanciaPunto *lista,int tam);
float calc_dist_centr(int,DistanciaPunto*,int*,int,int);
float calc_dist(float*,float*,int);
DistanciaPunto *distancias(Matriz*);
unsigned int **promedio_ptos(unsigned int**,Matriz*,DistanciaPunto*,float**,int);
unsigned int **calc_dist_pc(Matriz*,DistanciaPunto*,float**,unsigned int**,int);

/* Repartir puntos
 *  -dc:Relación entre la distancia de un centroide y un punto
 *  -np:numero de puntos
 *  -nc:numero de centroides
 */
unsigned int **repartir_puntos(DistanciaPunto *dc,float **centr,Matriz *mtr,unsigned int** racimo,int nc){
    int i,j=0;
    for(i=0;i<mtr->m;i++,(racimo[i-1]=(unsigned int*)malloc(sizeof(unsigned int)*2)));
    for(i=0;i<mtr->m;i++){
        int mindist=i;
        for(j=0;j<nc;j++){
            if(dc[mtr->m*j+i].dist<dc[mindist].dist){
                mindist=i+j*mtr->m;
            }
            //printf("INDEX:%d | i:%d,j:%d,mindist:%d\n",(mtr->m*j+i),i,j,mindist);
        }
        racimo[i][0]=i;
        racimo[i][1]=dc[mindist].p1;
    }
    for(i=0;i<mtr->m;i++)
        printf("punto:%d,racimo:%d\n",racimo[i][0],racimo[i][1]);
    return promedio_ptos(racimo,mtr,dc,centr,nc);
}
/* Funcion que toma el promedio de los puntos resultantes de la repartición de centroides
 *  -rac:racimos i.e. centroides|puntos
 *  -mtr:matriz de datos introducidos por el usuario
 *  -centr:arreglo de coordenadas de centroides
 *  -nc:número de centroides
 */
unsigned int **promedio_ptos(unsigned int **rac,Matriz *mtr,DistanciaPunto *dc,float **centr,int nc){
    printf("---STEP:%d---\n",step++);
    unsigned int i,j,cont=0;
    float **sumas=(float**)malloc(sizeof(float**)*nc);
    unsigned int *ap=(unsigned int*)malloc(sizeof(unsigned int)*nc);
    for(i=0;i<nc;i++,(sumas[i-1]=(float*)malloc(mtr->n*sizeof(float))));
    for(i=0;i<mtr->m;i++){
        //sumar +1 aparicion para cada punto
        ++ap[rac[i][1]];
        //sumar todas las cantidades de cada dimension
        for(j=0;j<mtr->n;j++)
            sumas[rac[i][1]][j]=sumas[rac[i][1]][j]+mtr->data[rac[i][0]][j];
//printf("i:%d,j:%d\n",i,j);
    }
    for(i=0;i<nc;i++){
        for(j=0;j<mtr->n;j++){
            sumas[i][j]/=ap[i];
            centr[i][j]=sumas[i][j];
            if(nabs(sumas[i][j]-centr[i][j])<err){
                printf("menor\n");
                cont++;
            }
            printf("sumas:%d,#dim:%d,pos:%.2f\n",i,j,sumas[i][j]); 
            printf("centr:%d,#dim:%d,pos:%.2f\n",i,j,centr[i][j]);
            printf("diferencia:%.2f\n",nabs(sumas[i][j]-centr[i][j]));
        }
        //falta reemplazar los nuevos centroides y pasar a la siguiente
        //función que calcula la distancia con los nuevos centroídes
    }
    //if(cont==nc*mtr->n||step>3)
    //    return rac;
    if(step>3)
        return rac;
    free(ap);
    return calc_dist_pc(mtr,dc,centr,rac,nc);
}
unsigned int **calc_dist_pc(Matriz *mtr,DistanciaPunto *dp,float **centr,unsigned int **rac,int nc){
    unsigned int i,j,k;
    //printf("orig:%.2f\n",mtr->data[0][0]);
    //mtr->data[0][0]+=1e3;
    //printf("orig:%.2f\n",mtr->data[0][0]);
    //printf("centr:%.2f\n",centr[0][0]);
    for(i=0;i<nc;i++){
        for(j=0;j<mtr->m;j++){
            k=j+i*mtr->m;
            dp[k].dist=calc_dist(centr[i],mtr->data[j],mtr->n);
            dp[k].p1=i;
            dp[k].p2=j;
            printf("INDEX:%d| centr:%d,pto:%d,dist:%.2f\n",k,i,j,dp[k].dist);
            printf("\tcentr--- x:%.2f,y:%.2f\n",centr[i][0],centr[i][1]);
            printf("\tpunto--- x:%.2f,y:%.2f\n",mtr->data[j][0],mtr->data[j][1]);
        }
    }
    return repartir_puntos(dp,centr,mtr,rac,nc);
}
/** * Realiza la tabla de centroides ordanada
*/
unsigned int **iniciar_centroides(Matriz *mtr,int ncentr){
    unsigned int **racimo=(unsigned int**)malloc(sizeof(unsigned int)*mtr->m);
    DistanciaPunto *dists=(DistanciaPunto*)distancias(mtr);
    int *icent=(int*)malloc(sizeof(int)*ncentr);
    int k=mtr->m;
    k*=k+1;
    k/=2;
    unsigned int i,j;
    float sref=0;
    printf("Tabla de distancias a centroides ordenadas\n");
    for(i=0;i<k;i++){
        if(dists[i].dist>sref){
            j=i;
            sref=dists[i].dist;
        }
    }
    icent[0]=dists[j].p1;
    icent[1]=dists[j].p2;
    if(ncentr>2){
        unsigned int pref;
        for(j=2;j<ncentr;j++){
            float suma,sumaref=0;
            for(i=0;i<mtr->m;i++){
                if((suma=calc_dist_centr(i,dists,icent,j,mtr->m))>sumaref){
                    sumaref=suma;
                    pref=i;
                }
            }
            icent[j]=pref;
        }
    }
    DistanciaPunto *distcentr=(DistanciaPunto*)calloc((mtr->m)*ncentr,sizeof(DistanciaPunto));
    DistanciaPunto *tarr=(DistanciaPunto*)calloc(mtr->m,sizeof(DistanciaPunto));
    for(i=0;i<ncentr;i++){
        k=0;
        for(j=0;j<mtr->m;j++){
            memcpy(&(tarr[k]),&(dists[buscar_pto(icent[i],j,mtr->m)]),sizeof(DistanciaPunto));
            if(icent[i]>tarr[k].p1){
                tarr[k].p2=tarr[k].p1;
            }
            tarr[k].p1=i;
            k++;
        }
        //ordenar(tarr,k);
        memcpy(&(distcentr[i*mtr->m]),tarr,sizeof(DistanciaPunto)*mtr->m);
    }
    for(i=0;i<mtr->m*ncentr;i++)
        printf("INDEX=%d| p1:%d,p2:%d,dist:%.2f\n",i,distcentr[i].p1,distcentr[i].p2,distcentr[i].dist);
    //convertir el arreglo de indices de centroides a referencias a coordenadas i.e.
    //arreglos de numeros float
    float **centr=(float**)malloc(sizeof(float*)*ncentr);
    for(i=0;i<ncentr;i++){
        printf("icent:%d ,x:%.2f,y:%.2f\n",icent[i],mtr->data[icent[i]][0],mtr->data[icent[i]][1]);
        float *n=mtr->data[icent[i]];
        float *m=(float*)malloc(sizeof(float)*mtr->n);
        memcpy(m,n,sizeof(float)*mtr->n);
        centr[i]=m;
        //printf("centrN:%d,x:%.2f,y:%.2f\n",i,m[0],m[1]);
    }
    return repartir_puntos(distcentr,centr,mtr,racimo,ncentr);
}
int ord(const void *a,const void *b){
    DistanciaPunto *d1=(DistanciaPunto*)a;
    DistanciaPunto *d2=(DistanciaPunto*)b;
    return (d1->dist>d2->dist)?1:0;
}
void ordenar(DistanciaPunto *lista,int tam){
    qsort(lista,tam,sizeof(DistanciaPunto),ord);
}
DistanciaPunto *distancias(Matriz *mtr){
    unsigned short int i,j,l=0;
    int k=mtr->m;
    k*=k+1;
    k/=2;
    DistanciaPunto *dists = (DistanciaPunto*)malloc(sizeof(DistanciaPunto)*k);
    for(i=0;i<mtr->m;i++){
        for(j=i;j<mtr->m;j++){
            dists[l].p1=i;
            dists[l].p2=j;
            if(i==j){
                dists[l].dist=0.0f;
            }else{
                dists[l].dist=calc_dist(mtr->data[dists[l].p1],mtr->data[dists[l].p2],mtr->n);
            }
            l++;
        }
    }
    //for(i=0;i<k;i++){
    //    printf("INDEX=%d| p1:%d,p2:%d,dist:%.2f\n",i,dists[i].p1,dists[i].p2,dists[i].dist);
    //}
    //    printf("punto:%d\n",buscar_pto(8,3,mtr->m));
    return dists;
}

float calc_dist(float *p1,float *p2,int dim){
    float dist=0;
    for(;dim>=0;--dim){
        dist+=(p1[dim]-p2[dim])*(p1[dim]-p2[dim]);
    }
    dist=sqrt(dist);
    return dist;
}
int buscar_pto(int a,int b,int np){
    if(a>b){
        int aux=a;
        a=b;
        b=aux;
    }
    return ((a*(a+1))/2+(np-a)*a+b-a);
}
float calc_dist_centr(int punto,DistanciaPunto *dists,int *centr,int ncentr,int np){
    unsigned short int i;
    float sumadist=0;
    for(i=0;i<ncentr;i++){

        if(punto==centr[i]){
            return 0;
        }else{
            sumadist+=dists[buscar_pto(punto,centr[i],np)].dist;
        }
    }
    return sumadist;
}
float nabs(float x){
    return (x<0)?x*-1:x;
}
