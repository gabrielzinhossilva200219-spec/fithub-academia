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

int validarNome(char nome[]);
int validarCPF(char cpf[]);
recepcionista.c

int validarNome(char nome[]) {

    return strlen(nome) > 0;
}

int validarCPF(char cpf[]) {

    return strlen(cpf) == 11;
}

Dentro de cadastrarAluno():

if(!validarNome(alunos[totalAlunos].nome)) {

    printf("Nome invalido!\n");

    return;
}

if(!validarCPF(alunos[totalAlunos].cpf)) {

    printf("CPF invalido!\n");

    return;
}