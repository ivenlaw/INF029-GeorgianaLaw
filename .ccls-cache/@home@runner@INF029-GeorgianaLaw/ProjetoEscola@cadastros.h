// Modularização referente aos cadastros no Projeto Escola

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "alunos.h"
#ifndef cadastros_h
#define cadastros_h


// Prototipos

int menuCadastro();



// struct para datas

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

// struct para ficha de cadastro

typedef struct {

  int matricula;
  char nome[51];
  char sexo;
  Data nascimento;
  char cpf[12];
} Ficha;

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

#endif