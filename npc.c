#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "npc.h"
#include "comodos.h"

extern NPC npcs[MAX_NPCS];
extern Comodo comodos[MAX_COMODOS];

pthread_t threads_npcs[MAX_NPCS];
sem_t sem_comodos[MAX_COMODOS];

void* thread_npc(void* arg) {
    int npc_id = *(int*)arg;
    free(arg);

    while (1) {
        // Simula movimento aleatório entre cômodos vizinhos
        int atual = npcs[npc_id].local_atual;
        Comodo *c = &comodos[atual];
        if (c->qtd_vizinhos == 0) {
            sleep(1);
            continue;
        }
        int novo = c->vizinhos[rand() % c->qtd_vizinhos];

        // Tenta entrar no cômodo novo
        sem_wait(&sem_comodos[novo]);
        sem_post(&sem_comodos[atual]);

        npcs[npc_id].local_atual = novo;
        sleep(5); // espera entre movimentos
    }

    return NULL;
}

void iniciar_threads_npcs(void) {
    for (int i = 0; i < MAX_COMODOS; i++) {
        sem_init(&sem_comodos[i], 0, 1);
    }
    for (int i = 0; i < MAX_NPCS; i++) {
        // Tenta ocupar cômodo inicial
        sem_wait(&sem_comodos[npcs[i].local_atual]);
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads_npcs[i], NULL, thread_npc, id);
    }
}

void finalizar_threads_npcs(void) {
    for (int i = 0; i < MAX_NPCS; i++) {
        pthread_cancel(threads_npcs[i]);
        pthread_join(threads_npcs[i], NULL);
        sem_post(&sem_comodos[npcs[i].local_atual]);
    }
    for (int i = 0; i < MAX_COMODOS; i++) {
        sem_destroy(&sem_comodos[i]);
    }
}
