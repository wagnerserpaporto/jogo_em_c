#ifndef PISTAS_H
#define PISTAS_H

#include "estruturas.h"

void inicializar_pistas(void);
void adicionar_pista(int npc_id, int comodo_id, const char *texto);
void mostrar_pistas_do_comodo(int comodo_id);

#endif
