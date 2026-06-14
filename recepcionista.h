#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H

#define MAX_ALUNOS 100

typedef struct {

    char nome[100];
    char cpf[12];
    char dataNascimento[11];
    char email[100];
    char telefone[12];
    char laudo[50];

    int faltas;

} Aluno;

#endif