#ifndef NODOABIN_H
#define NODOABIN_H

#include <string>
#include <vector>
class Carrera{
    public:
        int idGrupo;
        std::string nombre;
        std::vector<std::string> plant;
        Carrera(){}
        Carrera(int idGpo,std::string nom,std::vector<std::string> plant){
            this->idGrupo = idGpo;
            this->nombre = nom;
            this->plant = plant;
        }
};
class GpoCarreras{
    public:
    int idGrupo;
    std::vector<Carrera*> carreras;
    GpoCarreras(){}
    GpoCarreras(int id){this->idGrupo = id;}
};

class NABin{
    public:
        GpoCarreras *val;
        NABin *izq;
        NABin *der;
        NABin(GpoCarreras *c){
            val = c;
            izq = NULL;
            der = NULL;
        }
};
#endif
