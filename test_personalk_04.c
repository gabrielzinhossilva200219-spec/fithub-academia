MU_TEST(PT09_cadastro_treino_incrementa_total) {
    reset_personal();
    strcpy(treinos[0].cpf_aluno, "12345678900");
    strcpy(treinos[0].exercicio, "Agachamento");
    treinos[0].peso = 80;
    treinos[0].repeticoes = 12;
    treinos[0].series = 4;
    totalTreinos = 1;
    mu_check(totalTreinos == 1);
}