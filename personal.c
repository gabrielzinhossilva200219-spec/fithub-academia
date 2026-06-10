#include <stdio.h>
#include <string.h>

typedef struct {
    char nome_aluno[100];
    char exercicio[100];
    int peso;
    int repeticoes;
} Treino;

Treino treinos[100];
int totalTreinos = 0;