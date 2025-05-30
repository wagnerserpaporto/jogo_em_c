#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define MAX_COMODOS 6
#define MAX_VIZINHOS 4
#define MAX_NPCS 6
#define MAX_ARMAS 6
#define MAX_PROVAS 10
#define MAX_PISTAS 20

typedef struct {
    int id;
    char nome[50];
    char descricao[256];
    int vizinhos[MAX_VIZINHOS];
    int qtd_vizinhos;
} Comodo;

typedef struct {
    int id;
    char nome[50];
    int local_atual;
    int suspeito;
} NPC;

typedef struct {
    int id;
    char nome[50];
    char descricao[256];
} Arma;

typedef struct {
    int id;
    char descricao[256];
    int ligada_arma;
    int ligada_comodo;
} Prova;

typedef struct {
    int id;
    char texto[256];
    int npc_origem;
    int comodo_local;
} Pista;

typedef struct {
    int local_jogador;
    int provas_coletadas[MAX_PROVAS];
    int qtd_provas_coletadas;
} Jogador;

#endif
