#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H

#include <string.h>

#define MAX_ALUNOS 100

/**
 * @brief Estrutura que representa um aluno cadastrado no sistema.
 */
typedef struct
{
    char nome[100];           /**< Nome completo do aluno */
    char cpf[12];             /**< CPF do aluno (11 digitos sem pontuacao) */
    char dataNascimento[11];  /**< Data de nascimento no formato dd/mm/aaaa */
    char email[100];          /**< Endereco de email do aluno */
    char telefone[12];        /**< Telefone com DDD (11 digitos) */
    char laudo[50];           /**< Laudo medico do aluno */
    int faltas;               /**< Contador de faltas do aluno */
} Aluno;

/**
 * @brief Valida se o nome nao e vazio.
 * @param nome String contendo o nome a ser validado.
 * @return 1 se valido, 0 se invalido.
 */
int validarNome(char nome[]);

/**
 * @brief Valida se o CPF possui exatamente 11 digitos.
 * @param cpf String contendo o CPF a ser validado.
 * @return 1 se valido, 0 se invalido.
 */
int validarCPF(char cpf[]);

/**
 * @brief Valida se a data esta no formato dd/mm/aaaa com valores coerentes.
 * @param data String contendo a data a ser validada.
 * @return 1 se valida, 0 se invalida.
 */
int validarData(char data[]);

/**
 * @brief Valida se o email contem '@' e '.com'.
 * @param email String contendo o email a ser validado.
 * @return 1 se valido, 0 se invalido.
 */
int validarEmail(char email[]);

/**
 * @brief Valida se o telefone possui exatamente 11 digitos.
 * @param telefone String contendo o telefone a ser validado.
 * @return 1 se valido, 0 se invalido.
 */
int validarTelefone(char telefone[]);

/**
 * @brief Valida se o laudo medico nao e vazio.
 * @param laudo String contendo o laudo a ser validado.
 * @return 1 se valido, 0 se invalido.
 */
int validarLaudo(char laudo[]);

/**
 * @brief Verifica se um CPF ja esta cadastrado no sistema.
 * @param cpf String contendo o CPF a ser verificado.
 * @return 1 se ja existe, 0 se nao existe.
 */
int cpfExiste(char cpf[]);

/**
 * @brief Cadastra um novo aluno apos validar todos os campos.
 */
void cadastrarAluno();

/**
 * @brief Exclui um aluno pelo CPF.
 */
void excluirAluno();

/**
 * @brief Consulta o numero de faltas de um aluno pelo CPF.
 */
void consultarFaltas();

/**
 * @brief Registra uma falta para um aluno pelo CPF.
 */
void registrarFalta();

/**
 * @brief Registra a entrada (check-in) de um aluno pelo CPF.
 */
void registrarEntrada();

/**
 * @brief Exibe e controla o menu da recepcionista.
 */
void menuRecepcionista();

#endif