/* Projeto Escola */

#include "menus.h"
#ifndef disciplinas_h
#define disciplinas_h



// Prototipos

int cadastarDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);
int listarDisciplina (Materia disciplina[], int nr_disciplina);
int atualizarDisciplina (Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]);
int excluirDisciplina (Materia disciplina[], int nr_disciplina);



#endif