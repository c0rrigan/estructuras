#ifndef EXPR_H
#define EXPR_H
#include <string>
#include <vector>
#include "cuestionarios.h"
enum Operadores {PAR_I = 1,PAR_D,IGUAL,DIFERENTE,MAY,MAY_I,MEN,MEN_I,AND,OR};
enum Tipos {NUM,OP};

typedef struct Elem{
    Tipos tipo;
    int val;
}Elem;
//Función qe evalúa la expresión lógica contenida en el string
int evaluarExpr(std::string);
void agregarSimbolos(std::vector<variable*>&);
#endif
