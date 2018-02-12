#include <stdio.h>
#include "load.h"
#include "puntos.h"

typedef struct DistanciaPunto{
    union{
        float *cord1;
        float *cord2;
    }fcord;
    union{
        int *cord1;
        int *cord2;
    }icord;
    float dist;
}DistanciaPunto;

void centroides(Matriz *m){
    DistanciaPunto *distancias;
    if(PRES){
         
    }else{
    }
}
