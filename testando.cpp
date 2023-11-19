#include "tripulante.h"
#include "node.h"
#include "fila.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Tripulante medico("medico");
    Tripulante cacador("cacador");
    Tripulante marujo("marujo");
    Tripulante arqueiro("arqueiro");
    Tripulante musico("musico");
    Tripulante cozinheiro("cozinheiro");

    filaTrip fila1;

    cout << "### Adicionando tripulantes a fila ###" << endl;
    fila1.enfileirar(marujo);
    fila1.enfileirar(cacador);
    fila1.enfileirar(medico);
    fila1.enfileirar(arqueiro);

    fila1.exibirOrdemFila();

    cout << "### Verificando a presença de um medico na fila ###" << endl;
    Node* atualMedico = nullptr;
    if (fila1.haveMedico(atualMedico)) {
        cout << "Medico encontrado na fila." << endl;
    } else {
        cout << "Medico não encontrado na fila." << endl;
    }
    cout << endl;

    cout << "### Removendo um tripulante ###" << endl;
    fila1.retira();

    fila1.exibirOrdemFila();

    cout << "### Adicionando mais tripulantes a fila ###" << endl;
    fila1.enfileirar(musico);
    fila1.enfileirar(cozinheiro);

    fila1.exibirOrdemFila();

    cout << "### Verificando a presença de um cacador na fila ###" << endl;
    Node* atualCacador = nullptr;
    if (fila1.haveCacador(atualCacador)) {
        cout << "cacador encontrado na fila." << endl;
    } else {
        cout << "cacador não encontrado na fila." << endl;
    }
    cout << endl;

    fila1.retira();

    fila1.exibirOrdemFila();

    fila1.retira();

    fila1.exibirOrdemFila();

    fila1.retira();

    fila1.exibirOrdemFila();

    cout << "### Esvaziando a fila ###" << endl;
    fila1.destroi();
    return 0;
}
