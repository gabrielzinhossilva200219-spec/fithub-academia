#include <stdio.h>
#include <string.h>
#include "gerente.h"

Funcionario funcionarios[MAX_FUNCIONARIOS];
int totalFuncionarios = 0;

void cadastrarRecepcionista() {

    if(totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionarios atingido!\n");
        return;
    }

    strcpy(funcionarios[totalFuncionarios].nome, "Recepcionista");
    strcpy(funcionarios[totalFuncionarios].cargo, "Recepcionista");

    totalFuncionarios++;

    printf("Recepcionista cadastrada com sucesso!\n");
}

void cadastrarPersonal() {

    if(totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionarios atingido!\n");
        return;
    }

    strcpy(funcionarios[totalFuncionarios].nome, "Personal");
    strcpy(funcionarios[totalFuncionarios].cargo, "Personal Trainer");

    totalFuncionarios++;

    printf("Personal Trainer cadastrado com sucesso!\n");
}

void listarFuncionarios() {

}

void menuGerente() {

}