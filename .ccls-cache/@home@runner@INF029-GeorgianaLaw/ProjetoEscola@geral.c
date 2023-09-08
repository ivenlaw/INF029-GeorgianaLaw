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

int aberturaArquivo (Ficha aluno[]){

  FILE* abrirArquivo;
  char linha[TAM_LINHA_FICHA];
  int nr_aluno=0;

  abrirArquivo = fopen("fichasAluno.txt", "r");
  if(abrirArquivo==0){
    printf("Arquivo de dados não disponível. Criando novo arquivo!");
    abrirArquivo = fopen("fichasAluno.txt", "w");
  }
  else {
    do {
      fgets(linha, TAM_LINHA_FICHA, abrirArquivo);
      carregarAluno(linha, aluno);
      nr_aluno++;
    } while (!feof(abrirArquivo));
  }
  return nr_aluno;
}

void fechaAluno(Ficha aluno[], int nr_aluno){

  FILE* abrirArquivo;
  abrirArquivo = fopen("fichasAluno.txt", "w+");
  char linha[80];
  int i;
  
  for (i = 0; i < nr_aluno; i++) {
    fprintf(abrirArquivo, "%d", aluno[i].matricula);
    fputs(";", abrirArquivo);
    fputs(aluno[i].nome, abrirArquivo);
    fputs(";", abrirArquivo);
    fputc(aluno[i].sexo, abrirArquivo);
    fputs(";", abrirArquivo);
    fprintf(abrirArquivo, "%d;%d;%d", aluno[i].nascimento.dia,
            aluno[i].nascimento.mes,
            aluno[i].nascimento.ano);
    fputs(";", abrirArquivo);
    fputs(aluno[i].cpf, abrirArquivo);
    fputs(";", abrirArquivo);
    fprintf(abrirArquivo, "%d", aluno[i].ativo);
    if (i < nr_aluno - 1)
      fputs("\n", abrirArquivo);
  }
  
  fclose(abrirArquivo);
  
}

void carregarAluno(char linha[], Ficha aluno[]) {

  char *tok;

  int cont = 1;
  tok = strtok(linha, ";");

  while (tok != 0) {
    switch (cont) {
    case 1: {
      aluno->matricula = atoi(tok);
      break;
    }
    case 2: {
      strcpy(aluno->nome, tok);
      break;
    }
    case 3: {
      aluno->sexo=*tok;
      break;
    }
    case 4: {
      aluno->nascimento.dia = atoi(tok);
      break;
    }
    case 5: {
      aluno->nascimento.mes = atoi(tok);
      break;
    }
    case 6: {
      aluno->nascimento.ano = atoi(tok);
      break;
    }
    case 7: {
      strcpy(aluno->cpf, tok);
      break;
    }
    case 8: {
      strcpy(aluno->cpf, tok);
      break;
    }
    }
    printf("%s\n", tok);
    tok = strtok(0, ";");
    cont++;
  }
}
