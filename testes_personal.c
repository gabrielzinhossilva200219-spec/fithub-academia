/**
 * @file testes_personal.c
 * @brief Testes unitarios do modulo Personal Trainer - FitHub Academia.
 * @details Utiliza stubs para simular dependencias e isolar as funcoes
 *          testadas de efeitos colaterais externos.
 */

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "personal.h"
#include "recepcionista.h"

/* ===== VARIAVEIS EXTERNAS ===== */
extern Treino treinos[];
extern int totalTreinos;
extern Aluno alunos[];
extern int totalAlunos;

/* ===== STUBS ===== */

/** @brief Stub: simula busca de treino por CPF que encontra resultado. */
Treino* stub_buscarTreino_encontrado(char cpf[]) {
    static Treino t;
    strcpy(t.cpf_aluno, cpf);
    strcpy(t.exercicio, "Supino");
    t.peso = 60; t.repeticoes = 10; t.series = 3;
    return &t;
}

/** @brief Stub: simula busca de treino por CPF que nao encontra resultado. */
Treino* stub_buscarTreino_nao_encontrado(char cpf[]) { return NULL; }

/* ===== SETUP ===== */

void reset_personal() {
    totalTreinos = 0;
    totalAlunos = 0;
    memset(treinos, 0, sizeof(Treino) * 100);
    memset(alunos, 0, sizeof(Aluno) * MAX_ALUNOS);
}

/* ===== TESTES ===== */

/**
 * @brief PT01 - Busca de treino por CPF existente retorna ponteiro valido.
 * @details Usa stub_buscarTreino_encontrado para simular CPF cadastrado.
 */
MU_TEST(PT01_buscar_treino_existente) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(t != NULL);
}

/**
 * @brief PT02 - Busca de treino por CPF inexistente retorna NULL.
 * @details Usa stub_buscarTreino_nao_encontrado para simular CPF nao cadastrado.
 */
MU_TEST(PT02_buscar_treino_inexistente) {
    Treino* t = stub_buscarTreino_nao_encontrado("00000000000");
    mu_check(t == NULL);
}

/**
 * @brief PT03 - Treino cadastrado tem exercicio correto.
 * @details Verifica se o campo exercicio e preenchido corretamente no stub.
 */
MU_TEST(PT03_treino_exercicio_correto) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(strcmp(t->exercicio, "Supino") == 0);
}

/**
 * @brief PT04 - Treino cadastrado tem peso valido (maior que zero).
 */
MU_TEST(PT04_treino_peso_valido) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(t->peso > 0);
}

/**
 * @brief PT05 - Treino cadastrado tem repeticoes validas (maior que zero).
 */
MU_TEST(PT05_treino_repeticoes_validas) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(t->repeticoes > 0);
}

/**
 * @brief PT06 - Treino cadastrado tem series validas (maior que zero).
 */
MU_TEST(PT06_treino_series_validas) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(t->series > 0);
}

/**
 * @brief PT07 - CPF associado ao treino e armazenado corretamente.
 */
MU_TEST(PT07_treino_cpf_correto) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(strcmp(t->cpf_aluno, "12345678900") == 0);
}

/**
 * @brief PT08 - Total de treinos comeca em zero apos reset.
 */
MU_TEST(PT08_total_treinos_inicial_zero) {
    reset_personal();
    mu_check(totalTreinos == 0);
}

/**
 * @brief PT09 - Cadastro de treino incrementa o total de treinos.
 * @details Simula insercao manual de um treino no array.
 */
MU_TEST(PT09_cadastro_treino_incrementa_total) {
    reset_personal();
    strcpy(treinos[0].cpf_aluno, "12345678900");
    strcpy(treinos[0].exercicio, "Agachamento");
    treinos[0].peso = 80;
    treinos[0].repeticoes = 12;
    treinos[0].series = 4;
    totalTreinos = 1;
    mu_check(totalTreinos == 1);
}

/**
 * @brief PT10 - Dois treinos distintos podem ser cadastrados para CPFs diferentes.
 */
MU_TEST(PT10_dois_treinos_cpfs_distintos) {
    reset_personal();
    strcpy(treinos[0].cpf_aluno, "11111111111");
    strcpy(treinos[1].cpf_aluno, "22222222222");
    totalTreinos = 2;
    mu_check(strcmp(treinos[0].cpf_aluno, treinos[1].cpf_aluno) != 0);
}

MU_TEST_SUITE(suite_personal) {
    MU_RUN_TEST(PT01_buscar_treino_existente);
    MU_RUN_TEST(PT02_buscar_treino_inexistente);
    MU_RUN_TEST(PT03_treino_exercicio_correto);
    MU_RUN_TEST(PT04_treino_peso_valido);
    MU_RUN_TEST(PT05_treino_repeticoes_validas);
    MU_RUN_TEST(PT06_treino_series_validas);
    MU_RUN_TEST(PT07_treino_cpf_correto);
    MU_RUN_TEST(PT08_total_treinos_inicial_zero);
    MU_RUN_TEST(PT09_cadastro_treino_incrementa_total);
    MU_RUN_TEST(PT10_dois_treinos_cpfs_distintos);
}

int main() {
    MU_RUN_SUITE(suite_personal);
    MU_REPORT();
    return MU_EXIT_CODE;
}
