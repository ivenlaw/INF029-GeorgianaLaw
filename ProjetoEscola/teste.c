// testando

#include <stdio.h>
#include <ctype.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"
#include "professores.h"
#include "disciplinas.h"
#include <stdlib.h>
#include <string.h>

int main () {

  int i;
  int num[11];
  int nr_aluno=0;
  int soma1=0, soma2=0, resto1=0, resto2=0;

  size_t x = strlen(aluno[nr_aluno].cpf) - 1;
  if (x==11){
     for(int i=0; i<13; i++)
       num[i]=aluno[i].cpf;
  }
  else
    printf("CPF incompleto, digite os 11 números. \n");

  for(i=10; i<3; i--){
    int j=0;
    soma1=soma1+(num[j]*i);
  }

  resto1=((soma1*10)%11);

  if (resto1==num[9]) {
    for(i=11; i<3; i--){
      int j=0;
      soma1=soma1+(num[j]*i);
    }  

  resto2=((soma2*10)%11);

  if(resto2==num[10])
//      return CPF_VALIDADO;
  printf("Cadastro Ok");
else
//      return CPF_INCORRETO;
   printf("Cadastro com erro");
}
else
//  return CPF_INCORRETO;*/
printf("Cadastro com erro");

} 
  
/*
  num1 = atoi(aluno[0].cpf);
  num2 = atoi(aluno[1].cpf);
  num3 = atoi(aluno[2].cpf);
  num4 = atoi(aluno[3].cpf);
  num5 = atoi(aluno[4].cpf);
  num6 = atoi(aluno[5].cpf);
  num7 = atoi(aluno[6].cpf);
  num8 = atoi(aluno[7].cpf);
  num9 = atoi(aluno[8].cpf);
  num10 = atoi(aluno[9].cpf);
  num11 = atoi(aluno[10].cpf);
  

  aluno(){
  
  sscanf(aluno[0].cpf, "%d", &num1);
  sscanf(aluno[1].cpf, "%d", &num2);
  sscanf(aluno[2].cpf, "%d", &num3);
  sscanf(aluno[3].cpf, "%d", &num4);
  sscanf(aluno[4].cpf, "%d", &num5);
  sscanf(aluno[5].cpf, "%d", &num6);
  sscanf(aluno[6].cpf, "%d", &num7);
  sscanf(aluno[7].cpf, "%d", &num8);
  sscanf(aluno[8].cpf, "%d", &num9);
  sscanf(aluno[9].cpf, "%d", &num10);
  sscanf(aluno[10].cpf, "%d", &num11);
  }
  
  soma1=((num1*10)+(num2*9)+(num3*8)+(num4*7)+(num5*6)+(num6*5)+(num7*4)+(num8*3)+(num9*2));
  resto1=((soma1*10)%11);
  if (resto1==num9) {
    soma2=((num1*11)+(num2*10)+(num3*9)+(num4*8)+(num5*7)+(num6*6)+(num7*5)+(num8*4)+(num9*3)+(num10*2));
    resto2=((soma2*10)%11);
    if(resto2==num10)
//      return CPF_VALIDADO;
      printf("Cadastro Ok");
    else
//      return CPF_INCORRETO;
       printf("Cadastro com erro");
  }
  else
//  return CPF_INCORRETO;
    printf("Cadastro com erro");
    
} 

} */