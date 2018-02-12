extern int PRES;
extern int verbose;
typedef struct Matriz{
    int m,n;
    union{
        float **fdata;
        int **idata;
    }data;
}Matriz;
    
Matriz *matriz(char*);
