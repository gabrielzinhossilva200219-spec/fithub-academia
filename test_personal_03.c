MU_TEST(PT03_treino_exercicio_correto) {
    Treino* t = stub_buscarTreino_encontrado("12345678900");
    mu_check(strcmp(t->exercicio, "Supino") == 0);
}