#ifndef DATOS_H
#define DATOS_H
extern unsigned int **OPH;
extern char *OP[];
int busc_op(unsigned char *,unsigned int**);
unsigned int cargar_datos();
unsigned int hash(unsigned char *s);
#endif

