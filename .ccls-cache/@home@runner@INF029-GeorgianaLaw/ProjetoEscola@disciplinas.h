/* Projeto Escola */

#include "geral.h"
#include "professores.h"
#ifndef disciplinas_h
#define disciplinas_h



// Prototipos

int cadastarDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);
int listarDisciplina (Materia disciplina[], int nr_disciplina, int aluno_disciplina);
int atualizarDisciplina (Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);
int excluirDisciplina (Materia disciplina[], int nr_disciplina);
int matricularAluno (Materia disciplina[], int nr_disciplina, int nr_aluno, Ficha aluno[], int aluno_disciplina);
int aberturaArquivoDisciplina (Materia disciplina[], int nr_professor, Ficha professor[]);
void fechaDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[], Ficha aluno[], int aluno_disciplina, int nr_aluno);
void carregarDisciplina(char linhaDisciplina[], Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);


#endif