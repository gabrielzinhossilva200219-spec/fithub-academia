#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "recepcionista.h"
#include "personal.h"

extern Aluno alunos[];
extern int totalAlunos;
extern Treino treinos[];
extern int totalTreinos;

void reset() {
    totalAlunos = 0;
    totalTreinos = 0;
    memset(alunos, 0, sizeof(Aluno) * MAX_ALUNOS);
    memset(treinos, 0, sizeof(Treino) * 100);
}