/* Projeto Escola */

//#include <stdio.h>
//#include "menus.h"
//#include <stdlib.h>
//#include <string.h>
#ifndef alunos_h
#define alunos_h

#define TAM_ALUNO 3
#define MATRICULA_INVALIDA -1
#define CADASTRO_FINALIZADO -2

// struct para datas

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

// struct para ficha de cadastro

typedef struct {

  int matricula;
  char nome[51];
  char sexo;
  Data nascimento;
  char cpf[12];
  int ativo;
} Ficha;


// Prototipos

int validadorCPF();
int cadastarAluno();
int listarAluno (Ficha aluno[], int nr_aluno);




#endif
