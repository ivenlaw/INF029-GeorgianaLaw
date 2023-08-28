/* Cadastro de Alunos */

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// FUNÇÃO com Opcao de cadastramento de aluno

int cadastarAluno(Ficha aluno[], int nr_aluno) {

  int v;
//  Ficha aluno[TAM_ALUNO];
//  int i, j, opcao, v, sexo;
//  int nr_aluno = 0;

// Cadastrar matrícula do aluno
  
  printf("\nDigite a matrícula: ");
  scanf("%d", &aluno[nr_aluno].matricula);
  getchar(); 

// Ativando cadastro 

  aluno[nr_aluno].ativo=0;
  
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
    if (aluno[nr_aluno].sexo == 'F' || aluno[nr_aluno].sexo == 'M' || aluno[nr_aluno].sexo == 'f' || aluno[nr_aluno].sexo == 'm') {
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
    v=0;
    printf("\nDigite o CPF: ");
    fflush(stdin);
    fgets(aluno[nr_aluno].cpf, 12, stdin);
    x = strlen(aluno[nr_aluno].cpf) - 1;
    if (aluno[nr_aluno].cpf[x] == '\n')
      aluno[nr_aluno].cpf[x] = '\0';
    printf("Cadastro concluído\n");
/*    
    int retorno = validadorCPF(aluno, nr_aluno);
    if(retorno == CPF_VALIDADO){
      printf("Cadastro concluído");
      v=1;
    }
    else {
      if(retorno == CPF_INCORRETO)
      printf("O CPF informado está incorreto.\n");
    }

*/    
  } while (!v);
/*
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11;
  int soma1=0, soma2=0, resto1=0, resto2=0;

  num1 = atoi(aluno[0].cpf);
  num2 = atoi(aluno[1].cpf);
  num3 = atoi(aluno[2].cpf);
  num4 = atoi(aluno[3].cpf);
  num5 = atoi(aluno[4].cpf);
  num6 = atoi(aluno[5].cpf);
  num7 = atoi(aluno[6].cpf);
  num8 = atoi(aluno[7].cpf);
  num9 = atoi(aluno[8].cpf);
  num10 = atoi(aluno[9].cpf);
  num11 = atoi(aluno[10].cpf);

  sscanf(aluno[0].cpf, "%d", &num1);
  sscanf(aluno[1].cpf, "%d", &num2);
  sscanf(aluno[2].cpf, "%d", &num3);
  sscanf(aluno[3].cpf, "%d", &num4);
  sscanf(aluno[4].cpf, "%d", &num5);
  sscanf(aluno[5].cpf, "%d", &num6);
  sscanf(aluno[6].cpf, "%d", &num7);
  sscanf(aluno[7].cpf, "%d", &num8);
  sscanf(aluno[8].cpf, "%d", &num9);
  sscanf(aluno[9].cpf, "%d", &num10);
  sscanf(aluno[10].cpf, "%d", &num11);
  
  
  soma1=((num1*10)+(num2*9)+(num3*8)+(num4*7)+(num5*6)+(num6*5)+(num7*4)+(num8*3)+(num9*2));
  printf("soma1 %d\n", soma1);
  resto1=((soma1*10)%11);
  printf("resto1 %d\n", resto1);
  if (resto1==num10) {
    soma2=((num1*11)+(num2*10)+(num3*9)+(num4*8)+(num5*7)+(num6*6)+(num7*5)+(num8*4)+(num9*3)+(num10*2));
    printf("soma2 %d\n", soma2);
    resto2=((soma2*10)%11);
    printf("resto2 %d\n", resto2);
    if(resto2==num11)
      printf("CPF_VALIDADO");
    else
      printf ("CPF_INCORRETO");
  }
  else
  printf ("CPF_INCORRETO");
*/
  
return 0;
}

// FUNÇÃO para excluir aluno

int excluirAluno (Ficha aluno[], int nr_aluno) {

  int consulta, i;
  printf("Digite a matrícula a ser excluida: ");
  scanf("%d", &consulta);

  for (i=0; i<nr_aluno; i++) {
    if (aluno[i].ativo == -1) {
      printf("Cadastro já inativo");
    }
    else if (aluno[i].matricula == consulta) {
      aluno[i].ativo=-1;
      for(int j=i+1; j<nr_aluno; j++) {
        aluno[i]=aluno[j];
        return CADASTRO_EXCLUIDO;
        break;
      }
    }
  }
return 0;
}

// FUNÇÃO para atualizar um Aluno

int atualizarAluno (Ficha aluno[], int nr_aluno){
  int consulta, j;
  printf("\n\nDigite a matrícula a ser atualizada\n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_aluno; i++) {
    if (aluno[i].matricula == consulta) {
      char troca;
      printf("\n** Cadastro da matrícula %d **\n\n",
       aluno[i].matricula);
      // TROCA do nome
      printf("Deseja alterar o nome %s? ", aluno[i].nome);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        printf("\nDigite o novo nome: ");
        fflush(stdin);
        fgets(aluno[i].nome, 51, stdin);
        size_t x = strlen(aluno[i].nome) - 1;
        if (aluno[i].nome[x] == '\n')
          aluno[i].nome[x] = '\0';
      }
      // TROCA do sexo
      printf("\nDeseja alterar o sexo '%c'? ", aluno[i].sexo);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o novo sexo (F/M): ");
          aluno[i].sexo = getchar();
          if (aluno[i].sexo == 'F' || aluno[i].sexo == 'M' || aluno[i].sexo == 'f' || aluno[i].sexo == 'm') {
            v = 1;
          } else {
            printf("\nSexo inválido. Digite 'M' ou 'F' maiúsculos.\n");
//            getchar();
          }
        } while (v == 0);
      }
      //TROCA de Data de Nascimento
      printf("\nDeseja alterar a data de nascimento: %d/%d/%d? ", aluno[i].nascimento.dia, aluno[i].nascimento.mes,
             aluno[i].nascimento.ano);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o dia do nascimento(dd): ");
          scanf("%d", &aluno[i].nascimento.dia);
          if (aluno[i].nascimento.dia > 31 ||
              aluno[i].nascimento.dia <= 0) {
            printf("\nDia inválido.\n");
          } else
            v = 1;
        } while (!v);
        v = 0;
        do {
          printf("\nDigite o mês do nascimento (mm): ");
          scanf("%d", &aluno[i].nascimento.mes);
          if (aluno[i].nascimento.mes > 12 ||
              aluno[i].nascimento.mes <= 0) {
            printf("\nMês inválido.\n");
          } else
            v = 1;
        } while (!v);
        v = 0;
        do {
          printf("\nDigite o ano do nascimento (aaaa): ");
          scanf("%d", &aluno[i].nascimento.ano);
          getchar();
          if (aluno[i].nascimento.ano > 2023 ||
              aluno[i].nascimento.ano <= 1903) {
            printf("\nAno inválido.\n");
          } else
            v = 1;
        } while (!v);
      }
      //TROCA do CPF
      printf("\nDeseja alterar o CPF: ");
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
      printf("? ");
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o CPF: ");
          fflush(stdin);
          fgets(aluno[nr_aluno].cpf, 12, stdin);
          size_t x = strlen(aluno[nr_aluno].cpf) - 1;
          if (aluno[nr_aluno].cpf[x] == '\n')
            aluno[nr_aluno].cpf[x] = '\0';
          return CADASTRO_ATUALIZADO;
          break;
        } while (!v);
      }
    }
    else{
      return MATRICULA_INVALIDA;
      break;
    }
  break;
  }
return 0;
}



// FUNÇÃO para listar um Aluno

int listarAluno (Ficha aluno[], int nr_aluno){
  int consulta, j;
  printf("\n\nDigite a matrícula a ser consultada\n");
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
      printf("Matrícula %d não localizada", consulta);
      break;
    }
}
  return 0;
}
/*
//  FUNÇÃO Validador de CPF
int validadorCPF (Ficha aluno, int nr_aluno) {
  int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11;
  int soma1=0, soma2=0, resto1=0, resto2=0;

  num1 = atoi(aluno[0].cpf);
  num2 = atoi(aluno[1].cpf);
  num3 = atoi(aluno[2].cpf);
  num4 = atoi(aluno[3].cpf);
  num5 = atoi(aluno[4].cpf);
  num6 = atoi(aluno[5].cpf);
  num7 = atoi(aluno[6].cpf);
  num8 = atoi(aluno[7].cpf);
  num9 = atoi(aluno[8].cpf);
  num10 = atoi(aluno[9].cpf);
  num11 = atoi(aluno[10].cpf);

  sscanf(aluno[0].cpf, "%d", &num1);
  sscanf(aluno[1].cpf, "%d", &num2);
  sscanf(aluno[2].cpf, "%d", &num3);
  sscanf(aluno[3].cpf, "%d", &num4);
  sscanf(aluno[4].cpf, "%d", &num5);
  sscanf(aluno[5].cpf, "%d", &num6);
  sscanf(aluno[6].cpf, "%d", &num7);
  sscanf(aluno[7].cpf, "%d", &num8);
  sscanf(aluno[8].cpf, "%d", &num9);
  sscanf(aluno[9].cpf, "%d", &num10);
  sscanf(aluno[10].cpf, "%d", &num11);
  
  
  soma1=((num1*10)+(num2*9)+(num3*8)+(num4*7)+(num5*6)+(num6*5)+(num7*4)+(num8*3)+(num9*2));
  resto1=((soma1*10)%11);
  if (resto1==num9) {
    soma2=((num1*11)+(num2*10)+(num3*9)+(num4*8)+(num5*7)+(num6*6)+(num7*5)+(num8*4)+(num9*3)+(num10*2));
    resto2=((soma2*10)%11);
    if(resto2==num10)
      return CPF_VALIDADO;
    else
      return CPF_INCORRETO;
  }
  else
  return CPF_INCORRETO;
} 
*/