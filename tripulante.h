#ifndef TRIPULANTE_H
#define TRIPULANTE_H
#include <iostream>
#include <string>
using namespace std;

class Tripulante{
    private:
        string funcao;
    
    public:
        Tripulante(string funcaoDoTripulante): funcao{funcaoDoTripulante} {}
        ~Tripulante();
        friend class Node;
};

#endif