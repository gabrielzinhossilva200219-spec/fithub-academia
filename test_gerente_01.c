MU_TEST(GT01_total_funcionarios_inicial_zero) {
    reset_gerente();
    mu_check(totalFuncionarios == 0);
}

