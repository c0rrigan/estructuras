#ifndef NODOCOLA_H
#define NODOCOLA_H
class NodoCola{
    public:
        Nodo *val;
        NodoCola *rel;
        NodoCola(){val = NULL;rel = NULL;}
        NodoCola(Nodo *s){val = s;rel = NULL;}
};
#endif
