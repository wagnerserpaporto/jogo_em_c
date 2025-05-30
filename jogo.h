#ifndef JOGO_H
#define JOGO_H

#include "estruturas.h"

void inicializar_jogo(void);
void mostrar_comodo(int comodo_id);
void mostrar_pistas_do_comodo(int comodo_id);
void interrogar_npc(int npc_id, Jogador *jogador);
int acusar_npc(int npc_id, Jogador *jogador);
void criar_threads_npcs(void);
void destruir_threads_npcs(void);

#endif
