// Modularização referente aos cadastros no Projeto Escola

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"


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

// Menu geral da escola

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


