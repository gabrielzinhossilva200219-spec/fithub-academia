/**
 * @file gerente.c
 * @brief Implementacao das funcoes do modulo gerente.
 */

#include <stdio.h>
#include <string.h>

#include "gerente.h"

Funcionario funcionarios[MAX_FUNCIONARIOS];
int totalFuncionarios = 0;

/**
 * @brief Cadastra uma nova recepcionista.
 * @details Solicita o nome ao usuario e define o cargo como Recepcionista.
 *          Verifica o limite maximo de funcionarios antes de cadastrar.
 */
void cadastrarRecepcionista()
{
    if (totalFuncionarios >= MAX_FUNCIONARIOS)
    {
        printf("\n=================================\n");
        printf(
            "ERRO: Limite maximo de %d funcionarios atingido!\n",
            MAX_FUNCIONARIOS
        );
        printf("Nao e possivel realizar novos cadastros.\n");
        printf("=================================\n");
        return;
    }

    printf("Nome da recepcionista: ");
    scanf(" %99[^\n]", funcionarios[totalFuncionarios].nome);

    if (strlen(funcionarios[totalFuncionarios].nome) == 0)
    {
        printf("Nome invalido!\n");
        return;
    }

    strcpy(funcionarios[totalFuncionarios].cargo, "Recepcionista");
    totalFuncionarios++;

    printf("Recepcionista cadastrada com sucesso!\n");
}

/**
 * @brief Cadastra um novo personal trainer.
 * @details Solicita o nome ao usuario e define o cargo como Personal Trainer.
 *          Verifica o limite maximo de funcionarios antes de cadastrar.
 */
void cadastrarPersonal()
{
    if (totalFuncionarios >= MAX_FUNCIONARIOS)
    {
        printf("\n=================================\n");
        printf(
            "ERRO: Limite maximo de %d funcionarios atingido!\n",
            MAX_FUNCIONARIOS
        );
        printf("Nao e possivel realizar novos cadastros.\n");
        printf("=================================\n");
        return;
    }

    printf("Nome do Personal Trainer: ");
    scanf(" %99[^\n]", funcionarios[totalFuncionarios].nome);

    if (strlen(funcionarios[totalFuncionarios].nome) == 0)
    {
        printf("Nome invalido!\n");
        return;
    }

    strcpy(funcionarios[totalFuncionarios].cargo, "Personal Trainer");
    totalFuncionarios++;

    printf("Personal Trainer cadastrado com sucesso!\n");
}

/**
 * @brief Lista todos os funcionarios cadastrados.
 * @details Exibe nome e cargo de cada funcionario. Caso nenhum tenha sido
 *          cadastrado, exibe mensagem informativa.
 */
void listarFuncionarios()
{
    if (totalFuncionarios == 0)
    {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    printf("\n=== Funcionarios Cadastrados ===\n");

    for (int i = 0; i < totalFuncionarios; i++)
    {
        printf("%d - %s (%s)\n", i + 1, funcionarios[i].nome, funcionarios[i].cargo);
    }
}

/**
 * @brief Exibe o menu do gerente e processa as opcoes escolhidas.
 * @details Loop continuo ate que o usuario escolha sair (opcao 0).
 */
void menuGerente()
{
    int opcao;

    do
    {
        printf("\n=================================\n");
        printf("       MENU DO GERENTE\n");
        printf("=================================\n");
        printf("1 - Cadastrar Recepcionista\n");
        printf("2 - Cadastrar Personal Trainer\n");
        printf("3 - Listar Funcionarios\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
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
                printf(
                    "\nOpcao invalida! Escolha uma opcao entre 0 e 3.\n"
                );
        }

    } while (opcao != 0);
}
