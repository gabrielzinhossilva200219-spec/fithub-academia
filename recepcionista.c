/**
 * @file recepcionista.c
 * @brief Implementacao das funcoes do modulo recepcionista.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "recepcionista.h"

Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;



void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarTela()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

/**
 * @brief Valida se o nome nao e vazio.
 * @param nome String a ser validada.
 * @return 1 se valido, 0 se invalido.
 */
int validarNome(char nome[])
{
    return strlen(nome) > 0;
}

/**
 * @brief Valida se o CPF possui exatamente 11 digitos.
 * @param cpf String a ser validada.
 * @return 1 se valido, 0 se invalido.
 */
int validarCPF(char cpf[])
{
    return strlen(cpf) == 11;
}

/**
 * @brief Valida se a data esta no formato dd/mm/aaaa com valores coerentes.
 * @param data String a ser validada.
 * @return 1 se valida, 0 se invalida.
 */
int validarData(char data[])
{
    int dia, mes, ano;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
        return 0;

    if (dia < 1 || dia > 31)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    return 1;
}

/**
 * @brief Valida se o email contem '@' e '.com'.
 * @param email String a ser validada.
 * @return 1 se valido, 0 se invalido.
 */
int validarEmail(char email[])
{
    return strstr(email, "@") != NULL &&
           strstr(email, ".com") != NULL;
}

/**
 * @brief Valida se o telefone possui exatamente 11 digitos.
 * @param telefone String a ser validada.
 * @return 1 se valido, 0 se invalido.
 */
int validarTelefone(char telefone[])
{
    return strlen(telefone) == 11;
}

/**
 * @brief Valida se o laudo medico nao e vazio.
 * @param laudo String a ser validada.
 * @return 1 se valido, 0 se invalido.
 */
int validarLaudo(char laudo[])
{
    return strlen(laudo) > 0;
}

/**
 * @brief Verifica se um CPF ja esta cadastrado.
 * @param cpf String contendo o CPF a verificar.
 * @return 1 se ja existe, 0 se nao existe.
 */
int cpfExiste(char cpf[])
{
    for (int i = 0; i < totalAlunos; i++)
    {
        if (strcmp(alunos[i].cpf, cpf) == 0)
            return 1;
    }

    return 0;
}

/**
 * @brief Cadastra um novo aluno no sistema.
 * @details Solicita todos os dados ao usuario e aplica as validacoes
 *          antes de inserir o aluno no array. O CPF e verificado
 *          para evitar duplicatas.
 */
void cadastrarAluno()
{
    if (totalAlunos >= MAX_ALUNOS)
    {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno novo;
    novo.faltas = 0;

    printf("Nome: ");
    scanf(" %99[^\n]", novo.nome);

    if (!validarNome(novo.nome))
    {
        printf("Nome invalido!\n");
        return;
    }

    printf("CPF (11 digitos, sem pontos): ");
    scanf("%11s", novo.cpf);

    if (!validarCPF(novo.cpf))
    {
        printf("CPF invalido! Digite 11 digitos sem pontos ou traco.\n");
        return;
    }

    if (cpfExiste(novo.cpf))
    {
        printf("CPF ja cadastrado!\n");
        return;
    }

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%10s", novo.dataNascimento);

    if (!validarData(novo.dataNascimento))
    {
        printf("Data invalida!\n");
        return;
    }

    printf("Email: ");
    scanf("%99s", novo.email);

    if (!validarEmail(novo.email))
    {
        printf("Email invalido!\n");
        return;
    }

    printf("Telefone (11 digitos, com DDD): ");
    scanf("%11s", novo.telefone);

    if (!validarTelefone(novo.telefone))
    {
        printf("Telefone invalido! Digite 11 digitos com DDD.\n");
        return;
    }

    printf("Laudo medico: ");
    scanf(" %49[^\n]", novo.laudo);

    if (!validarLaudo(novo.laudo))
    {
        printf("Laudo invalido!\n");
        return;
    }

    alunos[totalAlunos] = novo;
    totalAlunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

/**
 * @brief Exclui um aluno do sistema pelo CPF.
 * @details Busca o aluno pelo CPF e o remove reorganizando o array.
 */
void excluirAluno()
{
    char cpf[12];

    printf("CPF do aluno a excluir: ");
    scanf("%11s", cpf);

    for (int i = 0; i < totalAlunos; i++)
    {
        if (strcmp(alunos[i].cpf, cpf) == 0)
        {
            for (int j = i; j < totalAlunos - 1; j++)
            {
                alunos[j] = alunos[j + 1];
            }

            totalAlunos--;

            printf("Aluno excluido com sucesso!\n");
            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

/**
 * @brief Consulta o numero de faltas de um aluno.
 * @details Busca o aluno pelo CPF e exibe o total de faltas registradas.
 */
void consultarFaltas()
{
    char cpf[12];

    printf("CPF do aluno: ");
    scanf("%11s", cpf);

    for (int i = 0; i < totalAlunos; i++)
    {
        if (strcmp(alunos[i].cpf, cpf) == 0)
        {
            printf("Aluno: %s\n", alunos[i].nome);
            printf("Faltas: %d\n", alunos[i].faltas);
            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

/**
 * @brief Registra uma falta para um aluno.
 * @details Busca o aluno pelo CPF e incrementa o contador de faltas.
 */
void registrarFalta()
{
    char cpf[12];

    printf("CPF do aluno: ");
    scanf("%11s", cpf);

    for (int i = 0; i < totalAlunos; i++)
    {
        if (strcmp(alunos[i].cpf, cpf) == 0)
        {
            alunos[i].faltas++;

            printf(
                "Falta registrada! Total de faltas: %d\n",
                alunos[i].faltas
            );

            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

/**
 * @brief Registra a entrada de um aluno (check-in).
 * @details Busca o aluno pelo CPF e confirma a entrada no sistema.
 */
void registrarEntrada()
{
    char cpf[12];

    printf("CPF do aluno: ");
    scanf("%11s", cpf);

    for (int i = 0; i < totalAlunos; i++)
    {
        if (strcmp(alunos[i].cpf, cpf) == 0)
        {
            printf("Entrada registrada para: %s\n", alunos[i].nome);
            return;
        }
    }

    printf("Aluno nao encontrado!\n");
}

/**
 * @brief Exibe e controla o menu da recepcionista.
 * @details Loop continuo ate que o usuario escolha sair (opcao 0).
 */
void menuRecepcionista()
{
    int opcao;

    do
    {
        printf("\n=================================\n");
        printf("       MENU DA RECEPCIONISTA\n");
        printf("=================================\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Excluir aluno\n");
        printf("3 - Consultar faltas\n");
        printf("4 - Registrar falta\n");
        printf("5 - Registrar entrada\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarAluno();
                break;

            case 2:
                excluirAluno();
                break;

            case 3:
                consultarFaltas();
                break;

            case 4:
                registrarFalta();
                break;

            case 5:
                registrarEntrada();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}