#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

Elementos vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {

//  printf("\n funcao criarEstruturaAuxiliar \n");
  int retorno = 0;
  // a posicao pode já existir estrutura auxiliar
  retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  // se posição é um valor válido {entre 1 e 10}
  retorno = POSICAO_INVALIDA;
  // o tamanho ser muito grande
  retorno = SEM_ESPACO_DE_MEMORIA;
  // o tamanho nao pode ser menor que 1
  retorno = TAMANHO_INVALIDO;
  // deu tudo certo, crie
  retorno = SUCESSO;

  if (vetorPrincipal[posicao].aux != NULL) 
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
  else {  
    if (tamanho < 1) 
      retorno = TAMANHO_INVALIDO;
    else {
        if (ehPosicaoValida(posicao) == SUCESSO ){
          vetorPrincipal[posicao].aux = malloc(tamanho * sizeof(Elementos));
          if (vetorPrincipal[posicao].aux == NULL) {
            retorno = SEM_ESPACO_DE_MEMORIA;
          }
          vetorPrincipal[posicao].tam = tamanho;
          
          retorno = SUCESSO;
          }
        else 
          retorno = POSICAO_INVALIDA;  
    }
  }
  return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {

//  printf("\n funcao inserirNumeroEmEstrutura \n");
  int retorno = 0;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    retorno = POSICAO_INVALIDA;
  else {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao].aux != NULL) {
      if ((vetorPrincipal[posicao].qtd) < (vetorPrincipal[posicao].tam)) {
        // insere
vetorPrincipal[posicao].aux[vetorPrincipal[posicao].qtd] = valor;
        vetorPrincipal[posicao].qtd++;
        retorno = SUCESSO;
      } 
      else {
        retorno = SEM_ESPACO;
      }
    } 
    else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
//  printf("\n funcao excluirNumeroDoFinaldaEstrutura \n");
  int retorno = SUCESSO;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else {
    if (vetorPrincipal[posicao].aux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }  
    else {
      if (vetorPrincipal[posicao].qtd == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
      else {
        vetorPrincipal[posicao].qtd--;
        retorno = SUCESSO;
      }
    }
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
//  printf("\n funcao excluirNumeroEspecificoDeEstrutura \n");
  int i=0;
  int retorno = SUCESSO;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else {
    if (vetorPrincipal[posicao].aux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else {
      if (vetorPrincipal[posicao].qtd == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
      else{
        while (i<vetorPrincipal[posicao].qtd){
          if (vetorPrincipal[posicao].aux[i] == valor){
            for (int j=i; j<vetorPrincipal[posicao].qtd; j++){
                vetorPrincipal[posicao].aux[j] = vetorPrincipal[posicao].aux[j+1];
              }
            vetorPrincipal[posicao].qtd --;
            retorno = SUCESSO;
            break;
          }
          else{
            retorno = NUMERO_INEXISTENTE;  
          }
        i++;
        }
      }
    }
  }
    
  return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {

//  printf("\n funcao ehPosicaoValida \n");
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

//  printf("\n funcao getDadosEstruturaAuxiliar \n");
  int retorno = 0;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else {
    if (vetorPrincipal[posicao].aux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else {
      for(int i=0; i<vetorPrincipal[posicao].qtd; i++){
        vetorAux[i] = vetorPrincipal[posicao].aux[i];
        retorno = SUCESSO;
      }
    } 
  }
  return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

//  printf("\n funcao getDadosOrdenadosEstruturaAuxiliar \n");
  int retorno = 0;
  int z=0, j=0;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else {
    if (vetorPrincipal[posicao].aux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else {
      for(int i=0; i<(vetorPrincipal[posicao].qtd)-1; i++){  
        int menor =i;
        for(int j=i+1; j<vetorPrincipal[posicao].qtd; j++){
          if (vetorAux[j] < vetorAux[menor])
            menor = j;
          }
            z=vetorAux[i];
            vetorAux[i] = vetorAux[menor];
            vetorAux[menor] = z;
      }
      retorno = SUCESSO;
    } 
}

  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

//  printf("\n funcao getDadosDeTodasEstruturasAuxiliares \n");
  int retorno = 0;
  int tamTotal = 0;
  int k=0;

  for (int i = 0; i < TAM; i++){
    tamTotal = tamTotal + (vetorPrincipal[i].qtd);
//    printf(">> vetorPrincipal[%d].qtd = %d\n", i, vetorPrincipal[i].qtd);
  }

  if (tamTotal == 0){
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  else {
    for(int i=0; i<tamTotal; i++){
      if (vetorPrincipal[i].aux != NULL){
        for(int j=0; j<vetorPrincipal[i].qtd; j++){
          vetorAux[k] = vetorPrincipal[i].aux[j];
          k++;
        }
      }
      retorno = SUCESSO;
    }
  }
  return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
//  printf("\n funcao getDadosOrdenadosDeTodasEstruturasAuxiliares \n");
  int retorno = 0;

    int tamTotal = 0;
    int k=0;

    for (int i = 0; i < TAM; i++){
      tamTotal = tamTotal + (vetorPrincipal[i].qtd);
//      printf(">> vetorPrincipal[%d].qtd = %d\n", i, vetorPrincipal[i].qtd);
    }

    if (tamTotal == 0){
      retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else {
      for(int i=0; i<tamTotal; i++){
        if (vetorPrincipal[i].aux != NULL){
          for(int j=0; j<vetorPrincipal[i].qtd; j++){
            vetorAux[k] = vetorPrincipal[i].aux[j];
            k++;
          }
        }
      }
      for(int i=0; i<tamTotal-1; i++){  
        int menor =i;
        for(int j=i+1; j<tamTotal; j++){
          if (vetorAux[j] < vetorAux[menor])
            menor = j;
          }
            int z=vetorAux[i];
            vetorAux[i] = vetorAux[menor];
            vetorAux[menor] = z;
      }
      retorno = SUCESSO;
    }
  return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
//  printf("\n funcao modificarTamanhoEstruturaAuxiliar \n");
  int retorno = 0;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else {
    if (vetorPrincipal[posicao].aux == NULL){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else{
 //     printf("tam ant %d novo ant %d\n", vetorPrincipal[posicao].tam, novoTamanho);
      if ( ((vetorPrincipal[posicao].tam) + novoTamanho) < 1){
//        printf("tam pos %d novo pos %d\n", vetorPrincipal[posicao].tam, novoTamanho);
        retorno = NOVO_TAMANHO_INVALIDO;
      }
      else {
        
        vetorPrincipal[posicao].aux = realloc(vetorPrincipal[posicao].aux, ((vetorPrincipal[posicao].tam) + novoTamanho) * sizeof(Elementos));
 //       printf("tam novo %d\n", vetorPrincipal[posicao].tam);
        if (vetorPrincipal[posicao].aux == NULL) {
          retorno = SEM_ESPACO_DE_MEMORIA;
 //         printf("erro\n");
        }
        vetorPrincipal[posicao].tam = ((vetorPrincipal[posicao].tam) + (novoTamanho));
  //      printf("qtd ant %d\n", vetorPrincipal[posicao].qtd);
        if (vetorPrincipal[posicao].qtd > vetorPrincipal[posicao].tam){
          vetorPrincipal[posicao].qtd = vetorPrincipal[posicao].tam;
 //         printf("qtd novo %d\n", vetorPrincipal[posicao].qtd);
        }
 //       printf("tam novo 2 %d\n", vetorPrincipal[posicao].tam);
        retorno = SUCESSO;
      }
    }
  }
  
  return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

 // printf("\n funcao getQuantidadeElementosEstruturaAuxiliar \n");
  int retorno = 0;

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
 //   printf("posicao invalida");
    retorno = POSICAO_INVALIDA;
  }
  else {
    if (vetorPrincipal[posicao].aux == NULL){
 //     printf("sem estrutura auxiliar");
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    else {
      if (vetorPrincipal[posicao].qtd == 0){
 //       printf("estrutura auxiliar vazia");
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
      else{
  //      printf("qtd %d\n", vetorPrincipal[posicao].qtd);
        retorno = vetorPrincipal[posicao].qtd;
      }
    } 
  }
  return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() { 

  printf( "\n funcao montarListaEncadeadaComCabecote \n");
  No *inicioNovo = (No*) malloc(sizeof(No));
  inicioNovo->prox=NULL;

  No *ant;
  No *novo = (No*) malloc(sizeof(No));
  if(novo == NULL){
    return NULL;
  }

  for(int i=0; i<TAM; i++){
    if (vetorPrincipal[i].aux != NULL){
      if(inicioNovo->prox==NULL){
        inicioNovo->prox = novo;
      }
      else {
        while (j<vetorPrincipal[i].qtd){
          novo->prox = novo;
          novo->conteudo = vetorPrincipal[i].aux[j];
          novo->prox = NULL;
          j++;  
        }
      }
      } 
    }
    else
      return NULL;
  }
  
  return NULL; 
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
  printf("\n funcao getDadosListaEncadeadaComCabecote \n");

  
  
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
  printf("\n funcao destruirListaEncadeadaComCabecote \n");
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {

//  printf("\n função inicializar\n");
  for (int i = 0; i < TAM; i++) {
    vetorPrincipal[i].tam = 0;
    vetorPrincipal[i].aux = NULL;
    vetorPrincipal[i].qtd = 0;
 //   printf(">> vetorPrincipal[%d] = %d\n", i, vetorPrincipal[i].qtd); // TIRAR
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
//  printf("\n funcao finalizar \n");
  for (int i = 0; i < TAM; i++) {
    free(vetorPrincipal[i].aux);    
    vetorPrincipal[i].aux = NULL;
    vetorPrincipal[i].tam = 0;
    vetorPrincipal[i].qtd = 0;  
//    printf("vetorPrincipal[%d].qtd = %d\n", i, vetorPrincipal[i].qtd);
  } 
}