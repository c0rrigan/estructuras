#ifndef NODO_H
#define NODO_H
class Nodo{
    public:
        char *val;
        Nodo *rel;
        Nodo(){val = NULL;rel = NULL;}
        Nodo(char *s){val = s;rel = NULL;}
};
#endif
