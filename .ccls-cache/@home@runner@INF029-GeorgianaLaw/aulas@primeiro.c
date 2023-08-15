#include <stdio.h>
#define TAM 10
int main(void) {
  
  int idades[TAM], media, soma=0, i;

  for(i=0; i<TAM; i++) {
    printf("Digite %d idades:\n", TAM);
    scanf("%d", &idades[i]);
    soma=soma+idades[i];
  }

  media = soma/TAM;

  for(i=0; i<TAM; i++) {
    if (idades[i]>media)
      printf("%d\n", idades[i]);
  }
}