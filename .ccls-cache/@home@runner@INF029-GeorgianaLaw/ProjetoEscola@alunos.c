/* Cadastro de Alunos */

#include <stdio.h>
#include "alunos.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define tamAluno 3


int main() {

  Aluno aluno[tamAluno];
  int i, opcao, v, sexo;
  int sair = 0;
  int nr_aluno = 0;

  // Menu inicial para Aluno

  while (!sair) {

    printf("\n*** Menu Cadastro de Aluno ***\n\n");
    printf("Escolha sua opção: \n");
    printf("0 - Sair \n");
    printf("1 - Cadastrar \n");
    printf("2 - Excluir \n");
    printf("3 - Atualizar \n");
    printf("4 - Consulta \n\n");
    scanf("%d", &opcao);

    // Direcionamento das opções

    switch (opcao) {
    case 0:
      if (opcao == 0) {
        printf("\nSaindo do cadastro dos alunos.\n");
        sair = 1;
        break;
      }
    case 1:
      if (opcao == 1) {
        printf("\nDigite a matrícula: ");
        scanf("%d", &aluno[nr_aluno].matriculaAluno);
        getchar();

        printf("\nDigite o nome: ");
        fflush(stdin);
        fgets(aluno[nr_aluno].nomeAluno, 51, stdin);
        size_t x = strlen(aluno[nr_aluno].nomeAluno) - 1; 
        if (aluno[nr_aluno].nomeAluno[x] == '\n')
          aluno[nr_aluno].nomeAluno[x] = '\0';

        do {
          printf("\nDigite o sexo (F/M): ");
          scanf("%c", &aluno[nr_aluno].sexoAluno);
          v=aluno[nr_aluno].sexoAluno;
          if(v!='F' || v!='M')
            printf("\nSexo inválido. Digite 'M' ou 'F' maiúsculos.");
        } while(v!='F' || v!='M');
        
        do {
          v=0;
          printf("\nDigite o dia do nascimento(dd): ");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.dia);
          if(aluno[nr_aluno].nascimentoAluno.dia>31 || aluno[nr_aluno].nascimentoAluno.dia<=0) {
          printf("\nDia inválido.");
        } 
          else
          v=1;
        } while(!v);
        
        do {
          v=0;
          printf("\nDigite o mês do nascimento (mm): ");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.mes);
          if(aluno[nr_aluno].nascimentoAluno.mes>12 || aluno[nr_aluno].nascimentoAluno.mes<=0) {
            printf("\nMês inválido.");
          } 
            else
            v=1;
         } while(!v);

        do {
          v=0;
          printf("\nDigite o ano do nascimento (aaaa): ");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.ano);
          getchar();
          if(aluno[nr_aluno].nascimentoAluno.ano>2023 || aluno[nr_aluno].nascimentoAluno.ano<=1903) {
              printf("\nAno inválido.");
            } 
              else
              v=1;
         } while(!v);

        do {
          printf("\nDigite o CPF: ");
          fflush(stdin);
          fgets(aluno[nr_aluno].cpfAluno, 12, stdin);
          x = strlen(aluno[nr_aluno].cpfAluno) - 1; 
          if (aluno[nr_aluno].cpfAluno[x] == '\n')
            aluno[nr_aluno].cpfAluno[x] = '\0';
          v = validadorCPF (aluno[nr_aluno].cpfAluno[12]);
          if (!v)
            printf("\nCPF inválido.");
          
          } while (!v);

        printf("\nCadastro finalizado.\n");
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
          if (aluno[i].matriculaAluno == consulta) {
            printf("\n** Cadastro da matrícula %d **\n\n",
                   aluno[i].matriculaAluno);
            printf("Nome: %s\n", aluno[i].nomeAluno);
            printf("Sexo: %c\n", aluno[i].sexoAluno);
            printf("Data de Nascimento: %d/%d/%d\n",
                   aluno[i].nascimentoAluno.dia, aluno[i].nascimentoAluno.mes,
                   aluno[i].nascimentoAluno.ano);
            printf("CPF.: %s\n", aluno[i].cpfAluno);
            break;
          }
          else
            printf("\nMatrícula não localizada.\n");
            break;
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
