#include <stdio.h>
// #define TAM 3
int main(void) {
  
  int idades[10], media, soma=0, i;

  for(i=0; i<10; i++) {
    printf("Digite 10 idades:\n");
    scanf("%d", &idades[i]);
    soma=soma+idades[i];
  }

  media = soma/10;

  for(i=0; i<10; i++) {
    if (idades[i]>media)
      printf("%d", idades[i]);
  }
}