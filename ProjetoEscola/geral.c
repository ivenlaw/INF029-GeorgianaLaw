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

int aberturaArquivoAluno (Ficha aluno[]){

  FILE* abrirArquivoAluno;
  char linhaAluno[TAM_ALUNO_FICHA];
  int nr_aluno=0;

  abrirArquivoAluno = fopen("fichasAluno.txt", "r");
  if(abrirArquivoAluno==0){
    printf("Arquivo de dados não disponível. Criando novo arquivo!");
    abrirArquivoAluno = fopen("fichasAluno.txt", "w");
  }
  else {
    do {
      fgets(linhaAluno, TAM_ALUNO_FICHA, abrirArquivoAluno);
      carregarAluno(linhaAluno, aluno, nr_aluno);
      nr_aluno++;
    } while (!feof(abrirArquivoAluno));
  }
  return nr_aluno;
}

void fechaAluno(Ficha aluno[], int nr_aluno){

  FILE* abrirArquivoAluno;
  abrirArquivoAluno = fopen("fichasAluno.txt", "w+");
//  char linhaAluno[80];
  int i;
  
  for (i = 0; i < nr_aluno; i++) {
    fprintf(abrirArquivoAluno, "%d", aluno[i].matricula);
    fputs(";", abrirArquivoAluno);
    fputs(aluno[i].nome, abrirArquivoAluno);
    fputs(";", abrirArquivoAluno);
    fputc(aluno[i].sexo, abrirArquivoAluno);
    fputs(";", abrirArquivoAluno);
    fprintf(abrirArquivoAluno, "%d;%d;%d", aluno[i].nascimento.dia,
            aluno[i].nascimento.mes,
            aluno[i].nascimento.ano);
    fputs(";", abrirArquivoAluno);
    fputs(aluno[i].cpf, abrirArquivoAluno);
    fputs(";", abrirArquivoAluno);
    fprintf(abrirArquivoAluno, "%d", aluno[i].ativo);
    if (i < nr_aluno - 1)
      fputs("\n", abrirArquivoAluno);
  }
  
  fclose(abrirArquivoAluno);
  
}

void carregarAluno(char linhaAluno[], Ficha aluno[], int nr_aluno) {

  char *tokA;

//  printf("%s", linhaAluno);
  
  int cont = 1;
  tokA = strtok(linhaAluno, ";");

  while (tokA != 0) {
    switch (cont) {
    case 1: {
      aluno[nr_aluno].matricula = atoi(tokA);
      break;
    }
    case 2: {
      strcpy(aluno[nr_aluno].nome, tokA);
      break;
    }
    case 3: {
      aluno[nr_aluno].sexo=*tokA;
      break;
    }
    case 4: {
      aluno[nr_aluno].nascimento.dia = atoi(tokA);
      break;
    }
    case 5: {
      aluno[nr_aluno].nascimento.mes = atoi(tokA);
      break;
    }
    case 6: {
      aluno[nr_aluno].nascimento.ano = atoi(tokA);
      break;
    }
    case 7: {
      strcpy(aluno[nr_aluno].cpf, tokA);
      break;
    }
    case 8: {
      aluno[nr_aluno].ativo = atoi(tokA);
      break;
    }
    }
//    printf(" %s\n", tokA);
    tokA = strtok(0, ";");
    cont++;
  }
}

int aberturaArquivoProfessor (Ficha professor[]){

  FILE* abrirArquivoProfessor;
  char linhaProfessor[TAM_PROF_FICHA];
  int nr_professor=0;

  abrirArquivoProfessor = fopen("fichasProfessor.txt", "r");
  if(abrirArquivoProfessor==0){
    printf("Arquivo de dados não disponível. Criando novo arquivo!");
    abrirArquivoProfessor = fopen("fichasProfessor.txt", "w");
  }
  else {
    do {
      fgets(linhaProfessor, TAM_PROF_FICHA, abrirArquivoProfessor);
      carregarProfessor (linhaProfessor, professor, nr_professor);
      nr_professor++;
    } while (!feof(abrirArquivoProfessor));
  }
  return nr_professor;
}

void fechaProfessor(Ficha professor[], int nr_professor){

  FILE* abrirArquivoProfessor;
  abrirArquivoProfessor = fopen("fichasProfessor.txt", "w+");
//  char linhaProfessor[80];
  int i;
  
  for (i = 0; i < nr_professor; i++) {
    fprintf(abrirArquivoProfessor, "%d", professor[i].matricula);
    fputs(";", abrirArquivoProfessor);
    fputs(professor[i].nome, abrirArquivoProfessor);
    fputs(";", abrirArquivoProfessor);
    fputc(professor[i].sexo, abrirArquivoProfessor);
    fputs(";", abrirArquivoProfessor);
    fprintf(abrirArquivoProfessor, "%d;%d;%d", professor[i].nascimento.dia,
            professor[i].nascimento.mes,
            professor[i].nascimento.ano);
    fputs(";", abrirArquivoProfessor);
    fputs(professor[i].cpf, abrirArquivoProfessor);
    fputs(";", abrirArquivoProfessor);
    fprintf(abrirArquivoProfessor, "%d", professor[i].ativo);
    if (i < nr_professor - 1)
      fputs("\n", abrirArquivoProfessor);
  }
  
  fclose(abrirArquivoProfessor);
  
}

void carregarProfessor(char linhaProfessor[], Ficha professor[], int nr_professor) {

  char *tokP;

 // printf("%s", linhaProfessor);
  
  int cont = 1;
  tokP = strtok(linhaProfessor, ";");

  while (tokP != 0) {
    switch (cont) {
    case 1: {
      professor[nr_professor].matricula = atoi(tokP);
      break;
    }
    case 2: {
      strcpy(professor[nr_professor].nome, tokP);
      break;
    }
    case 3: {
      professor[nr_professor].sexo=*tokP;
      break;
    }
    case 4: {
      professor[nr_professor].nascimento.dia = atoi(tokP);
      break;
    }
    case 5: {
      professor[nr_professor].nascimento.mes = atoi(tokP);
      break;
    }
    case 6: {
      professor[nr_professor].nascimento.ano = atoi(tokP);
      break;
    }
    case 7: {
      strcpy(professor[nr_professor].cpf, tokP);
      break;
    }
    case 8: {
      professor[nr_professor].ativo = atoi(tokP);
      break;
    }
    }
//    printf(" %s\n", tokP);
    tokP = strtok(0, ";");
    cont++;
  }
}


int aberturaArquivoDisciplina (Materia disciplina[], int nr_professor, Ficha professor[]){

  FILE* abrirArquivoDisciplina;
  char linhaDisciplina[TAM_DISC_FICHA];
  int nr_disciplina=0;

  abrirArquivoDisciplina = fopen("fichasDisciplina.txt", "r");
  if(abrirArquivoDisciplina==0){
    printf("Arquivo de dados não disponível. Criando novo arquivo!");
    abrirArquivoDisciplina = fopen("fichasDisciplina.txt", "w");
  }
  else {
    do {
      fgets(linhaDisciplina, TAM_DISC_FICHA, abrirArquivoDisciplina);
      carregarDisciplina (linhaDisciplina, disciplina, nr_disciplina, nr_professor, professor);
      nr_disciplina++;
    } while (!feof(abrirArquivoDisciplina));
  }
  return nr_disciplina;
}

void fechaDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[], Ficha aluno[], int aluno_disciplina, int nr_aluno){

  FILE* abrirArquivoDisciplina;
  abrirArquivoDisciplina = fopen("fichasDisciplina.txt", "w+");
  //char linhaDisciplina[80];
  int i;
  
  for (i = 0; i < nr_disciplina; i++) {
    fprintf(abrirArquivoDisciplina, "%d", disciplina[i].codigo);
    fputs(";", abrirArquivoDisciplina);
    fputs(disciplina[i].nome, abrirArquivoDisciplina);
    fputs(";", abrirArquivoDisciplina);
    fputc(disciplina[i].semestre, abrirArquivoDisciplina);
    fputs(";", abrirArquivoDisciplina);
    fprintf(abrirArquivoDisciplina, "%s", disciplina[i].professor);
    fputs(";", abrirArquivoDisciplina);
    fprintf(abrirArquivoDisciplina, "%s", disciplina[i].alunosMatriculados);
    fputs(";", abrirArquivoDisciplina);
    fprintf(abrirArquivoDisciplina, "%d", disciplina[i].ativo);
    if (i < nr_disciplina - 1)
      fputs("\n", abrirArquivoDisciplina);
  }
  
  fclose(abrirArquivoDisciplina);
  
}

void carregarDisciplina(char linhaDisciplina[], Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]) {

  char *tokD;

 // printf("%s", linhaProfessor);
  
  int cont = 1;
  tokD = strtok(linhaDisciplina, ";");

  while (tokD != 0) {
    switch (cont) {
    case 1: {
      disciplina[nr_disciplina].codigo = atoi(tokD);
      break;
    }
    case 2: {
      strcpy(disciplina[nr_disciplina].nome, tokD);
      break;
    }
    case 3: {
      disciplina[nr_disciplina].semestre=*tokD;
      break;
    }
    case 4: {
      strcpy(disciplina[nr_disciplina].professor, tokD);
      break;
    }
    case 5: {
      strcpy(disciplina[nr_disciplina].alunosMatriculados, tokD);
      break;
    }
    case 6: {
      disciplina[nr_disciplina].ativo = atoi(tokD);
      break;
    }
    }
//    printf(" %s\n", tokP);
    tokD = strtok(0, ";");
    cont++;
  }
}
