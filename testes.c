/**
 * @file testes.c
 * @brief Testes unitarios do sistema FitHub Academia utilizando MinUnit.
 * @details Utiliza stubs para simular dependencias e isolar as funcoes
 *          testadas de efeitos colaterais externos.
 */

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "recepcionista.h"
#include "personal.h"

/* ===== VARIAVEIS EXTERNAS ===== */
extern Aluno alunos[];
extern int totalAlunos;
extern Treino treinos[];
extern int totalTreinos;

/* ==========================================================
 * STUBS
 * Funcoes simuladas para isolar comportamentos nos testes.
 * Substituem dependencias externas sem afetar o sistema real.
 * ========================================================== */

/** @brief Stub: simula validacao de nome sempre valida. */
int stub_validarNome_valido(char nome[]) { return 1; }

/** @brief Stub: simula validacao de nome sempre invalida. */
int stub_validarNome_invalido(char nome[]) { return 0; }

/** @brief Stub: simula validacao de CPF sempre valida. */
int stub_validarCPF_valido(char cpf[]) { return 1; }

/** @brief Stub: simula validacao de CPF sempre invalida. */
int stub_validarCPF_invalido(char cpf[]) { return 0; }

/** @brief Stub: simula que o CPF ja existe no sistema. */
int stub_cpfExiste_sim(char cpf[]) { return 1; }

/** @brief Stub: simula que o CPF nao existe no sistema. */
int stub_cpfExiste_nao(char cpf[]) { return 0; }

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

void reset() {

    /** @brief CT01 - Nome valido deve ser aceito. */
MU_TEST(CT01_nome_valido) {
    mu_check(validarNome("Julia Pereira") == 1);
}

/** @brief CT02 - Nome vazio deve ser rejeitado. */
MU_TEST(CT02_nome_vazio) {
    mu_check(validarNome("") == 0);
}

/** @brief CT03 - CPF com 11 digitos deve ser aceito. */
MU_TEST(CT03_cpf_valido) {
    mu_check(validarCPF("12345678900") == 1);
}

/** @brief CT04 - CPF vazio deve ser rejeitado. */
MU_TEST(CT04_cpf_vazio) {
    mu_check(validarCPF("") == 0);
}

/** @brief CT05 - CPF com menos de 11 digitos deve ser rejeitado. */
MU_TEST(CT05_cpf_incompleto) {
    mu_check(validarCPF("123") == 0);
}

    totalAlunos = 0;
    totalTreinos = 0;
    memset(alunos, 0, sizeof(Aluno) * MAX_ALUNOS);
    memset(treinos, 0, sizeof(Treino) * 100);
}
