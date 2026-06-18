MU_TEST(PT02_buscar_treino_inexistente) {
    Treino* t = stub_buscarTreino_nao_encontrado("00000000000");
    mu_check(t == NULL);
}