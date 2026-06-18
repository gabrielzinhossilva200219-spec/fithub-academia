MU_TEST(CT14_cadastro_completo) {
    reset_recepcionista();
    strcpy(alunos[0].nome, "Julia Pereira");
    strcpy(alunos[0].cpf, "12345678900");
    strcpy(alunos[0].dataNascimento, "10/10/2000");
    strcpy(alunos[0].email, "juliapereirateste@gmail.com");
    strcpy(alunos[0].telefone, "11999999999");
    strcpy(alunos[0].laudo, "Apto");
    alunos[0].faltas = 0;
    totalAlunos = 1;