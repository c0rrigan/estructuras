extern int PRES;
extern int verbose;
typedef struct Matriz{
    int m,n;
    float **data;
}Matriz;
    
Matriz *matriz(char*);
