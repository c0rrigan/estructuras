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

float calc_dist(float*,float*,int);
DistanciaPunto *distancias(Matriz*);
void ordenar(DistanciaPunto*,int);
int ord(const void *a,const void *b);

void centroides(Matriz *mtr,int ncentr){
    DistanciaPunto *dists=(DistanciaPunto*)distancias(mtr);
    int *centroides=(int*)malloc(sizeof(int)*ncentr);
    int k=mtr->m;
    k*=k+1;
    k/=2;
    unsigned short int i;
    //printf("con\n");
    //for(i=0;i<k;i++)
    //    printf("i:%d,j:%d,di:%.2f\n",dists[i].p1,dists[i].p2,dists[i].dist);
    centroides[0]=dists[k-1].p1;
    centroides[1]=dists[k-1].p2;
    //if(ncentr>2){
    //    int nc=2;
    //    int pr=0;//punto referencia
    //    float dr=0.0f;//distancia referencia
    //    while(nc<ncentr){
    //        int i,j,l,m,n;
    //        for(i=k-2;i>mtr->m;i--){
    //            for(j=0;j<nc;j++){
    //                printf("i:%d,j:%d\n",i,j);
    //                if(dists[i].p1==centroides[j]){
    //                    printf("Coincide con p1\n");
    //                    pr=dists[i].p1; 
    //                    for(l=0;l<nc;l++){
    //                        if(l!=i){
    //                            if(pr>centroides[l]){
    //                                printf("pr>\n");
    //                                for(n=i+1;i>mtr->m;i--){
    //                                    printf("n:%d,l:%d\n",n,l); 
    //                                }
    //                            }else{
    //                                printf("pr<\n");
    //                                for(n=i+1;i>mtr->m;i--){
    //                                    printf("n:%d,l:%d\n",n,l); 
    //                                }
    //                            }
    //                        }
    //                    }
    //                }
    //                if(dists[i].p2==centroides[j]){
    //                    pr=dists[i].p2;
    //                    printf("Coincide con p2\n");
    //                }
    //                //for(l=0;l<nc;l++){
    //                //if(l!=i){

    //                //}

    //            }
    //            nc++;
    //            }
    //        }
    //    }
    //}
}

DistanciaPunto *distancias(Matriz *mtr){
    unsigned short int i,j,l=0;
    int k=mtr->m;
    k*=k+1;
    k/=2;
    DistanciaPunto *dists = (DistanciaPunto*)malloc(sizeof(DistanciaPunto)*k);
    for(i=0;i<mtr->m;i++){
        for(j=i;j<mtr->m;j++){
            //printf("i:%d,j:%d\n",i,j);
            dists[l].p1=i;
            dists[l].p2=j;
            if(i==j){
                dists[l].dist=0.0f;
                //                printf("zero dist:%f\n",dists[l].dist);
            }else{
                dists[l].dist=calc_dist(mtr->data[dists[l].p1],mtr->data[dists[l].p2],mtr->n);
            }
            l++;
        }
    }
    //printf("sin\n");
    //for(i=0;i<k;i++)
    //    printf("i:%d,j:%d,di:%.2f\n",dists[i].p1,dists[i].p2,dists[i].dist);
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
        //printf("p1:%f,p2:%f,dim:%d,dis:%f\n",p1[dim],p2[dim],dim,dis);
    }
    dist=sqrt(dist);
    //    printf("dist:%.2f\n",dist);
    return dist;
}

