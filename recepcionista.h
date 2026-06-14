#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H

#include <string.h>

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

int validarNome(char nome[]);
int validarCPF(char cpf[]);
int validarData(char data[]);
int validarEmail(char email[]);
int validarTelefone(char telefone[]);
int validarLaudo(char laudo[]);
int cpfExiste(char cpf[]);

void cadastrarAluno();
void excluirAluno();
void consultarFaltas();
void registrarFalta();
void registrarEntrada();
void menuRecepcionista();

#endif