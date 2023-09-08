/* Projeto Escola */

//#include <stdio.h>
#include "geral.h"
//#include <stdlib.h>
//#include <string.h>
#ifndef alunos_h
#define alunos_h



// Prototipos

int validadorCPFaluno (Ficha aluno[], int nr_aluno, int x);
int cadastarAluno(Ficha aluno[], int nr_aluno);
int listarAluno (Ficha aluno[], int nr_aluno);
int excluirAluno (Ficha aluno[], int nr_aluno);
int atualizarAluno (Ficha aluno[], int nr_aluno);


#endif
