/**
 * @file main.c
 * @brief Ponto de entrada do sistema FitHub Academia.
 * @details Exibe o menu principal e direciona para os módulos
 *          de Gerente, Recepcionista e Personal Trainer.
 */

#include <stdio.h>

#include "gerente.h"
#include "recepcionista.h"
#include "personal.h"

/**
 * @brief Função principal do sistema.
 * @return 0 em caso de execução bem-sucedida.
 */
int main(void)
{
    int opcao;

    do
    {
        printf("\n=================================\n");
        printf("         SISTEMA FITHUB\n");
        printf("=================================\n");
        printf("1 - Menu Gerente\n");
        printf("2 - Menu Recepcionista\n");
        printf("3 - Menu Personal Trainer\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                menuGerente();
                break;

            case 2:
                menuRecepcionista();
                break;

            case 3:
                menuPersonal();
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}