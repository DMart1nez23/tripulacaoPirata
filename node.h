//classe estruturação do nó
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include "tripulante.h"
using namespace std;

class Node{
    public:
        Tripulante tripulante;
        Node* esq;
        Node* dir;

    public:
        Node(Tripulante& tripulante): tripulante{tripulante}, esq{nullptr}, dir{nullptr} { }
        ~Node(){ }
        friend class filaTrip;
};

#endif