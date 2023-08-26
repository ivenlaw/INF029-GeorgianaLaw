/* Cadastro de Alunos */

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// FUNÇÃO com Opcao de cadastramento de aluno

int cadastarAluno() {

  Ficha aluno[TAM_ALUNO];
  int i, j, opcao, v, sexo;
  int nr_aluno = 0;

// Cadastrar matrícula do aluno
  
  printf("\nDigite a matrícula: ");
  scanf("%d", &aluno[nr_aluno].matricula);
  getchar(); 

// Cadastrar o nome do aluno
  
  printf("\nDigite o nome: ");
  fflush(stdin);
  fgets(aluno[nr_aluno].nome, 51, stdin);
  size_t x = strlen(aluno[nr_aluno].nome) - 1;
  if (aluno[nr_aluno].nome[x] == '\n')
    aluno[nr_aluno].nome[x] = '\0';

// Cadastrar o sexo do aluno
  
  do {
    printf("\nDigite o sexo (F/M): ");
    aluno[nr_aluno].sexo = getchar();
    if (aluno[nr_aluno].sexo == 'F' || aluno[nr_aluno].sexo == 'M') {
      v = 1;
    } else {
      printf("\nSexo inválido. Digite 'M' ou 'F' maiúsculos.\n");
      v = 0;
      getchar();
    }
  } while (v == 0);

// Cadastrar o dia de nascimento do aluno
  
  do {
    v = 0;
    printf("\nDigite o dia do nascimento(dd): ");
    scanf("%d", &aluno[nr_aluno].nascimento.dia);
    if (aluno[nr_aluno].nascimento.dia > 31 ||
        aluno[nr_aluno].nascimento.dia <= 0) {
      printf("\nDia inválido.\n");
    } else
      v = 1;
  } while (!v);

// Cadastrar o mês de nascimento do aluno
  
  do {
    v = 0;
    printf("\nDigite o mês do nascimento (mm): ");
    scanf("%d", &aluno[nr_aluno].nascimento.mes);
    if (aluno[nr_aluno].nascimento.mes > 12 ||
        aluno[nr_aluno].nascimento.mes <= 0) {
      printf("\nMês inválido.\n");
    } else
      v = 1;
  } while (!v);

// Cadastrar o ano de nascimento do aluno
  
  do {
    v = 0;
    printf("\nDigite o ano do nascimento (aaaa): ");
    scanf("%d", &aluno[nr_aluno].nascimento.ano);
    getchar();
    if (aluno[nr_aluno].nascimento.ano > 2023 ||
        aluno[nr_aluno].nascimento.ano <= 1903) {
      printf("\nAno inválido.\n");
    } else
      v = 1;
  } while (!v);

// Cadastrar o CPF do aluno
  
  do {
    printf("\nDigite o CPF: ");
    fflush(stdin);
    fgets(aluno[nr_aluno].cpf, 12, stdin);
    x = strlen(aluno[nr_aluno].cpf) - 1;
    if (aluno[nr_aluno].cpf[x] == '\n')
      aluno[nr_aluno].cpf[x] = '\0';
  } while (!v);

  
  return CADASTRO_FINALIZADO;
}

// FUNÇÃO para listar um Aluno

int listarAluno (Ficha aluno[], int nr_aluno){
  
  int consulta, j;
  printf("\nDigite a matrícula a ser consultada\n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_aluno; i++) {
    if (aluno[i].matricula == consulta) {
      printf("\n** Cadastro da matrícula %d **\n\n",
             aluno[i].matricula);
      printf("Nome: %s\n", aluno[i].nome);
      printf("Sexo: %c\n", aluno[i].sexo);
      printf("Data de Nascimento: %d/%d/%d\n",
             aluno[i].nascimento.dia, aluno[i].nascimento.mes,
             aluno[i].nascimento.ano);
      printf("CPF.: ");
      for (j=0;j<3;j++)    
          printf("%c", aluno[i].cpf[j]);
      printf(".");
      for(j=3;j<6;j++)     
          printf("%c", aluno[i].cpf[j]);
      printf(".");
      for(j=6;j<9;j++)   
          printf("%c", aluno[i].cpf[j]);
      printf("-");
      for(j=9;j<11;j++)   
          printf("%c", aluno[i].cpf[j]);
      break;
    }
    else{
      return MATRICULA_INVALIDA;
      break;
    }  
  }
  return 0;
}
