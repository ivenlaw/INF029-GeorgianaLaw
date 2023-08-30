/* Cadastro de Professores */

#include <stdio.h>
#include "menus.h"
//#include "alunos.h"
#include "relatorios.h"
#include "professores.h"
#include "disciplinas.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// FUNÇÃO com Opcao de cadastramento de professores

int cadastarProfessor(Ficha professor[], int nr_professor) {

  int v;
//  Ficha professor[TAM_PROFESSOR];
//  int i, j, opcao, v, sexo;
//  int nr_professor = 0;

// Cadastrar matrícula do professor
  
  printf("\nDigite a matrícula: ");
  scanf("%d", &professor[nr_professor].matricula);
  getchar(); 

// Ativando cadastro 

  professor[nr_professor].ativo=0;
  
// Cadastrar o nome do professor
  
  printf("\nDigite o nome: ");
  fflush(stdin);
  fgets(professor[nr_professor].nome, 51, stdin);
  size_t x = strlen(professor[nr_professor].nome) - 1;
  if (professor[nr_professor].nome[x] == '\n')
    professor[nr_professor].nome[x] = '\0';

// Cadastrar o sexo do professor
  
  do {
    printf("\nDigite o sexo (F/M): ");
    professor[nr_professor].sexo = getchar();
    if (professor[nr_professor].sexo == 'F' || professor[nr_professor].sexo == 'M' || professor[nr_professor].sexo == 'f' || professor[nr_professor].sexo == 'm') {
      v = 1;
    } else {
      printf("\nSexo inválido. Digite 'M' ou 'F' maiúsculos.\n");
      v = 0;
      getchar();
    }
  } while (v == 0);

// Cadastrar o dia de nascimento do professor
  
  do {
    v = 0;
    printf("\nDigite o dia do nascimento(dd): ");
    scanf("%d", &professor[nr_professor].nascimento.dia);
    if (professor[nr_professor].nascimento.dia > 31 ||
        professor[nr_professor].nascimento.dia <= 0) {
      printf("\nDia inválido.\n");
    } else
      v = 1;
  } while (!v);

// Cadastrar o mês de nascimento do professor
  
  do {
    v = 0;
    printf("\nDigite o mês do nascimento (mm): ");
    scanf("%d", &professor[nr_professor].nascimento.mes);
    if (professor[nr_professor].nascimento.mes > 12 ||
        professor[nr_professor].nascimento.mes <= 0) {
      printf("\nMês inválido.\n");
    } else
      v = 1;
  } while (!v);

// Cadastrar o ano de nascimento do professor
  
  do {
    v = 0;
    printf("\nDigite o ano do nascimento (aaaa): ");
    scanf("%d", &professor[nr_professor].nascimento.ano);
    getchar();
    if (professor[nr_professor].nascimento.ano > 2023 ||
        professor[nr_professor].nascimento.ano <= 1903) {
      printf("\nAno inválido.\n");
    } else
      v = 1;
  } while (!v);

// Cadastrar o CPF do professor
  
  do {
    printf("\nDigite o CPF: ");
    fflush(stdin);
    fgets(professor[nr_professor].cpf, 12, stdin);
    x = strlen(professor[nr_professor].cpf) - 1;
    if (professor[nr_professor].cpf[x] == '\n')
      professor[nr_professor].cpf[x] = '\0';
  } while (!v);
  return CADASTRO_FINALIZADO;
}

// FUNÇÃO para excluir professor

int excluirProfessor (Ficha professor[], int nr_professor) {

  int consulta, i;
  printf("Digite a matrícula a ser excluida: ");
  scanf("%d", &consulta);

  for (i=0; i<nr_professor; i++) {
    if (professor[i].ativo == -1) {
      printf("Cadastro já inativo");
    }
    else if (professor[i].matricula == consulta) {
      professor[i].ativo=-1;
      for(int j=i+1; j<nr_professor; j++) {
        professor[i]=professor[j];
        return CADASTRO_EXCLUIDO;
        break;
      }
    }
  }
return 0;
}

// FUNÇÃO para atualizar um Professor

int atualizarProfessor (Ficha professor[], int nr_professor){
  int consulta, j;
  printf("\n\nDigite a matrícula a ser atualizada\n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_professor; i++) {
    if (professor[i].matricula == consulta) {
      char troca;
      printf("\n** Cadastro da matrícula %d **\n\n",
       professor[i].matricula);
      // TROCA do nome
      printf("Deseja alterar o nome %s? ", professor[i].nome);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        printf("\nDigite o novo nome: ");
        fflush(stdin);
        fgets(professor[i].nome, 51, stdin);
        size_t x = strlen(professor[i].nome) - 1;
        if (professor[i].nome[x] == '\n')
          professor[i].nome[x] = '\0';
      }
      // TROCA do sexo
      printf("\nDeseja alterar o sexo '%c'? ", professor[i].sexo);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o novo sexo (F/M): ");
          professor[i].sexo = getchar();
          if (professor[i].sexo == 'F' || professor[i].sexo == 'M' || professor[i].sexo == 'f' || professor[i].sexo == 'm') {
            v = 1;
          } else {
            printf("\nSexo inválido. Digite 'M' ou 'F' maiúsculos.\n");
//            getchar();
          }
        } while (v == 0);
      }
      //TROCA de Data de Nascimento
      printf("\nDeseja alterar a data de nascimento: %d/%d/%d? ", professor[i].nascimento.dia, professor[i].nascimento.mes,
             professor[i].nascimento.ano);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o dia do nascimento(dd): ");
          scanf("%d", &professor[i].nascimento.dia);
          if (professor[i].nascimento.dia > 31 ||
              professor[i].nascimento.dia <= 0) {
            printf("\nDia inválido.\n");
          } else
            v = 1;
        } while (!v);
        v = 0;
        do {
          printf("\nDigite o mês do nascimento (mm): ");
          scanf("%d", &professor[i].nascimento.mes);
          if (professor[i].nascimento.mes > 12 ||
              professor[i].nascimento.mes <= 0) {
            printf("\nMês inválido.\n");
          } else
            v = 1;
        } while (!v);
        v = 0;
        do {
          printf("\nDigite o ano do nascimento (aaaa): ");
          scanf("%d", &professor[i].nascimento.ano);
          getchar();
          if (professor[i].nascimento.ano > 2023 ||
              professor[i].nascimento.ano <= 1903) {
            printf("\nAno inválido.\n");
          } else
            v = 1;
        } while (!v);
      }
      //TROCA do CPF
      printf("\nDeseja alterar o CPF: ");
      for (j=0;j<3;j++)    
          printf("%c", professor[i].cpf[j]);
      printf(".");
      for(j=3;j<6;j++)     
          printf("%c", professor[i].cpf[j]);
      printf(".");
      for(j=6;j<9;j++)   
          printf("%c", professor[i].cpf[j]);
      printf("-");
      for(j=9;j<11;j++)   
          printf("%c", professor[i].cpf[j]);
      printf("? ");
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o CPF: ");
          fflush(stdin);
          fgets(professor[nr_professor].cpf, 12, stdin);
          size_t x = strlen(professor[nr_professor].cpf) - 1;
          if (professor[nr_professor].cpf[x] == '\n')
            professor[nr_professor].cpf[x] = '\0';
          v=1;
        } while (!v);
      }
      return CADASTRO_ATUALIZADO;
      break;
    }
    else{
      return MATRICULA_INVALIDA;
      break;
    }
  break;
  }
return 0;
}



// FUNÇÃO para listar um Professor

int listarProfessor (Ficha professor[], int nr_professor){
  int consulta, j;
  printf("\n\nDigite a matrícula a ser consultada\n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_professor; i++) {
    if (professor[i].matricula == consulta) {
      printf("\n** Cadastro da matrícula %d **\n\n",
             professor[i].matricula);
      printf("Nome: %s\n", professor[i].nome);
      printf("Sexo: %c\n", professor[i].sexo);
      printf("Data de Nascimento: %d/%d/%d\n",
             professor[i].nascimento.dia, professor[i].nascimento.mes,
             professor[i].nascimento.ano);
      printf("CPF.: ");
      for (j=0;j<3;j++)    
          printf("%c", professor[i].cpf[j]);
      printf(".");
      for(j=3;j<6;j++)     
          printf("%c", professor[i].cpf[j]);
      printf(".");
      for(j=6;j<9;j++)   
          printf("%c", professor[i].cpf[j]);
      printf("-");
      for(j=9;j<11;j++)   
          printf("%c", professor[i].cpf[j]);
      break;
    }
    else{
      printf("Matrícula %d não localizada", consulta);
      break;
    }
}
  return 0;
}

