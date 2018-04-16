//Nava Lopez Sebastian 1CV9
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "lista.h"
#define MEM 100//Numero de unidades de memoria en tabla primaria
class Elemento{
    public:
        int val;
        Lista *exp;
};

using namespace std;
Elemento tabla[MEM];
int fhash(int x){
    return x%MEM;
}
int insertar(int val){
    int hash = fhash(val);
    //Comprobar si la posición en la tabla hash esta ocupada
    //en caso de que el valor sea 0 puede reescribir :s
    Elemento *tempElem = tabla+hash;
    if(tempElem->val){
        if(!tempElem->exp)
            tempElem->exp = new Lista();
        tempElem->exp->insertar(val);
        return val;
    }else{
        tempElem->val = val;
        return val;
    }
    return 0;
}
int buscar(int val){
    int hash = fhash(val);
    Elemento *tempElem = tabla+hash;
    if(tempElem->val != val){
        return (tempElem->exp)?tempElem->exp->buscar(val):0;
    }else{
        return tempElem->val;
    }
}
int main(){
    Lista l;
    int j = 0;
    int i = 100;
    int q = 0;
    int nums[i];
    //int nums[] = {67,175,25,0,-4,35,67,175,25};
    //int i = sizeof(nums)/sizeof(nums[0]);
    FILE *f = fopen("numbers","w+");
    srand(time(NULL));
    for(;j < i;j++){
        nums[j] = rand()%1000;
        fprintf(f,"%d\n",nums[j]);
    }
    for(j = 0;j < i;j++){
        insertar(nums[j]);
    }
    fclose(f);
    for(;;){
        cin >> q;
        printf("buscar:%d\n",buscar(q));
    }
}
