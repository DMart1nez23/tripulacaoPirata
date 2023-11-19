#ifndef TRIPULANTE_H
#define TRIPULANTE_H
#include <iostream>
#include <string>
using namespace std;

class Tripulante{
    public:
        string funcao;
    
    public:
        Tripulante(string funcaoDoTripulante): 
        funcao{funcaoDoTripulante} {}
        ~Tripulante(){}
        friend class Node;
        friend class filaTrip;
};

#endif