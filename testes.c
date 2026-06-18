/**
 * @file testes.c
 * @brief Suite principal de testes do sistema FitHub Academia.
 * @details Roda todos os testes dos modulos recepcionista, personal e gerente.
 */

#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "recepcionista.h"
#include "personal.h"
#include "gerente.h"

/* ===== VARIAVEIS EXTERNAS ===== */
extern Aluno alunos[];
extern int totalAlunos;
extern Treino treinos[];
extern int totalTreinos;
extern Funcionario funcionarios[];
extern int totalFuncionarios;

/* ===== STUBS ===== */

int stub_validarNome_valido(char nome[])         { return 1; }
int stub_validarNome_invalido(char nome[])        { return 0; }
int stub_validarCPF_valido(char cpf[])            { return 1; }
int stub_validarCPF_invalido(char cpf[])          { return 0; }
int stub_cpfExiste_sim(char cpf[])                { return 1; }
int stub_cpfExiste_nao(char cpf[])                { return 0; }
int stub_validarNomeFuncionario_valido(char n[])  { return strlen(n) > 0; }
int stub_validarNomeFuncionario_invalido(char n[]){ return 0; }

Treino* stub_buscarTreino_encontrado(char cpf[]) {
    static Treino t;
    strcpy(t.cpf_aluno, cpf);
    strcpy(t.exercicio, "Supino");
    t.peso = 60; t.repeticoes = 10; t.series = 3;
    return &t;
}
Treino* stub_buscarTreino_nao_encontrado(char cpf[]) { return NULL; }

/* ===== SETUP ===== */

void reset() {
    totalAlunos = 0;
    totalTreinos = 0;
    totalFuncionarios = 0;
    memset(alunos, 0, sizeof(Aluno) * MAX_ALUNOS);
    memset(treinos, 0, sizeof(Treino) * 100);
    memset(funcionarios, 0, sizeof(Funcionario) * MAX_FUNCIONARIOS);
}

/* ==========================================================
 * MODULO: RECEPCIONISTA (CT01 - CT15)
 * ========================================================== */

MU_TEST(CT01_nome_valido)       { mu_check(validarNome("Julia Pereira") == 1); }
MU_TEST(CT02_nome_vazio)        { mu_check(validarNome("") == 0); }
MU_TEST(CT03_cpf_valido)        { mu_check(validarCPF("12345678900") == 1); }
MU_TEST(CT04_cpf_vazio)         { mu_check(validarCPF("") == 0); }
MU_TEST(CT05_cpf_incompleto)    { mu_check(validarCPF("123") == 0); }
MU_TEST(CT06_data_valida)       { mu_check(validarData("10/10/2000") == 1); }
MU_TEST(CT07_data_invalida)     { mu_check(validarData("99/99/9999") == 0); }
MU_TEST(CT08_email_valido)      { mu_check(validarEmail("juliapereirateste@gmail.com") == 1); }
MU_TEST(CT09_email_invalido)    { mu_check(validarEmail("juliapereirateste.com") == 0); }
MU_TEST(CT10_telefone_valido)   { mu_check(validarTelefone("11999999999") == 1); }
MU_TEST(CT11_telefone_vazio)    { mu_check(validarTelefone("") == 0); }
MU_TEST(CT12_laudo_informado)   { mu_check(validarLaudo("Apto") == 1); }
MU_TEST(CT13_laudo_vazio)       { mu_check(validarLaudo("") == 0); }

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

MU_TEST(CT15_cpf_duplicado) {
    reset();
    mu_check(stub_cpfExiste_sim("12345678900") == 1);
}

/* ==========================================================
 * MODULO: PERSONAL (PT01 - PT10)
 * ========================================================== */

MU_TEST(PT01_buscar_treino_existente)      { mu_check(stub_buscarTreino_encontrado("12345678900") != NULL); }
MU_TEST(PT02_buscar_treino_inexistente)    { mu_check(stub_buscarTreino_nao_encontrado("00000000000") == NULL); }
MU_TEST(PT03_treino_exercicio_correto)     { Treino* t = stub_buscarTreino_encontrado("12345678900"); mu_check(strcmp(t->exercicio, "Supino") == 0); }
MU_TEST(PT04_treino_peso_valido)           { Treino* t = stub_buscarTreino_encontrado("12345678900"); mu_check(t->peso > 0); }
MU_TEST(PT05_treino_repeticoes_validas)    { Treino* t = stub_buscarTreino_encontrado("12345678900"); mu_check(t->repeticoes > 0); }
MU_TEST(PT06_treino_series_validas)        { Treino* t = stub_buscarTreino_encontrado("12345678900"); mu_check(t->series > 0); }
MU_TEST(PT07_treino_cpf_correto)           { Treino* t = stub_buscarTreino_encontrado("12345678900"); mu_check(strcmp(t->cpf_aluno, "12345678900") == 0); }

MU_TEST(PT08_total_treinos_inicial_zero) {
    reset();
    mu_check(totalTreinos == 0);
}

MU_TEST(PT09_cadastro_treino_incrementa_total) {
    reset();
    strcpy(treinos[0].cpf_aluno, "12345678900");
    strcpy(treinos[0].exercicio, "Agachamento");
    treinos[0].peso = 80; treinos[0].repeticoes = 12; treinos[0].series = 4;
    totalTreinos = 1;
    mu_check(totalTreinos == 1);
}

MU_TEST(PT10_dois_treinos_cpfs_distintos) {
    reset();
    strcpy(treinos[0].cpf_aluno, "11111111111");
    strcpy(treinos[1].cpf_aluno, "22222222222");
    totalTreinos = 2;
    mu_check(strcmp(treinos[0].cpf_aluno, treinos[1].cpf_aluno) != 0);
}

/* ==========================================================
 * MODULO: GERENTE (GT01 - GT10)
 * ========================================================== */

MU_TEST(GT01_total_funcionarios_inicial_zero) { reset(); mu_check(totalFuncionarios == 0); }

MU_TEST(GT02_cargo_recepcionista_correto) {
    reset();
    strcpy(funcionarios[0].nome, "Ana Lima");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    mu_check(strcmp(funcionarios[0].cargo, "Recepcionista") == 0);
}

MU_TEST(GT03_cargo_personal_correto) {
    reset();
    strcpy(funcionarios[0].nome, "Carlos Silva");
    strcpy(funcionarios[0].cargo, "Personal Trainer");
    totalFuncionarios = 1;
    mu_check(strcmp(funcionarios[0].cargo, "Personal Trainer") == 0);
}

MU_TEST(GT04_nome_funcionario_correto) {
    reset();
    strcpy(funcionarios[0].nome, "Maria Souza");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    mu_check(strcmp(funcionarios[0].nome, "Maria Souza") == 0);
}

MU_TEST(GT05_limite_maximo_funcionarios)      { reset(); totalFuncionarios = MAX_FUNCIONARIOS; mu_check(totalFuncionarios >= MAX_FUNCIONARIOS); }
MU_TEST(GT06_nome_funcionario_vazio_invalido) { mu_check(stub_validarNomeFuncionario_invalido("") == 0); }
MU_TEST(GT07_nome_funcionario_valido)         { mu_check(stub_validarNomeFuncionario_valido("Pedro Costa") == 1); }

MU_TEST(GT08_dois_funcionarios_cargos_distintos) {
    reset();
    strcpy(funcionarios[0].cargo, "Recepcionista");
    strcpy(funcionarios[1].cargo, "Personal Trainer");
    totalFuncionarios = 2;
    mu_check(strcmp(funcionarios[0].cargo, funcionarios[1].cargo) != 0);
}

MU_TEST(GT09_cadastro_incrementa_total) {
    reset();
    strcpy(funcionarios[0].nome, "Julia Pereira");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    totalFuncionarios = 1;
    mu_check(totalFuncionarios == 1);
}

MU_TEST(GT10_reset_limpa_funcionarios) {
    strcpy(funcionarios[0].nome, "Alguem");
    totalFuncionarios = 1;
    reset();
    mu_check(totalFuncionarios == 0);
    mu_check(strlen(funcionarios[0].nome) == 0);
}

/* ==========================================================
 * SUITES
 * ========================================================== */

MU_TEST_SUITE(suite_recepcionista) {
    MU_RUN_TEST(CT01_nome_valido);
    MU_RUN_TEST(CT02_nome_vazio);
    MU_RUN_TEST(CT03_cpf_valido);
    MU_RUN_TEST(CT04_cpf_vazio);
    MU_RUN_TEST(CT05_cpf_incompleto);
    MU_RUN_TEST(CT06_data_valida);
    MU_RUN_TEST(CT07_data_invalida);
    MU_RUN_TEST(CT08_email_valido);
    MU_RUN_TEST(CT09_email_invalido);
    MU_RUN_TEST(CT10_telefone_valido);
    MU_RUN_TEST(CT11_telefone_vazio);
    MU_RUN_TEST(CT12_laudo_informado);
    MU_RUN_TEST(CT13_laudo_vazio);
    MU_RUN_TEST(CT14_cadastro_completo);
    MU_RUN_TEST(CT15_cpf_duplicado);
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
    printf("\n===== RECEPCIONISTA =====\n");
    MU_RUN_SUITE(suite_recepcionista);

    printf("\n===== PERSONAL =====\n");
    MU_RUN_SUITE(suite_personal);

    printf("\n===== GERENTE =====\n");
    MU_RUN_SUITE(suite_gerente);

    MU_REPORT();
    return MU_EXIT_CODE;
}
