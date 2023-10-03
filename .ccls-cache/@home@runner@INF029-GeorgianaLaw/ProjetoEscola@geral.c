// Modularização referente aos cadastros no Projeto Escola

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "geral.h"
#include "alunos.h"
#include "relatorios.h"
#include "professores.h"
#include "disciplinas.h"


// Menu geral da escola

int menuGeral(){  

  int opcaoGeral;
  
  printf("\n\n*** Menu escola ***\n\n");
  printf("Escolha sua opção: \n");
  printf("0 - Sair \n");
  printf("1 - Cadastro dos alunos \n");
  printf("2 - Cadastro dos professores \n");
  printf("3 - Cadastro das disciplinas \n");
  printf("4 - Relatórios \n\n");
  scanf("%d", &opcaoGeral);
  
  return opcaoGeral;
}

// Menu geral de cadastro de pessoas

int menuCadastro(){  

  int opcao;
  
  printf("Escolha sua opção: \n");
  printf("0 - Sair \n");
  printf("1 - Cadastrar \n");
  printf("2 - Excluir \n");
  printf("3 - Atualizar \n");
  printf("4 - Consulta \n\n");
  scanf("%d", &opcao);
  
  return opcao;
}

// Menu Relatórios

int menuRelatorios(){  

  int opcaoRelatorios;
  
  printf("\n\n*** Menu relatórios ***\n\n");
  printf("Escolha sua opção: \n");
  printf("0 - Sair \n");
  printf("1 - Listar alunos \n");
  printf("2 - Listar professores \n");
  printf("3 - Listar disciplinas \n");
  printf("4 - Administrativo \n\n");
  scanf("%d", &opcaoRelatorios);
  
  return opcaoRelatorios;
}

// Menu Disciplina

int menuDisciplina(){  

  int opcaoDisciplina;
  
  printf("Escolha sua opção: \n");
  printf("0 - Sair \n");
  printf("1 - Cadastrar \n");
  printf("2 - Excluir \n");
  printf("3 - Atualizar \n");
  printf("4 - Matricular aluno \n");
  printf("5 - Consulta \n\n");
  scanf("%d", &opcaoDisciplina);
  
  return opcaoDisciplina;
}





