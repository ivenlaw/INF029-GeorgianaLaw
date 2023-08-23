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
  int sair = 0;
  int nr_aluno = 0;
  

  // Menu inicial para Aluno
  
  while (!sair){

    printf("*** Menu Cadastro de Aluno ***\n");
    printf("Escolha sua opção: \n");
    printf("0 - Sair \n");
    printf("1 - Cadastrar \n");
    printf("2 - Excluir \n");
    printf("3 - Atualizar \n");
    printf("4 - Consulta \n");
    scanf("%d", &opcao);

  // Direcionamento das opções

    switch (opcao) {
      case 0: 
        if(opcao==0) {
          printf("Saindo do cadastro dos alunos.\n");
          sair=1;
          break;
        }
      case 1:
        if(opcao==1) {
          printf("Digite a matrícula:\n");
          scanf("%d", &aluno[nr_aluno].matriculaAluno);
    
          printf("Digite o nome:\n");
          fgets(aluno[nr_aluno].nomeAluno, 51, stdin);
          
          printf("Digite o sexo (F/M):\n");
          scanf("%s", &aluno[nr_aluno].sexoAluno);  

          printf("Digite o dia do nascimento:\n");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.dia);  

          printf("Digite o mês do nascimento:\n");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.mes);

          printf("Digite o ano do nascimento:\n");
          scanf("%d", &aluno[nr_aluno].nascimentoAluno.ano);

          printf("Digite o CPF:\n");
          fgets(aluno[nr_aluno].cpfAluno, 12, stdin); 
          /* usa um for para ler cada caracter do cpf
            //Percorrendo o vetor de char e mostrando
           //cada elemento individualmente
            for (i=0; i<6; i++)
  {
    printf("Valor do elemento %d da string = %c\n",i, texto[i]);
  }  */
          
          break;
        }
    
        case 2: 
        if(opcao==2) {
          printf("menu 2.\n");
          
          break;
        }
      
        case 3: 
        if(opcao==3) {
          printf("menu 3.\n");
          
          break;
        }

        case 4: 
        if(opcao==4) {
          int consulta;
          printf("Digite a matrícula a ser consultada\n");
          scanf("%d", &consulta);
          for(i=0; i<=tamAluno; i++) {
            if(aluno[nr_aluno].matriculaAluno==consulta) {
              printf("A matrícula %d possui o seguinte cadastro:\n", aluno[i].matriculaAluno);
              printf("Nome: %s\n", aluno[i].nomeAluno);
              printf("Sexo: %d\n", aluno[i].sexoAluno);
              printf("Data de Nascimento: %d/%d/%d\n", aluno[i].nascimentoAluno.dia, aluno[i].nascimentoAluno.mes, aluno[i].nascimentoAluno.ano);
              printf("CPF.: %s\n", aluno[i].cpfAluno);
            }
          }
          break;
        }
      
        default: 
         {
          printf(" nenhuma das opcoes.\n");
          
          break;
         }
    }
  }

  

  
return 0;
}


