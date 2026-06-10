#include <stdio.h>
#include <string.h>
#include "gerente.h"

Funcionario funcionarios[MAX_FUNCIONARIOS];
int totalFuncionarios = 0;

void cadastrarRecepcionista() {

if(totalFuncionarios >= MAX_FUNCIONARIOS) {

    printf("\n=================================\n");
    printf("ERRO: Limite maximo de %d funcionarios atingido!\n",
           MAX_FUNCIONARIOS);
    printf("Nao e possivel realizar novos cadastros.\n");
    printf("=================================\n");

    return;
}

    strcpy(funcionarios[totalFuncionarios].nome, "Recepcionista");
    strcpy(funcionarios[totalFuncionarios].cargo, "Recepcionista");

    totalFuncionarios++;

    printf("Recepcionista cadastrada com sucesso!\n");
}

void cadastrarPersonal() {

    if(totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("\n=================================\n");
        printf("ERRO: Limite maximo de %d funcionarios atingido!\n",
               MAX_FUNCIONARIOS);
        printf("Nao e possivel realizar novos cadastros.\n");
        printf("=================================\n");
        return;
    }

    strcpy(funcionarios[totalFuncionarios].nome, "Personal");
    strcpy(funcionarios[totalFuncionarios].cargo, "Personal Trainer");

    totalFuncionarios++;

    printf("Personal Trainer cadastrado com sucesso!\n");
}

void listarFuncionarios() {

    if(totalFuncionarios == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    printf("\n=== Funcionarios Cadastrados ===\n");

    for(int i = 0; i < totalFuncionarios; i++) {
        printf("%d - %s (%s)\n",
               i + 1,
               funcionarios[i].nome,
               funcionarios[i].cargo);
    }
}

void menuGerente() {

    int opcao;

    do {

        printf("\n=================================\n");
        printf("       MENU DO GERENTE\n");
        printf("=================================\n");
        printf("1 - Cadastrar Recepcionista\n");
        printf("2 - Cadastrar Personal Trainer\n");
        printf("3 - Listar Funcionarios\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                cadastrarRecepcionista();
                break;

            case 2:
                cadastrarPersonal();
                break;

            case 3:
                listarFuncionarios();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("\nOpcao invalida! Escolha uma opcao entre 0 e 3.\n");
        }

    } while(opcao != 0);
}