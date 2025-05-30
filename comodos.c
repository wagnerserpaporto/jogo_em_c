#include <string.h>
#include "comodos.h"

Comodo comodos[MAX_COMODOS];

void inicializar_comodos(void) {
    // Exemplo simplificado — preencha com nomes e conexões reais
    comodos[0].id = 0;
    strcpy(comodos[0].nome, "Hall");
    strcpy(comodos[0].descricao, "Entrada principal da mansão.");
    comodos[0].vizinhos[0] = 1;
    comodos[0].vizinhos[1] = 2;
    comodos[0].qtd_vizinhos = 2;

    comodos[1].id = 1;
    strcpy(comodos[1].nome, "Cozinha");
    strcpy(comodos[1].descricao, "Lugar com cheiro de comida fresca.");
    comodos[1].vizinhos[0] = 0;
    comodos[1].vizinhos[1] = 3;
    comodos[1].qtd_vizinhos = 2;

    // Continue preenchendo os outros cômodos com conexões reais...
}
