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

int validarData(char data[]);
int validarData(char data[]) {

    int dia;
    int mes;
    int ano;

    sscanf(data,"%d/%d/%d",&dia,&mes,&ano);

    if(dia < 1 || dia > 31)
        return 0;

    if(mes < 1 || mes > 12)
        return 0;

    return 1;
}

if(!validarData(alunos[totalAlunos].dataNascimento)) {

    printf("Data invalida!\n");

    return;
}
int validarEmail(char email[]);
int validarEmail(char email[]) {

    return strstr(email,"@") &&
           strstr(email,".com");
}

if(!validarEmail(alunos[totalAlunos].email)) {

    printf("Email invalido!\n");

    return;
}

int validarTelefone(char telefone[]);
int validarLaudo(char laudo[]);
int validarTelefone(char telefone[]) {

    return strlen(telefone) == 11;
}

int validarLaudo(char laudo[]) {

    return strlen(laudo) > 0;
}

if(!validarTelefone(alunos[totalAlunos].telefone)) {

    printf("Telefone invalido!\n");

    return;
}

if(!validarLaudo(alunos[totalAlunos].laudo)) {

    printf("Laudo invalido!\n");

    return;
}
nt cpfExiste(char cpf[]);
int cpfExiste(char cpf[]) {

    for(int i = 0; i < totalAlunos; i++) {

        if(strcmp(alunos[i].cpf, cpf) == 0)
            return 1;
    }

    return 0;
}

if(cpfExiste(alunos[totalAlunos].cpf)) {

    printf("CPF ja cadastrado!\n");

    return;
}

void menuRecepcionista();
void menuRecepcionista() {

    int opcao;

    do {

        printf("\n===== RECEPCIONISTA =====\n");

        printf("1 - Cadastrar aluno\n");
        printf("0 - Sair\n");

        scanf("%d",&opcao);

        switch(opcao) {

            case 1:
                cadastrarAluno();
                break;
        }

    } while(opcao != 0);
}

if(totalAlunos >= MAX_ALUNOS) {

    printf("Limite de alunos atingido!\n");

    return;
}