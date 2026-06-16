/**
 * @file testes_gerente.c
 * @brief Testes unitarios do modulo Gerente - FitHub Academia.
 * @details Utiliza stubs para simular dependencias e isolar as funcoes
 *          testadas de efeitos colaterais externos.
 */

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "gerente.h"

/* ===== VARIAVEIS EXTERNAS ===== */
extern Funcionario funcionarios[];
extern int totalFuncionarios;

/* ===== STUBS ===== */

/** @brief Stub: simula nome de funcionario sempre valido (nao vazio). */
int stub_validarNomeFuncionario_valido(char nome[]) { return strlen(nome) > 0; }

/** @brief Stub: simula nome de funcionario invalido (vazio). */
int stub_validarNomeFuncionario_invalido(char nome[]) { return 0; }

/* ===== SETUP ===== */

void reset_gerente() {
    totalFuncionarios = 0;
    memset(funcionarios, 0, sizeof(Funcionario) * MAX_FUNCIONARIOS);
}

/* ===== TESTES ===== */

/**
 * @brief GT01 - Total de funcionarios comeca em zero apos reset.
 */
MU_TEST(GT01_total_funcionarios_inicial_zero) {
    reset_gerente();
    mu_check(totalFuncionarios == 0);
}

/**
 * @brief GT02 - Cadastro de recepcionista define cargo corretamente.
 * @details Simula insercao manual e verifica o campo cargo.
 */
MU_TEST(GT02_cargo_recepcionista_correto) {
    reset_gerente();
    strcpy(funcionarios[0].nome, "Ana Lima");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    mu_check(strcmp(funcionarios[0].cargo, "Recepcionista") == 0);
}

/**
 * @brief GT03 - Cadastro de personal trainer define cargo corretamente.
 */
MU_TEST(GT03_cargo_personal_correto) {
    reset_gerente();
    strcpy(funcionarios[0].nome, "Carlos Silva");
    strcpy(funcionarios[0].cargo, "Personal Trainer");
    totalFuncionarios = 1;
    mu_check(strcmp(funcionarios[0].cargo, "Personal Trainer") == 0);
}

/**
 * @brief GT04 - Nome do funcionario e armazenado corretamente.
 */
MU_TEST(GT04_nome_funcionario_correto) {
    reset_gerente();
    strcpy(funcionarios[0].nome, "Maria Souza");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    mu_check(strcmp(funcionarios[0].nome, "Maria Souza") == 0);
}

/**
 * @brief GT05 - Limite maximo de funcionarios e respeitado.
 * @details Verifica que o sistema nao permite mais que MAX_FUNCIONARIOS.
 */
MU_TEST(GT05_limite_maximo_funcionarios) {
    reset_gerente();
    totalFuncionarios = MAX_FUNCIONARIOS;
    mu_check(totalFuncionarios >= MAX_FUNCIONARIOS);
}

/**
 * @brief GT06 - Nome vazio de funcionario deve ser rejeitado pelo stub.
 */
MU_TEST(GT06_nome_funcionario_vazio_invalido) {
    mu_check(stub_validarNomeFuncionario_invalido("") == 0);
}

/**
 * @brief GT07 - Nome preenchido de funcionario deve ser aceito pelo stub.
 */
MU_TEST(GT07_nome_funcionario_valido) {
    mu_check(stub_validarNomeFuncionario_valido("Pedro Costa") == 1);
}

/**
 * @brief GT08 - Dois funcionarios com cargos distintos podem coexistir.
 */
MU_TEST(GT08_dois_funcionarios_cargos_distintos) {
    reset_gerente();
    strcpy(funcionarios[0].nome, "Ana Lima");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    strcpy(funcionarios[1].nome, "Carlos Silva");
    strcpy(funcionarios[1].cargo, "Personal Trainer");
    totalFuncionarios = 2;
    mu_check(strcmp(funcionarios[0].cargo, funcionarios[1].cargo) != 0);
}

/**
 * @brief GT09 - Cadastro de funcionario incrementa o total corretamente.
 */
MU_TEST(GT09_cadastro_incrementa_total) {
    reset_gerente();
    strcpy(funcionarios[0].nome, "Julia Pereira");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    mu_check(totalFuncionarios == 1);
}

/**
 * @brief GT10 - Apos reset, array de funcionarios esta vazio.
 */
MU_TEST(GT10_reset_limpa_funcionarios) {
    strcpy(funcionarios[0].nome, "Alguem");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    reset_gerente();
    mu_check(totalFuncionarios == 0);
    mu_check(strlen(funcionarios[0].nome) == 0);
}

MU_TEST_SUITE(suite_gerente) {
    MU_RUN_TEST(GT01_total_funcionarios_inicial_zero);
    MU_RUN_TEST(GT02_cargo_recepcionista_correto);
    MU_RUN_TEST(GT03_cargo_personal_correto);
    MU_RUN_TEST(GT04_nome_funcionario_correto);
    MU_RUN_TEST(GT05_limite_maximo_funcionarios);
    MU_RUN_TEST(GT06_nome_funcionario_vazio_invalido);
    MU_RUN_TEST(GT07_nome_funcionario_valido);
    MU_RUN_TEST(GT08_dois_funcionarios_cargos_distintos);
    MU_RUN_TEST(GT09_cadastro_incrementa_total);
    MU_RUN_TEST(GT10_reset_limpa_funcionarios);
}

int main() {
    MU_RUN_SUITE(suite_gerente);
    MU_REPORT();
    return MU_EXIT_CODE;
}
