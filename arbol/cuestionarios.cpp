#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "cuestionarios.h"
#include "expr.h"
using namespace std;

std::string CUEST_AREAS_DIR = "cuestionarios/Cuestionario1.csv";
std::string CUEST_FM_DIR = "cuestionarios/Cuestionario2_FM.csv";
std::string CUEST_MB_DIR = "cuestionarios/Cuestionario2_MB.csv";
std::string CUEST_SA_DIR = "cuestionarios/Cuestionario2_SA.csv";

void errorAbrirCuestionario(string);

void insertarVar(char *apu, int dato_ext,vector<variable*> &vc){
    int i;
    for(i = 0;i < vc.size();i++){
        if(vc[i]->area == apu){
            vc[i]->valor += dato_ext;
            return;
        }
    }
    vc.push_back(new variable(apu,dato_ext));
}
vector<variable*> aplicarCuestionario(FILE *archivo){
    vector<variable*> vars;
    int opc,
        valor,
        ng,
        mi,
        mg;
    char renglon[100],
    aux[4],
    *apu;
    //areas lista_areas;
    //areas_cola cola_areas;
    apu_variable aux_apu;
    while(fgets(renglon, 100, archivo)){

        apu = strtok(renglon, ",");

        printf("\n%s \n", apu);
        printf( "\t1. No Me Gusta\n"
                "\t2. Me es Indiferentes\n"
                "\t3. Me Gusta\n"
                "\tOpcion: ");

        apu = strtok(NULL, ",");
        ng = atoi(apu);
        apu = strtok(NULL, ",");
        mi = atoi(apu);
        apu = strtok(NULL, ",");
        mg = atoi(apu);
        apu = strtok(NULL, "\n");
        //falta para variable de que area es
        scanf("%d", &opc);
        //remover saltos de línea
        apu[strcspn(apu, "\r")] = 0;

        switch(opc){

            case 1:
                insertarVar(apu,ng,vars);//lista_areas.insertar_a(apu, ng);
                break;


            case 2:
                insertarVar(apu,mi,vars);//lista_areas.insertar_a(apu, mi);
                break;


            case 3:
                insertarVar(apu,mg,vars);//lista_areas.insertar_a(apu, mg);
                break;

        }

    }
    return vars;
}
void aplicarCuestionario1(){
    vector<variable*> vars;
    FILE *f = fopen(CUEST_AREAS_DIR.c_str(),"r");
    if(!f)
        errorAbrirCuestionario(CUEST_AREAS_DIR);
    vars = aplicarCuestionario(f);
    agregarSimbolos(vars);
}
void aplicarCuestionarioFM(){
    vector<variable*> vars;
    FILE *f = fopen(CUEST_FM_DIR.c_str(),"r");
    if(!f)
        errorAbrirCuestionario(CUEST_FM_DIR);
    vars = aplicarCuestionario(f);
    agregarSimbolos(vars);
}
void aplicarCuestionarioSA(){
    vector<variable*> vars;
    FILE *f = fopen(CUEST_SA_DIR.c_str(),"r");
    if(!f)
        errorAbrirCuestionario(CUEST_SA_DIR);
    vars = aplicarCuestionario(f);
    agregarSimbolos(vars);
}
void aplicarCuestionarioMB(){
    vector<variable*> vars;
    FILE *f = fopen(CUEST_MB_DIR.c_str(),"r");
    if(!f)
        errorAbrirCuestionario(CUEST_AREAS_DIR);
    vars = aplicarCuestionario(f);
    agregarSimbolos(vars);
}

void errorAbrirCuestionario(string s){
    cout << "Error al abir el cuestionario " << s << endl;
        exit(EXIT_FAILURE);
}
