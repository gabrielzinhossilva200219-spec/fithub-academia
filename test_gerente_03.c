MU_TEST(GT07_nome_funcionario_valido) {
    mu_check(stub_validarNomeFuncionario_valido("Pedro Costa") == 1);
}