/*
 * Nava López Sebastián
 * Estructuras de Datos
 *
 * Programa que lee un archivo .csv el cual es el primer agrgumento del programa
 * y lo imprime
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "load.h"
#include "puntos.h"

typedef struct DistanciaPunto{
    int p1;
    int p2;
    float dist;
}DistanciaPunto;

DistanciaPunto *arraycp(DistanciaPunto*,int);
float calc_dist(float*,float*,int);
DistanciaPunto *distancias(Matriz*);
void ordenar(DistanciaPunto*,int);
int ord(const void *a,const void *b);

/**
 * Realiza la tabla de centroides ordanada
 */
void centroides(Matriz *mtr,int ncentr){
    DistanciaPunto *dists=(DistanciaPunto*)distancias(mtr);
    int *centroides=(int*)malloc(sizeof(int)*ncentr);
    int k=mtr->m;
    k*=k+1;
    k/=2;
    unsigned short int i,j;
    printf("Tabla de distancias a centroides ordenadas\n");
    centroides[0]=dists[k-1].p1;
    centroides[1]=dists[k-1].p2;
    for(i=0;i<ncentr;i++){
	    for(j=k-1;j>mtr->m-2;j--){
		    if(dists[j].p1==centroides[i])
			    printf("%d\t%d\t%.2f\n",centroides[i],dists[j].p2,dists[j].dist);
		    if(dists[j].p2==centroides[i])
			    printf("%d\t%d\t%.2f\n",centroides[i],dists[j].p1,dists[j].dist);
	    }
    }
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
    ordenar(dists,k);

    return dists;
}
void ordenar(DistanciaPunto *lista,int tam){
    qsort(lista,tam,sizeof(DistanciaPunto),ord);
}
int ord(const void *a,const void *b){
    DistanciaPunto *d1=(DistanciaPunto*)a;
    DistanciaPunto *d2=(DistanciaPunto*)b;
    return (d1->dist>d2->dist)?1:0;
}

float calc_dist(float *p1,float *p2,int dim){
    float dist=0;
    for(;dim>=0;--dim){
        dist+=(p1[dim]-p2[dim])*(p1[dim]-p2[dim]);
    }
    dist=sqrt(dist);
    return dist;
}
