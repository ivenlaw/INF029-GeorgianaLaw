// Modularização referente aos cadastros no Projeto Escola

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"


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

// Menu geral da escola

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

// struct para datas



/*
// Validador de CPF
  int validadorCPF (int v[12]) {
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11,
soma1, soma2, resto1, resto2;

    num1 = atoi(v[1]);
    num2 = atoi(v[2]);
    num3 = atoi(v[3]);
    num4 = atoi(v[4]);
    num5 = atoi(v[5]);
    num6 = atoi(v[6]);
    num7 = atoi(v[7]);
    num8 = atoi(v[8]);
    num9 = atoi(v[9]);
    num10 = atoi(v[10]);
    num11 = atoi(v[11]);
    }
    soma1=((num1*10)+(num2*9)+(num3*8)+(num4*7)+(num5*6)+(num6*5)+(num7*4)+(num8*3)+(num9*2));
    resto1%=((soma1*10)/11);
    if (resto1==v[10]) {
      soma2=((num1*11)+(num2*10)+(num3*9)+(num4*8)+(num5*7)+(num6*6)+(num7*5)+(num8*4)+(num9*3)+(num10*2));
      resto2%=((soma2*10)/11);
      if(resto2==v[11])
        return 1;
      else
        return 0;
    }
    else
      return 0;
  } */

/* usa um for para ler cada caracter do cpf
          //Percorrendo o vetor de char e mostrando
         //cada elemento individualmente
          for (i=0; i<6; i++)
{
  printf("Valor do elemento %d da string = %c\n",i, texto[i]);
}  */
