#ifndef PUNTO_H
#define PUNTO_H
class Punto{
    public:
        int x;
        int y;
        Punto(int x,int y){
            this->x = x;
            this->y = y;
        }
        Punto(){
            x = -1;
            y = -1;
        }
        int comp(Punto sp){
            return (this->x == sp.x && this->y == sp.y); 
        }
        int comp(int x,int y){
            return (this->x == x && this->y == y); 
        }
        int vacio(){
            return (this->x ==-1 && this->y == -1);
        }
};
#endif
