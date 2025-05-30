#include <stdio.h>
#include "jogo.h"
#include "estruturas.h"
#include "pistas.h"
#include "save_load.h"

int main() {
    Jogador jogador = {0};
    jogador.local_jogador = 0;
    jogador.qtd_provas_coletadas = 0;

    inicializar_jogo();
    criar_threads_npcs();

    int opcao;
    int sair = 0;

    while (!sair) {
        mostrar_comodo(jogador.local_jogador);
        mostrar_pistas_do_comodo(jogador.local_jogador);

        printf("\nAções:\n1-Mover\n2-Interrogar\n3-Acusar\n4-Salvar\n5-Carregar\n0-Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("Digite ID do cômodo destino: ");
                int dest; scanf("%d", &dest);
                Comodo *c = &comodos[jogador.local_jogador];
                int valido = 0;
                for (int i = 0; i < c->qtd_vizinhos; i++) {
                    if (c->vizinhos[i] == dest) {
                        valido = 1;
                        break;
                    }
                }
                if (valido) {
                    jogador.local_jogador = dest;
                } else {
                    printf("Movimento inválido.\n");
                }
                break;
            }
            case 2: {
                printf("Digite ID do NPC para interrogar: ");
                int npc_id; scanf("%d", &npc_id);
                interrogar_npc(npc_id, &jogador);
                break;
            }
            case 3: {
                printf("Digite ID do NPC para acusar: ");
                int npc_id; scanf("%d", &npc_id);
                if (acusar_npc(npc_id, &jogador)) sair = 1;
                break;
            }
            case 4:
                salvar_jogo(&jogador);
                break;
            case 5:
                carregar_jogo(&jogador);
                break;
            case 0:
                sair = 1;
                break;
            default:
                printf("Opção inválida.\n");
        }
    }

    destruir_threads_npcs();
    printf("Obrigado por jogar!\n");
    return 0;
}
