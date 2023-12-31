/* Cadastro de Alunos */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamAluno 3

typedef struct {
  int dia;
  int mes;
  int ano; 
} Data; 

typedef struct {

  int matriculaAluno;
  char nomeAluno[51];
  char sexoAluno;
  Data nascimentoAluno;
  char cpfAluno[12];
} Aluno;


int main () {

  Aluno aluno[tamAluno];
  int i, opcao;
  int sair = 1;
  int nr_aluno = 0;

  // Menu inicial para Aluno
  
  while (!sair){

    printf("*** Menu Cadastro de Aluno ***\n");
    printf("Escolha sua opção: \n");
    printf("0 - Sair \n");
    printf("1 - Cadastrar \n");
    printf("2 - Excluir \n");
    printf("3 - Atualizar \n");
    scanf("%d", &opcao);

  // Direcionamento das opções

    switch (opcao) {
      case 0: 
        if(opcao==0) {
          printf("Saindo do cadastro dos alunos.\n");
          sair=0;
          break;
        }
      case 1:
        if(opcao==1) {
          printf("Digite a matrícula:\n");
          scanf("%d", &aluno[nr_aluno].matriculaAluno);
    
          printf("Digite o nome:\n");
          scanf("%51[^\n]", aluno[nr_aluno].nomeAluno);   
          
          printf("Digite o sexo (F/M):\n");
          scanf("%s", &aluno[nr_aluno].sexoAluno);  

          printf("Digite o dia do nascimento:\n");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.dia);  

          printf("Digite o mês do nascimento:\n");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.mes);

          printf("Digite o ano do nascimento:\n");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.ano);

          printf("Digite o CPF:\n");
          scanf("%12[^\n]", aluno[nr_aluno].cpfAluno); 
          
          break;
        }
    
        
    }
  }

  

  
return 0;
}


