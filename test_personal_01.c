MU_TEST(PT01_buscar_treino_existente) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(t != NULL);
}