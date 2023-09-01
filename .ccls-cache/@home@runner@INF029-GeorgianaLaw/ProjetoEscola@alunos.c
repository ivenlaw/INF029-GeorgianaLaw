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
      v=0;
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
    fgets(aluno[nr_aluno].cpf, 12, stdin);
    fflush(stdin);
    x = strlen(aluno[nr_aluno].cpf) - 1;
    if (aluno[nr_aluno].cpf[x] == '\n')
      aluno[nr_aluno].cpf[x] = '\0';
    int retorno = validadorCPFaluno(aluno, nr_aluno, x);
    if(retorno==CPF_VALIDADO){
      printf("CPF validado");
      v=1;
    }
    else {
      if(retorno==CPF_INCORRETO){
         printf("Cadastro com erro");
      v=0;
      }
    }
  } while (!v);
  return CADASTRO_FINALIZADO;
}

// FUNÇÃO para excluir aluno

int excluirAluno (Ficha aluno[], int nr_aluno) {

  int consulta, i;
  printf("Digite a matrícula a ser excluida: \n");
  scanf("%d", &consulta);

  for (i=0; i<nr_aluno; i++) {
    if (aluno[i].ativo == -1) {
      printf("Cadastro já inativo");
      break;
    }
    else if (aluno[i].matricula == consulta) {
      aluno[i].ativo=-1;
      if (nr_aluno>0) {
        for(int j=i+1; j<nr_aluno; j++) {
          aluno[i]=aluno[j];
        }
      }
    return CADASTRO_EXCLUIDO;
    break;
    }
    else
      return MATRICULA_INVALIDA;
    break;
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

// Validador de CPF
  int validadorCPFaluno (Ficha aluno[], int nr_aluno, int x) {
    int i, j;
    int num[11];
    char *preNum;
    int numPos;
    
    preNum=aluno[nr_aluno].cpf;
    
    strcpy(preNum,aluno[nr_aluno].cpf);
    numPos=atoi(preNum);
    
    int soma1=0, soma2=0, resto1=0, resto2=0;

    if (x==10){
       for(int i=0; i<11; i++){     
         num[i]=preNum[i]-48;
       }
        for(i=10, j=0; i>1; i--){
          soma1=soma1+(num[j]*i);
          j++;
        }
    
        resto1=((soma1*10)%11);
        if(resto1==10)
          resto1=0;
        
        if (resto1==num[9]) {
          for(i=11, j=0; i>1; i--){
            soma2=soma2+(num[j]*i);
            j++;
          }  
          resto2=((soma2*10)%11);
          
          if(resto2==num[10]){
            return CPF_VALIDADO;
          }
          else
            return CPF_INCORRETO;
        }
        else        
          return CPF_INCORRETO;  
    }
    else{
      printf("CPF incompleto, digite os 11 números. \n");
    }
    return 0;
}

