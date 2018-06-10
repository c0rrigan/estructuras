#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

#include "expr.h"

using namespace std;
//Función que regresa el identificador de cada operación
int operadores(string op){
    if(!op.compare("("))
        return PAR_I;
    if(!op.compare(")"))
        return PAR_D;
    if(!op.compare(">"))
        return MAY;
    if(!op.compare(">="))
        return MAY_I;
    if(!op.compare("<"))
        return MEN;
    if(!op.compare("<="))
        return MEN_I;
    if(!op.compare("=="))
        return IGUAL;
    if(!op.compare("!="))
        return DIFERENTE;
    if(!op.compare("&"))
        return AND;
    if(!op.compare("|"))
        return OR;
    else
        return 0;
}
//Función que asigna el orden de operación dependiendo
//del código de la operación establecido en el enum
int ordenOperacion(int op){
    if(op == PAR_I || op == PAR_D)
        return 5;
    if(op == MAY || op == MAY_I || op == MEN || op == MEN_I)
        return 4;
    if(op == IGUAL || op == DIFERENTE)
        return 3;
    if(op == AND)
        return 2;
    if(op == OR)
        return 1;
    else
        return 0;
}
//Función que calcula la operación con base en el ID asignado al operador
int operar(int op,int val1,int val2){
    switch(op){
        case(MAY):
            return val1 > val2;
        case(MAY_I):
            return val1 >= val2;
        case(MEN):
            return val1 < val2;
        case(MEN_I):
            return val1 <= val2;
        case(IGUAL):
            return val1 == val2;
        case(DIFERENTE):
            return val1 != val2;
        case(AND):
            return val1 && val2;
        case(OR):
            return val1 || val2;
    }
}
//Función que define el operador
int esOperador(string s,int *index){
    int op = 0;
    //Verificar si es un operador de un solo carácter
    if(op = operadores(s.substr(*index,1))){
        //Ver si es un operador incluyente
        if(s.at(*index) == '='){
            (*index)++;
            //Finalmente se regresa con el índice despues del operador
            if(op == MAY)
                return MAY_I;
            if(op == MEN)
                return MEN_I;
        }else{
            return op;
        }
    }else{
        if(op = operadores(s.substr(*index,2))){
            (*index)++;
            return op;
        }
    }
    return 0;
}
//Obtener variable de una cadena que puede comenzar con números
//para números y con letras para variables numéricas e.g. parámetros
//de exámenes
int obtenerVariable(string s){
    int i;
    if(isalpha(s.at(0))){
        //Buscar variable en tabla de valores
        cout << "Carácteristica no implementada" << endl;
        return 0;
    }else{
        //Buscar entero
        return atoi(s.c_str());
    }
}

//Función que convierte la cadena en una cola de estructuras 'elem' con
//tipo y valor de cada elemento(número o operador)
queue<Elem> dividirCadena(string s){
    queue<Elem> elems;
    string buffer;
    int i,val;
    char c;
    for(i = 0; i < s.length(); i++){
        if(val = esOperador(s,&i)){
            if(!buffer.empty()){
                //Revisar y vaciar el buffer
                //cout << "Número" << obtenerVariable(buffer) << endl;
                Elem num = {.tipo = NUM, .val = obtenerVariable(buffer)};
                elems.push(num);
                buffer.clear();
            }
            //cout << "Operador:" << val << endl;
            Elem elem = {.tipo = OP, .val = val};
            elems.push(elem);
        }else{
            if(isalpha(s.at(i)) || isdigit(s.at(i))){
                buffer.append(s.substr(i,1));
            }
        }
    }
    if(!buffer.empty()){
        //Revisar y vaciar el buffer
        //cout << "Número" << obtenerVariable(buffer) << endl;
        Elem num = {.tipo = NUM, .val = obtenerVariable(buffer)};
        elems.push(num);
        buffer.clear();
    }
    return elems;
}
//Función que implementa el algoritmo Shunting-yard para pasar de notación
//'infix' a notación 'postfix' o notación polaca inversa
queue<Elem> aNPI(queue<Elem> elems){
    queue<Elem> expr;
    stack<Elem> ops;
    Elem e;
    //Comienza a vaciar la cola de elementos
    while(!elems.empty()){
        e = elems.front();
        if(e.tipo == NUM){
            expr.push(e);
        }
        if(e.tipo == OP){
            if(ops.empty()){
                ops.push(e);
            }else{
                //Si llega a un parentesis derecho, comienza a sacar operadores
                //de 'ops' hasta llegar al parentesis izquierdo
                if(e.val == PAR_D){
                    while(ops.top().val != PAR_I){
                        expr.push(ops.top());
                        ops.pop();
                    }
                    ops.pop();
                }
                else if(e.val == PAR_I){
                    ops.push(e);
                }else{
                    //Sí el operador que ingresa tiene un orden menor o igual al que esta a la
                    //cabeza de 'ops', saca operadores hasta llegar a uno mayor
                    while(!ops.empty() && ordenOperacion(ops.top().val) <= ordenOperacion(e.val)){
                        expr.push(ops.top());
                        ops.pop();
                    }
                    ops.push(e);
                }
            }
        }
        elems.pop();
    }
    while(!ops.empty()){
        expr.push(ops.top());
        ops.pop();
    }
    return expr;
}
int evaluar(queue<Elem> expr){
    stack<int> res;
    Elem e;
    while(!expr.empty()){
        e = expr.front();
        int val1,val2 = val1 = 0;
        if(e.tipo == NUM){
            res.push(e.val);
        }
        if(e.tipo == OP){
            //El primer valor es el segundo en la evaluación porque en la
            //expresión sería el que se encontraba a la derecha
            val2 = res.top();
            res.pop();
            val1 = res.top();
            res.pop();
            res.push(operar(e.val,val1,val2));
        }
        expr.pop();
    }
    return res.top();
}
int evaluarExpr(string s){
    queue<Elem> elems = aNPI(dividirCadena(s));
    return evaluar(elems);
}
