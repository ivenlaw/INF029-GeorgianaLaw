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
  
// Validador de CPF
  int validadorCPFaluno (Ficha aluno[], int nr_aluno, int x) {
    int i, j;
    int num[11];
    char *preNum;
    int numPos;
    
    preNum=aluno[nr_aluno].cpf;
    
    strcpy(preNum,aluno[nr_aluno].cpf);
    numPos=atoi(preNum);
    
    int soma1=0, soma2=0, resto1=0, resto2=0;

    printf("%s %d\n", preNum, numPos);
    printf("x: %d\n", x);
    if (x==10){
       for(int i=0; i<11; i++){     
         num[i]=preNum[i]-48;
         printf("num %d: %d \n", i, num[i]);
       }
        for(i=10, j=0; i>1; i--){
          soma1=soma1+(num[j]*i);
          printf("soma1: %d\n", soma1);
          j++;
        }
    
        resto1=((soma1*10)%11);
        if(resto1==10)
          resto1=0;
        printf("resto1: %d\n", resto1);
        
        if (resto1==num[9]) {
          for(i=11, j=0; i>1; i--){
            soma2=soma2+(num[j]*i);
            printf("soma2: %d\n", soma2);
            j++;
          }  
          resto2=((soma2*10)%11);
          printf("resto1: %d\n", resto1);
          
          if(resto2==num[10]){
            printf("num9: %d\n", num[9]);
            return CPF_VALIDADO;
          }
          else
            return CPF_INCORRETO;
        }
        else        
          return CPF_INCORRETO;  
    }
    else{
      printf("CPF incompleto, digite os 11 números. \n");
    }
    return 0;
}
