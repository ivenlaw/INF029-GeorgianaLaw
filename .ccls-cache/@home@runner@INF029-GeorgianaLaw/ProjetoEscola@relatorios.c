/* Relatórios */

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// FUNÇAO para relatório com a lista dos alunos

int listarAlunos (Ficha aluno[], int nr_aluno){
  int consulta, j;
  int i=0;
  printf("\n\nLista dos alunos cadastrados \n\n");  
  while (i<nr_aluno) {
    printf("\n\n Matrícula %d **\n",
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
//    break;
  }
  return 0;
}


