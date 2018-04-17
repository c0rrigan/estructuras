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
        //Lista *exp;
        int t_exp;
        int *exp;
        Elemento(){ val = 0; t_exp = 0; exp = NULL;}
};
class TablaHash{
    public:
        int insertar(int);
        int buscar(int);
    private:
        Elemento tabla[MEM];
        int n_digitos(int);
        int mod_hash(int);
        int cm_hash(int);
        int exp_ins(Elemento*,int);
        int exp_busc(Elemento*,int);
};

using namespace std;

int TablaHash::mod_hash(int x){
    return x%MEM;
}
int TablaHash::n_digitos(int i){
    int dec = 10;
    int cont = 0;
    while(i>0){
        i = i - i%dec;
        dec *=10;
        cont++;
    }
    return cont;
}
int TablaHash::cm_hash(int val){
    int cont = n_digitos(val);
    int ret = 0;
    if(cont <= 2){
        return val%MEM;
    }
    char *num = (char*)calloc(cont,sizeof(char));
    sprintf(num,"%d",val);
    num[cont/2+1] = '\0';
    ret = atoi(num+cont/2-1);
    free(num);
    return ret;
}
int TablaHash::exp_ins(Elemento *em,int val){
    em->t_exp++;
    em->exp = (int*)realloc(em->exp,(em->t_exp)*sizeof(int));
    em->exp[em->t_exp-1] = val;
}
int TablaHash::insertar(int val){
    int hash = cm_hash(val);
    //Comprobar si la posición en la tabla hash esta ocupada
    //en caso de que el valor sea 0 puede reescribir :s
    Elemento *tempElem = tabla+hash;
    if(tempElem->val){
        if(!tempElem->exp)
            exp_ins(tempElem,val);
        return val;
    }else{
        tempElem->val = val;
        return val;
    }
    return 0;
}
int TablaHash::exp_busc(Elemento *em,int val){
    int p = 0;
    //p = bb(val,0,em->t_exp-1,em->exp);
    //return (**(tab+p)==h)?tab[p][1]:-1;
}
int TablaHash::buscar(int val){
    int hash = cm_hash(val);
    Elemento *tempElem = tabla+hash;
    if(tempElem->val != val){
        return (tempElem->exp)?exp_busc(tempElem,val):0;
    }else{
        return tempElem->val;
    }
}
int bb(int h,int n,int q,int *m){
    if(n==q){
        return *(m+n);
    }else{
        int p = (n+q)/2;
        if(*(m+p)<h)
            return bb(h,p+1,q,m);
        else
            return bb(h,n,p,m);
    }
}
int main(){
    TablaHash tb;
    int nums[] = {3,4,5,7,9};
    int num = 4;
    int out = bb(num,0,4,nums);
    printf("buscar:%d\n",out);
}
