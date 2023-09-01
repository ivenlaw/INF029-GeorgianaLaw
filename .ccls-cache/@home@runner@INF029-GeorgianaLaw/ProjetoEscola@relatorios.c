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

int listarDiscipinas (Materia disciplina[], int nr_disciplina){
  int consulta, j;
  printf("\n\nLista das disciplinas cadastrados \n\n");  
  for (int i=0; i < nr_disciplina; i++) {
    printf("\n\nCódigo: %d \n",
           disciplina[i].codigo);
    printf("Nome: %s\n", disciplina[i].nome);
    printf("Semestre: %c\n", disciplina[i].semestre);
    printf("Professor: %s\n", disciplina[i].professor);
  }
  return 0;
}

// FUNÇAO para relatório com a lista dos alunos por sexo

int listarSexo (Ficha aluno[], int nr_aluno, Ficha professor[], int nr_professor){
  
  int j;
  int v=0;
  int sairSexo=0;

  while (!sairSexo) {
    int opcao;
    printf("Deseja o relatorio de: \n");
    printf("0 - Sair \n");
    printf("1 - Alunos\n");
    printf("2 - Professores  \n\n");
    scanf("%d", &opcao);

    switch (opcao) {
      // Sair do menu listar sexo
      case 0:{
        if (opcao == 0) {
          printf("\nSaindo da listagem por sexo.\n\n");
          sairSexo = 1;
        }
      break;
      }
      case 1: 
        if (opcao == 1) {
          printf("\nDigite o sexo dos alunos a ser consutado: \n");  
          int consulta=getchar();
          if (aluno[nr_aluno].sexo == 'F' || aluno[nr_aluno].sexo == 'f') {
            printf("\n\nLista das alunas do sexo feminino cadastrados \n\n");
            for (int i=0; i < nr_aluno; i++) {
               if(aluno[nr_aluno].sexo == 'F' || aluno[nr_aluno].sexo == 'f')
               printf("Sexo: %c\n", aluno[i].sexo);
            }
          }
          else if (aluno[nr_aluno].sexo == 'M' || aluno[nr_aluno].sexo == 'm') {
              printf("\n\nLista dos alunos do sexo masculino cadastrados \n\n");
            for (int i=0; i < nr_aluno; i++) {
               if(aluno[nr_aluno].sexo == 'M' || aluno[nr_aluno].sexo == 'm')
               printf("Sexo: %c\n", aluno[i].sexo);
            }
          }
        break;
        }
      case 2: 
        if (opcao == 2) {
                    printf("\nDigite o sexo dos professores a ser consutado: \n");  
          int consulta=getchar();
          if (professor[nr_professor].sexo == 'F' || professor[nr_professor].sexo == 'f') {
            printf("\n\nLista das professoras do sexo feminino cadastrados \n\n");
            for (int i=0; i < nr_professor; i++) {
               if(professor[nr_professor].sexo == 'F' || professor[nr_professor].sexo == 'f')
               printf("Sexo: %c\n", professor[i].sexo);
            }
          }
          else if (professor[nr_professor].sexo == 'M' || professor[nr_professor].sexo == 'm') {
              printf("\n\nLista dos professores do sexo masculino cadastrados \n\n");
            for (int i=0; i < nr_professor; i++) {
               if(professor[nr_professor].sexo == 'M' || professor[nr_professor].sexo == 'm')
               printf("Sexo: %c\n", professor[i].sexo);
            }
          }
        break;
        }
      default: {
        printf("Opção inválida.\n");
        break;
      }
  }
}
}
