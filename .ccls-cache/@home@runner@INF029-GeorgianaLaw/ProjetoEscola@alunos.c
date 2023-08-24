/* Cadastro de Alunos */

#include <stdio.h>
#include "alunos.h"
#include "cadastros.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



int main() {

  Ficha aluno[tamAluno];
  int i, j, opcao, v, sexo;
  int sair = 0;
  int nr_aluno = 0;

  // Menu inicial para Aluno

  while (!sair) {

    printf("\n\n*** Menu Cadastro de Aluno ***\n\n");
    opcao = menuCadastro ();

    // Direcionamento das opções

    switch (opcao) {
    case 0:
      if (opcao == 0) {
        printf("\nSaindo do cadastro dos alunos.\n\n");
        sair = 1;
        break;
      }
    case 1:
      if (opcao == 1) {

      cadastarAluno();
        
        nr_aluno++;
        break;
      }

    case 2:
      if (opcao == 2) {
        printf("menu 2.\n");

        break;
      }

    case 3:
      if (opcao == 3) {
        printf("menu 3.\n");

        break;
      }

    case 4:
      if (opcao == 4) {
        int consulta;
        printf("\nDigite a matrícula a ser consultada\n");
        scanf("%d", &consulta);
        for (i = 0; i <= tamAluno; i++) {
          if (aluno[i].matricula == consulta) {
            printf("\n** Cadastro da matrícula %d **\n\n",
                   aluno[i].matricula);
            printf("Nome: %s\n", aluno[i].nome);
            printf("Sexo: %c\n", aluno[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n",
                   aluno[i].nascimento.dia, aluno[i].nascimento.mes,
                   aluno[i].nascimento.ano);
            printf("CPF.: ");
            for(j=0;j<3;j++)    
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
            printf("\nMatrícula não localizada.\n");
            break;}
        }
        break;
      }

    default: {
      printf("Opção inválida.\n");
      break;
    }
    }
  }

  return 0;
}
