#include <stdio.h>
#include <string.h>
#include "jogo.h"
#include "comodos.h"
#include "npc.h"
#include "pistas.h"

NPC npcs[MAX_NPCS];

void inicializar_jogo(void) {
    inicializar_comodos();

    // Inicializa NPCs (exemplo)
    for (int i = 0; i < MAX_NPCS; i++) {
        npcs[i].id = i;
        snprintf(npcs[i].nome, 50, "NPC%d", i);
        npcs[i].local_atual = i % MAX_COMODOS;
        npcs[i].suspeito = (i == 2);  // Por exemplo, NPC 2 é suspeito
    }

    inicializar_pistas();
}

void mostrar_comodo(int comodo_id) {
    if (comodo_id < 0 || comodo_id >= MAX_COMODOS) return;
    Comodo *c = &comodos[comodo_id];
    printf("\nVocê está no cômodo: %s\nDescrição: %s\n", c->nome, c->descricao);
    printf("Conexões: ");
    for (int i = 0; i < c->qtd_vizinhos; i++) {
        int vid = c->vizinhos[i];
        printf("%s ", comodos[vid].nome);
    }
    printf("\n");
}

void interrogar_npc(int npc_id, Jogador *jogador) {
    if (npc_id < 0 || npc_id >= MAX_NPCS) {
        printf("NPC inválido.\n");
        return;
    }

    printf("\nInterrogando %s...\n", npcs[npc_id].nome);
    if (npcs[npc_id].suspeito) {
        printf("%s: Eu não fiz nada! Não tenho nada a ver com isso!\n", npcs[npc_id].nome);
    } else {
        printf("%s: Eu estava no %s durante o crime.\n",
            npcs[npc_id].nome, comodos[npcs[npc_id].local_atual].nome);
    }
    // Pode adicionar lógica mais complexa conforme provas coletadas
}

int acusar_npc(int npc_id, Jogador *jogador) {
    printf("\nVocê está acusando %s.\n", npcs[npc_id].nome);
    if (npcs[npc_id].suspeito) {
        printf("Parabéns! Você acertou o culpado!\n");
        return 1;
    } else {
        printf("Acusação incorreta. Continue investigando.\n");
        return 0;
    }
}

void criar_threads_npcs(void) {
    iniciar_threads_npcs();
}

void destruir_threads_npcs(void) {
    finalizar_threads_npcs();
}
