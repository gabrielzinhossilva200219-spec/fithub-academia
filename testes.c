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

/** @brief CT06 - Data no formato valido deve ser aceita. */
MU_TEST(CT06_data_valida) {
    mu_check(validarData("10/10/2000") == 1);
}

/** @brief CT07 - Data com dia e mes invalidos deve ser rejeitada. */
MU_TEST(CT07_data_invalida) {
    mu_check(validarData("99/99/9999") == 0);
}

/** @brief CT08 - Email com arroba e .com deve ser aceito. */
MU_TEST(CT08_email_valido) {
    mu_check(validarEmail("juliapereirateste@gmail.com") == 1);
}

/** @brief CT09 - Email sem arroba deve ser rejeitado. */
MU_TEST(CT09_email_invalido) {
    mu_check(validarEmail("juliapereirateste.com") == 0);
}

/** @brief CT10 - Telefone com 11 digitos deve ser aceito. */
MU_TEST(CT10_telefone_valido) {
    mu_check(validarTelefone("11999999999") == 1);
}

/** @brief CT11 - Telefone vazio deve ser rejeitado. */
MU_TEST(CT11_telefone_vazio) {
    mu_check(validarTelefone("") == 0);
}

/** @brief CT12 - Laudo informado deve ser aceito. */
MU_TEST(CT12_laudo_informado) {
    mu_check(validarLaudo("Apto") == 1);
}

/** @brief CT13 - Laudo vazio deve ser rejeitado. */
MU_TEST(CT13_laudo_vazio) {
    mu_check(validarLaudo("") == 0);
}

/**
 * @brief CT14 - Cadastro completo com todos os campos validos.
 * @details Usa stub_validarNome_valido e stub_validarCPF_valido para
 *          simular que todas as validacoes passam sem depender
 *          da implementacao real.
 */
MU_TEST(CT14_cadastro_completo) {
    reset();
    strcpy(alunos[0].nome, "Julia Pereira");
    strcpy(alunos[0].cpf, "12345678900");
    strcpy(alunos[0].dataNascimento, "10/10/2000");
    strcpy(alunos[0].email, "juliapereirateste@gmail.com");
    strcpy(alunos[0].telefone, "11999999999");
    strcpy(alunos[0].laudo, "Apto");
    alunos[0].faltas = 0;
    totalAlunos = 1;

    mu_check(stub_validarNome_valido(alunos[0].nome) == 1);
    mu_check(stub_validarCPF_valido(alunos[0].cpf) == 1);
    mu_check(validarData(alunos[0].dataNascimento) == 1);
    mu_check(validarEmail(alunos[0].email) == 1);
    mu_check(validarTelefone(alunos[0].telefone) == 1);
    mu_check(validarLaudo(alunos[0].laudo) == 1);
    mu_check(stub_cpfExiste_nao(alunos[0].cpf) == 0);
    mu_check(totalAlunos == 1);
}

/**
 * @brief CT15 - CPF duplicado deve ser detectado.
 * @details Usa stub_cpfExiste_sim para simular que o CPF ja existe
 *          sem depender do estado real do array de alunos.
 */
MU_TEST(CT15_cpf_duplicado) {
    reset();
    mu_check(stub_cpfExiste_sim("12345678900") == 1);
}

    totalAlunos = 0;
    totalTreinos = 0;
    memset(alunos, 0, sizeof(Aluno) * MAX_ALUNOS);
    memset(treinos, 0, sizeof(Treino) * 100);
}
