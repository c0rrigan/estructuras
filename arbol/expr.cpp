#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
enum Operadores {PAR_I = 1,PAR_D,IGUAL,DIFERENTE,MAY,MAY_I,MEN,MEN_I,AND,OR};
enum Tipos {NUM,OP};

typedef struct Elem{
    Tipos elemTipo;
    int val;
}Elem;

using namespace std;
//Función que regresa el identificador de cada operación
int operadores(string op){
    if(!op.compare("("))
        return PAR_I;
    if(!op.compare(")"))
        return PAR_D;
    if(!op.compare("=="))
        return IGUAL;
    if(!op.compare("!="))
        return DIFERENTE;
    if(!op.compare(">"))
        return MAY;
    if(!op.compare(">="))
        return MAY_I;
    if(!op.compare("<"))
        return MEN;
    if(!op.compare("<="))
        return MEN_I;
    if(!op.compare("&"))
        return MEN;
    if(!op.compare("|"))
        return MEN_I;
    else
        return 0;
}
//Función que define el operador 
int esOperador(string s,int *index){
    int op = 0;
    //Verificar si es un operador de un solo carácter
    if(op = operadores(s.substr(*index,1))){
        (*index)++;
        //Ver si es un operador incluyente
        if(s.at(*index) == '='){
            (*index)++;
            //Finalmente se regresa con el índice despues del operador
            if(op == MAY)
                return MAY_I;
            if(op == MEN)
                return MEN_I;
        }
    }else{
        if(op = operadores(s.substr(*index,2))){
            (*index)+=2;
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
    }else{
       //Falta procesar la variable como entero 
    }
}

//Función que convierte las operaciones en 's' a notación polaca inversa
void aNPC(string s){
    queue<Elem> elems;  
    string buffer;
    int i,val;
    Elem elem;
    for(i = 0; i < s.length(); i++){
        if(val = esOperador(exp,&i)){
            elem = {.elemTipo = OP, .val = val};
        }else{
            if(isalpha(val) || isdigit(val)){
                buffer.append(val);
                //Despúes hay que agregar a 'elems' según el algoritmo 
                //http://condor.depaul.edu/ichu/csc415/notes/notes9/Infix.htm
                //Después hay que procesar la cadena que resulte con una
                //pila que realiza las operaciones en NPI
            }
        }
    }
}
int main(){
    int i = 3;
    string s = "el >= el chiste";
    cout << esOperador(s,&i) << endl;
    cout << s.substr(i) << endl;
}
