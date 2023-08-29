/* Projeto Escola */

//#include <stdio.h>
#include "menus.h"
//#include <stdlib.h>
//#include <string.h>
#ifndef alunos_h
#define alunos_h



// Prototipos

int validadorCPF (Ficha aluno[], int nr_aluno);
int cadastarAluno(Ficha aluno[], int nr_aluno);
int listarAluno (Ficha aluno[], int nr_aluno);
int excluirAluno (Ficha aluno[], int nr_aluno);
int atualizarAluno (Ficha aluno[], int nr_aluno);


#endif
