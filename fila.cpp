#include "fila.h"
#include <iostream>
#include <string>
#define MAX_LIMIT 12

using namespace std;

filaTrip:: filaTrip(): numElement{1}, max{MAX_LIMIT} {
    //inicializando o nó header;
    Tripulante* capitao = new Tripulante("capitao");
    Header = new Node(*capitao);
    Header->dir = Header;
    Header->esq = Header;
}

filaTrip:: ~filaTrip(){
    destroi();
}

void filaTrip:: destroi(){
    Node* atual = Header;
    Node* proximo = nullptr;

    while(atual!= nullptr){
        proximo = atual->dir;
        delete atual;
        atual = proximo;
    }

    Header = nullptr;
    numElement = 0;
}

bool filaTrip:: haveMedico(Node* &atual){
    if(isVazia()){
        return false;
    }

    atual = Header->dir;

    while(atual!=Header && atual->tripulante.funcao != "medico"){
        atual = atual->dir;
    }

    return(atual!=Header);
}

bool filaTrip:: haveCacador(Node* &atual){
    if(isVazia()){
        return false;
    }

    atual = Header->dir;

    while(atual!=Header && atual->tripulante.funcao != "cacador"){
        atual = atual->dir;
    }

    return(atual!=Header);
}

bool filaTrip:: retira(){
    if(isVazia()){
        cout << "A fila está vazia, impossivel retirar";
        return false;
    }

    Node* atual = nullptr;
    if(haveMedico(atual)){
        atual->esq->dir = atual->dir;
        atual->dir->esq = atual->esq;
        delete atual;
        atual = nullptr;
        numElement--;

        return true;
    }

    if(haveCacador(atual)){
        atual->esq->dir = atual->dir;
        atual->dir->esq = atual->esq;
        delete atual;
        atual = nullptr;
        numElement--;

        return true;
    }

    //se não tem caçador nem médico, retira o primeiro elemento
    atual = Header->dir;
    Header->dir = atual->dir;
    atual->dir->esq = atual->esq;
    delete atual;
    atual = nullptr;
    numElement--;
    return true;
}

bool filaTrip:: enfileirar(Tripulante& novoMarujo){
    if(isCheia()){
        cout << "A fila está cheia, não foi possivel inserir";
        return false;
    }

    Node* novoNo = new Node(novoMarujo);
    
    if(isVazia()){
        Header->dir = novoNo;
        Header->esq = novoNo;
        novoNo->dir = Header;
        novoNo->esq = Header;
    }
    else{
        Node* ultimoElemento = Header->esq;
        ultimoElemento->dir=novoNo;
        novoNo->esq = ultimoElemento;
        novoNo->dir = Header;
        Header->esq = novoNo;
    }
    numElement++;
    novoNo = nullptr;
    return true;
}

int filaTrip:: getNumElement() const {
    return numElement;
}

bool filaTrip:: isVazia() const{
    return (numElement == 0);
}

bool filaTrip:: isCheia() const{
    return (numElement >= max);
}

//funções para teste
Node* filaTrip::getInicio() const {
    if (!isVazia()) {
        return Header->dir;
    } else {
        return nullptr;
    }
}

Node* filaTrip::getHeader() const {
    return Header;
}

void filaTrip:: exibirOrdemFila() const{
    if (isVazia()) {
        cout << "A fila esta vazia." << endl;
    } else {
        Node* atual = getInicio();
        cout << "A fila esta cheia? " << (isCheia() ? "Sim" : "Nao") << endl;
        cout << "Numero de elementos na fila: " << getNumElement() << endl;
        cout << "Ordem dos tripulantes na fila: " << Header->tripulante.funcao << " ";
        while (atual != getHeader()) {
            cout << atual->tripulante.funcao << " ";
            atual = atual->dir;
        }
        cout << endl;
        
    }
}