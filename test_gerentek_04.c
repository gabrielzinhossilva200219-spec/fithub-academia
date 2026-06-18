MU_TEST(GT08_dois_funcionarios_cargos_distintos) {
    reset_gerente();
    strcpy(funcionarios[0].nome, "Ana Lima");
    strcpy(funcionarios[0].cargo, "Recepcionista");
    strcpy(funcionarios[1].nome, "Carlos Silva");
    strcpy(funcionarios[1].cargo, "Personal Trainer");
    totalFuncionarios = 2;
    mu_check(strcmp(funcionarios[0].cargo, funcionarios[1].cargo) != 0);
}