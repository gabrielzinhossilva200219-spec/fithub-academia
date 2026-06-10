#ifndef PERSONAL_H
#define PERSONAL_H

#include <stdio.h>
#include <string.h>

/* Estrutura do treino */
typedef struct {
    char nome_aluno[100];
    char exercicio[100];
    int peso;
    int repeticoes;
    int series;
} Treino;

/* funções do sistema */
void cadastrarTreino();
void listarTreinos();
void menuPersonal();

#endif