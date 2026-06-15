#ifndef PERSONAL_H
#define PERSONAL_H

#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura que representa um treino associado a um aluno.
 */ 

typedef struct {
    char cpf_aluno[12];
    char exercicio[100];
    int peso;
    int repeticoes;
    int series;
} Treino;

/**
 * @brief Cadastra um novo treino associado a um aluno pelo CPF.
 */

void cadastrarTreino();

/**
 * @brief Lista todos os treinos cadastrados no sistema.
 */

void listarTreinos();

/**
 * @brief Busca um treino pelo CPF do aluno.
 * @param cpf String contendo o CPF do aluno.
 * @return Ponteiro para o Treino encontrado, ou NULL se nao existir.
 */

Treino* buscarTreinoPorCPF(char cpf[]);

/**
 * @brief Exibe e controla o menu do personal trainer.
 */

void menuPersonal();

#endif