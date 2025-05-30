#include <stdio.h>
#include "save_load.h"
#include "jogo.h"

extern NPC npcs[MAX_NPCS]; // Declare npcs externamente em jogo.c

void salvar_jogo(Jogador *jogador) {
    FILE *f = fopen("savegame.dat", "wb");
    if (!f) {
        perror("Erro ao salvar jogo");
        return;
    }
    fwrite(jogador, sizeof(Jogador), 1, f);
    fwrite(npcs, sizeof(NPC), MAX_NPCS, f);
    fclose(f);
    printf("Jogo salvo com sucesso.\n");
}

void carregar_jogo(Jogador *jogador) {
    FILE *f = fopen("savegame.dat", "rb");
    if (!f) {
        printf("Nenhum save encontrado.\n");
        return;
    }
    fread(jogador, sizeof(Jogador), 1, f);
    fread(npcs, sizeof(NPC), MAX_NPCS, f);
    fclose(f);
    printf("Jogo carregado com sucesso.\n");
}
