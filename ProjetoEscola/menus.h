// Modularização referente aos cadastros no Projeto Escola

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "alunos.h"
#ifndef menus_h
#define menus_h

#define TAM_ALUNO 3
#define TAM_PROFESSOR 3
#define TAM_DISCIPLINA 10
#define ALUNO_MATRICULADO 50
#define MATRICULA_INVALIDA -1
#define CADASTRO_FINALIZADO -2
#define LISTA_VAZIA -3
#define CADASTRO_EXCLUIDO -4
#define CADASTRO_ATUALIZADO -5
#define CPF_VALIDADO -6
#define CPF_INCORRETO -7
#define CODIGO_INVALIDO -8


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

typedef struct {

  int codigo;
  char nome[20];
  int semestre;
  char professor[51];
  int alunosMatriculados[50];
  int ativo;
} Materia;


// Prototipos

int menuGeral();
int menuCadastro();
int menuRelatorios();
int menuDisciplina();


#endif