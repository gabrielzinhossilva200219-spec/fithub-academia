#ifndef GERENTE_H
#define GERENTE_H

#define MAX_FUNCIONARIOS 10

typedef struct {
    char nome[100];
    char cargo[30];
} Funcionario;

void cadastrarRecepcionista();
void cadastrarPersonal();
void listarFuncionarios();
void menuGerente();

#endif