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
#define LISTA_VAZIA -3
#define CADASTRO_EXCLUIDO -4
#define CADASTRO_ATUALIZADO -5

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
int cadastarAluno(Ficha aluno[], int nr_aluno);
int listarAluno (Ficha aluno[], int nr_aluno);
int excluirAluno (Ficha aluno[], int nr_aluno);
int atualizarAluno (Ficha aluno[], int nr_aluno);


#endif
