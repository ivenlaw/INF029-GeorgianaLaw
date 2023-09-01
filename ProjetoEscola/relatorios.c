/* Relatórios */

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"
#include "professores.h"
#include "disciplinas.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// FUNÇAO para relatório com a lista dos alunos

int listarAlunos (Ficha aluno[], int nr_aluno){
  int consulta, j;
  printf("\n\nLista dos alunos cadastrados \n\n");  
  for (int i=0; i < nr_aluno; i++) {
    printf("\n\nMatrícula: %d \n",
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
  }
  return 0;
}

// FUNÇAO para relatório com a lista dos professor

int listarProfessores (Ficha professor[], int nr_professor){
  int consulta, j;
  printf("\n\nLista dos professor cadastrados \n\n");  
  for (int i=0; i < nr_professor; i++) {
    printf("\n\nMatrícula: %d \n",
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
  }
  return 0;
}


// FUNÇAO para relatório com a lista das discipinas

int listarDiscipinas (Materia disciplina[], int nr_disciplina, int aluno_disciplina){
  int consulta, j;
  printf("\n\nLista das disciplinas cadastrados \n\n");  
  for (int i=0; i < nr_disciplina; i++) {
    printf("\n\nCódigo: %d \n",
           disciplina[i].codigo);
    printf("Nome: %s\n", disciplina[i].nome);
    printf("Semestre: %c\n", disciplina[i].semestre);
    printf("Professor: %s\n", disciplina[i].professor);
    printf("Alunos matriculados:");
    for(int j=0; j<aluno_disciplina; j++){
      printf("%d", disciplina[i].alunosMatriculados[j]);
        }
  }
  return 0;
}

// FUNÇAO para relatório com a lista dos alunos por sexo

int listarSexo (Ficha aluno[], int nr_aluno, Ficha professor[], int nr_professor){
  
  int j;
  int v=0;
  int sairSexo=0;

  while (!sairSexo) {
    int opcaoSexo;
    printf("\nDeseja o relatorio de: \n");
    printf("0 - Sair \n");
    printf("1 - Alunos\n");
    printf("2 - Professores  \n\n");
    scanf("%d", &opcaoSexo);

    switch (opcaoSexo) {
      // Sair do menu listar sexo
      case 0:{
        if (opcaoSexo == 0) {
          printf("\nSaindo da listagem por sexo.\n\n");
          sairSexo = 1;
        }
      break;
      }
      case 1: {
        if (opcaoSexo == 1) {
          int opcaoSexoAluno;
          int sairSexoAluno=0;
          while (!sairSexoAluno){
            printf("\nDigite o sexo dos alunos a ser consultado: \n");
            printf("0 - Sair \n");
            printf("1 - Feminino \n");
            printf("2 - Masculino \n\n");
            scanf("%d", &opcaoSexoAluno);
            if (opcaoSexoAluno == 0) {
              printf("\nSaindo.\n\n");
              sairSexoAluno = 1;
            }
            else if (opcaoSexoAluno == 1) {
              printf("\n\nLista das alunas do sexo feminino cadastrados \n\n");
              for (int i=0; i < nr_aluno; i++) {
                 if(aluno[i].sexo == 'F' || aluno[i].sexo == 'f')
                 printf("Aluna: %s\n", aluno[i].nome);
              }
              sairSexoAluno=1;
              break;
            }
            else if (opcaoSexoAluno == 2) {
                printf("\n\nLista dos alunos do sexo masculino cadastrados \n\n");
              for (int i=0; i < nr_aluno; i++) {
                 if(aluno[i].sexo == 'M' || aluno[i].sexo == 'm')
                 printf("Aluno: %s\n", aluno[i].nome);
              }
              sairSexoAluno=1;
              break;
            }
          break;
          }
        }
        break;
      }
      case 2:{ 
        if (opcaoSexo == 2) {
          int opcaoSexoProfessor;
          int sairSexoProfessor=0;
          while (!sairSexoProfessor){
            printf("\nDigite o sexo dos professores a ser consutado: \n");  
            printf("0 - Sair \n");
            printf("1 - Feminino \n");
            printf("2 - Masculino \n\n");
            scanf("%d", &opcaoSexoProfessor);
            if (opcaoSexoProfessor == 0) {
              printf("\nSaindo.\n\n");
              sairSexoProfessor = 1;
            }
            else if (opcaoSexoProfessor == 1) {
              printf("\n\nLista das professoras do sexo feminino cadastrados \n\n");
              for (int i=0; i < nr_professor; i++) {
                 if(professor[i].sexo == 'F' || professor[i].sexo == 'f')
                 printf("Professora: %s\n", professor[i].nome);
              }
              sairSexoProfessor = 1;
              break;
            }
            else if (opcaoSexoProfessor == 2) {
                printf("\n\nLista dos professores do sexo masculino cadastrados \n\n");
              for (int i=0; i < nr_professor; i++) {
                 if(professor[i].sexo == 'M' || professor[i].sexo == 'm')
                 printf("Professor: %s\n", professor[i].nome);
              }
              sairSexoProfessor=1;
              break;
            }
          break;
        }
        break;
      }
      }
    default: {
      printf("Opção inválida.\n");
      break;
    }
  }
}
  return 0;
}
