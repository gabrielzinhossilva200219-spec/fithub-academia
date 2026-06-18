MU_TEST(GT06_nome_funcionario_vazio_invalido) {
    mu_check(stub_validarNomeFuncionario_invalido("") == 0);
}