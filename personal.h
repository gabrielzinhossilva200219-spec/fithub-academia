#ifndef PERSONAL_H
#define PERSONAL_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char cpf_aluno[12];
    char exercicio[100];
    int peso;
    int repeticoes;
    int series;
} Treino;

void cadastrarTreino();
void listarTreinos();
Treino* buscarTreinoPorCPF(char cpf[]);
void menuPersonal();

#endif