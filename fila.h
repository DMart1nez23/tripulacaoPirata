#ifndef FILA_H
#define FILA_H
#include "node.h"

class filaTrip{
    private:
        Node *Header;
        int numElement;
        int max;
    public:
        filaTrip();
        ~filaTrip();
        void destroi();
        void retiraUm();
        void retiraVarios();
        void insereInicio();
        void insereMeio();
        void insereFim();
        int getNumElement();
        Node* getInicio();
        Node* getFim();
        bool isVazia() const;
        bool isCheia() const;

}

#endif
