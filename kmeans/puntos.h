typedef struct DistanciaPunto{
    int p1;
    int p2;
    float dist;
}DistanciaPunto;
DistanciaPunto *iniciar_centroides(Matriz*,int);
int **repartir_puntos(DistanciaPunto*,float**,Matriz*,int);
