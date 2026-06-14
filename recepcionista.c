recepcionista.c
#include <stdio.h>
#include <string.h>

#include "recepcionista.h"

Aluno alunos[MAX_ALUNOS];

int totalAlunos = 0;

void cadastrarAluno() {

    printf("Nome: ");
    scanf(" %[^\n]", alunos[totalAlunos].nome);

    printf("CPF: ");
    scanf("%s", alunos[totalAlunos].cpf);

    printf("Data de nascimento: ");
    scanf("%s", alunos[totalAlunos].dataNascimento);

    printf("Email: ");
    scanf("%s", alunos[totalAlunos].email);

    printf("Telefone: ");
    scanf("%s", alunos[totalAlunos].telefone);

    printf("Laudo medico: ");
    scanf(" %[^\n]", alunos[totalAlunos].laudo);

    alunos[totalAlunos].faltas = 0;

    totalAlunos++;

    printf("Aluno cadastrado!\n");
}