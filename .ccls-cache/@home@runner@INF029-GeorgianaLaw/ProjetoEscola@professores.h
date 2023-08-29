/* Projeto Escola */

#include "menus.h"
#ifndef professores_h
#define professores_h

#define TAM_PROFESSOR 3

// Prototipos


int cadastarProfessores(Ficha professores[], int nr_professores);
int listarProfessores (Ficha professores[], int nr_professores);
int excluirProfessores (Ficha professores[], int nr_professores);
int atualizarProfessores (Ficha professores[], int nr_professores);



#endif