#ifndef GERENTE_H
#define GERENTE_H

#define MAX_FUNCIONARIOS 10

/**
 * @brief Estrutura que representa um funcionario do sistema.
 */
typedef struct
{
    char nome[100];   /**< Nome completo do funcionario */
    char cargo[30];   /**< Cargo do funcionario (Recepcionista ou Personal Trainer) */
} Funcionario;

/**
 * @brief Cadastra uma nova recepcionista solicitando o nome ao usuario.
 */
void cadastrarRecepcionista();

/**
 * @brief Cadastra um novo personal trainer solicitando o nome ao usuario.
 */
void cadastrarPersonal();

/**
 * @brief Lista todos os funcionarios cadastrados no sistema.
 */
void listarFuncionarios();

/**
 * @brief Exibe e controla o menu do gerente.
 */
void menuGerente();

#endif