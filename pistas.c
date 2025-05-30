#include <stdio.h>
#include <string.h>
#include "pistas.h"

static Pista pistas[MAX_PISTAS];
static int total_pistas = 0;

void adicionar_pista(int npc_id, int comodo_id, const char *texto) {
    if (total_pistas < MAX_PISTAS) {
        pistas[total_pistas].id = total_pistas;
        pistas[total_pistas].npc_origem = npc_id;
        pistas[total_pistas].comodo_local = comodo_id;
        strncpy(pistas[total_pistas].texto, texto, 255);
        pistas[total_pistas].texto[255] = '\0';
        total_pistas++;
    }
}

void inicializar_pistas(void) {
    adicionar_pista(0, 0, "João comenta: Vi a Maria saindo da cozinha rápido.");
    adicionar_pista(1, 1, "Maria diz: Vi o Carlos perto do hall, parecia nervoso.");
    // Continue adicionando...
}

void mostrar_pistas_do_comodo(int comodo_id) {
    printf("\nPistas encontradas nesse cômodo:\n");
    int found = 0;
    for (int i = 0; i < total_pistas; i++) {
        if (pistas[i].comodo_local == comodo_id) {
            printf("- %s\n", pistas[i].texto);
            found = 1;
        }
    }
    if (!found) {
        printf("Nenhuma pista encontrada aqui.\n");
    }
}
