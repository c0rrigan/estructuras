#ifndef LOAD_H
#define LOAD_H
typedef struct matrix{
    int m,n;
    char **data;
}Matrix;

Matrix *load_matrix(char *s);
#endif
