#ifndef CUESTIONARIOS_H
#define CUESTIONARIOS_H
#include <string>
class variable{
    public:
        std::string area;
        int valor;
        variable *siguiente;
        variable(){}
        variable(std::string a,int v){
            this->area = a;
            this->valor = v;
        }
};
typedef variable *apu_variable;
void aplicarCuestionario1();
void aplicarCuestionarioMB();
void aplicarCuestionarioSA();
void aplicarCuestionarioFM();
#endif
