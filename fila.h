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
        bool retira();
        bool enfileirar(Tripulante&);
        bool haveMedico(Node* &);
        bool haveCacador(Node* &);
        int getNumElement() const;
        bool isVazia() const;
        bool isCheia() const;

        //funções teste
        Node* getInicio() const;
        Node* getHeader() const;
        void exibirOrdemFila() const;

};

#endif
