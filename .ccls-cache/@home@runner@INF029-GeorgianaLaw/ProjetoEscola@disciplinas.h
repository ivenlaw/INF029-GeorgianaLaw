/* Projeto Escola */

#include "menus.h"
#include "professores.h"
#ifndef disciplinas_h
#define disciplinas_h



// Prototipos

int cadastarDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);
int listarDisciplina (Materia disciplina[], int nr_disciplina, int aluno_disciplina);
int atualizarDisciplina (Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);
int excluirDisciplina (Materia disciplina[], int nr_disciplina);
int matricularAluno (Materia disciplina[], int nr_disciplina, int nr_aluno, Ficha aluno[], int aluno_disciplina);



#endif