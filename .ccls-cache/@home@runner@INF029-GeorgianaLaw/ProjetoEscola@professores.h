/* Projeto Escola */

#include "geral.h"
#ifndef professores_h
#define professores_h



// Prototipos


int cadastarProfessor(Ficha professor[], int nr_professor);
int listarProfessor (Ficha professor[], int nr_professor);
int excluirProfessor (Ficha professor[], int nr_professor);
int atualizarProfessor (Ficha professor[], int nr_professor);
int validadorCPFprofessor (Ficha professor[], int nr_professor, int x);
int aberturaArquivoProfessor (Ficha professor[]);
void fechaProfessor(Ficha professor[], int nr_professor);
void carregarProfessor(char linhaProfessor[], Ficha professor[], int nr_professor);


#endif