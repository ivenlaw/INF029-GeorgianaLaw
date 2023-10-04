// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Georgiana Glisilli Iven Law
//  email: ivenlaw@gmail.com
//  Matrícula: 20231160014
//  Semestre: 2°

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "GeorgianaLaw-20231160014.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

/* Para saber se um ano é bissexto, devemos verificar se ele se encaixa em um dos casos:

Caso 1) É um número divisível por 4, mas não é divisível por 100.
Caso 2) É um número divisível por 4, por 100 e por 400.

Lembre-se que um número é divisível por outro quando o resto da divisão é zero, ou seja, 
quando o resultado da conta é um número inteiro, sem vírgula. */
  
  //quebrar a string data em strings sDia, sMes, sAno

  //DataQuebrada dataQuebrada = quebraData(data);
  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    //int qtdOcorrencia[s = -1;
  int qtdOcorrencias = -1;
  int x=0;
  
  if (isCaseSensitive==1) {
    if((c>=65 && c<=90)){  
      for(int i=0; texto[i]!='\0'; i++){
        if (c==texto[i]) {
          x+=1;
          if(x==1){
            qtdOcorrencias=0;
            qtdOcorrencias=qtdOcorrencias+1;
         } 
          else
            qtdOcorrencias=qtdOcorrencias+1;
        }
        else if (c!=texto[i] && x==0){
          qtdOcorrencias=0;
        }
      }
    }
    else if ((c>=97 && c<=122)) {
      for(int i=0; texto[i]!='\0'; i++){
        if (c==texto[i]) {
          x+=1;
          if(x==1){
            qtdOcorrencias=0;
            qtdOcorrencias=qtdOcorrencias+1;
          } 
          else
           qtdOcorrencias=qtdOcorrencias+1;
        }
        else if (c!=texto[i] && x==0){
          qtdOcorrencias=0;
        }  
      }
    }
  }
  else if (isCaseSensitive==0) {
    if(c>=65 && c<=90)
      c=c+32;
      for(int i=0; texto[i]!='\0'; i++){
        if (c==texto[i]) {
            x+=1;
            if(x==1){
              qtdOcorrencias=0;
              qtdOcorrencias=qtdOcorrencias+1;
           } 
            else
             qtdOcorrencias=qtdOcorrencias+1;
        }
        else if (c!=texto[i] && x==0){
          qtdOcorrencias=0;
        }
      }
    
    if (c>=97 && c<=122)
      c=c-32;
      for(int i=0; texto[i]!='\0'; i++){
        if (c==texto[i]) {
            x+=1;
            if(x==1){
              qtdOcorrencias=0;
              qtdOcorrencias=qtdOcorrencias+1;
           } 
            else
             qtdOcorrencias=qtdOcorrencias+1;
        }
        else if (c!=texto[i] && x==0){
          qtdOcorrencias=0;
        }
      }
    }
  
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = -1;
  int sizeBusca=0;
  int x=0, y=0, z=0, p=0, i, j;
  
// tamanho string de busca
  for(i=0; strBusca[i]!='\0'; i++) {
    if(strBusca[i]!='\0') {
      sizeBusca+=1;
    }
	}

// busca
  for(i=0; strTexto[i]!='\0'; i++) {
    printf("i=%d, j=%d\n", i, j);
    printf("y=%d, z=%d\n", y, x);
    printf("qtdOcorrencias=%d, p=%d\n", qtdOcorrencias, p);
    j=0;
    while(strBusca[j]!='\0'){
			if(strBusca[j]==strTexto[i]) {
        if (x==0){
          p=i;  
        }
        x+=1;
        j++;
        i++;
				if (x==sizeBusca) {
          z+=1;
          posicoes[y]=p+1;
          y++;
          posicoes[y]=i;
          y++;
          if (z==1){
            qtdOcorrencias=0;
            qtdOcorrencias+=1;
          }
          else if(z>1){
            qtdOcorrencias+=1;
          }
				}
      }	
      else {
        if (qtdOcorrencias<0){
          qtdOcorrencias=0;
        }
        x=0;
        break;
      }
		}
	}

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int n1=num;
  int x=0;
  int n2;
  int numInv=0;

  if(n1>=0 && n1<=9){
    num=n1;
    return num;
  }

	while (n1>0){

    n2=n1%10;
    n1/=10;
    if (x==0){
      numInv=n2;
      x++;}
    else
      numInv=n2+(numInv*10);
  }
    
  num=numInv;

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias=0;
  int vetBusca[30];
  int vetBase[30];
  int tamBusca=0, tamBase=0;
  int nBase=numerobase;
  int nBusca=numerobusca;
  int i=0, j=0, x=0, y=0, k=0, l=0, n2;
  int contaOcorrencia=0;

  if(numerobase==numerobusca){
    qtdOcorrencias=1;
    return qtdOcorrencias;
  }

  while (nBase!=0){
    n2 = nBase % 10;
    nBase /= 10;
    if (i==0){
      vetBase[i]=n2;
//      x++;
    }
    else{
      vetBase[i]=n2;
    }
    tamBase += 1;
    i++;
  }

  for (i=0; i<tamBase;i++){
    printf("vetor base %d é %d tamBase %d \n", i, vetBase[i], tamBase);}

  if (nBusca>=0 && nBusca<=99){
    while (nBusca!=0){
      if(nBusca>=0 && nBusca<=9){
        vetBusca[0]=nBusca;
        tamBusca=1;
        break;
      }
      else if(nBusca>=10 && nBusca<=99){
        n2 = nBusca % 10;
        vetBusca[0]=n2;
        vetBusca[1]=(nBusca/10);
        tamBusca=2;
        break;
      }
    }
  }

  if (nBusca>99){
    while (nBusca!=0){
      n2 = nBusca % 10;
      if (j==0){
        vetBusca[j]=n2;
      }
      if(nBusca>=10 && nBusca<=99){
        n2 = nBusca % 10;
        vetBusca[j]=n2;
        j++;
        vetBusca[j]=(nBusca/10);
        tamBusca+=2;
        break;
      }
      if(j>0){
        vetBusca[j]=n2;
      }
      
      nBusca/=10;
      tamBusca += 1;
      j++;
    }
  }

  for (i=0; i<tamBusca;i++){
    printf("vetor busca %d é %d tamBusca %d \n", i, vetBusca[i], tamBusca);
}
  if (tamBusca==1) {
    for(i=0; i<tamBase; i++){
        if (vetBusca[0]==vetBase[i]){
          qtdOcorrencias += 1;
        }
    }
  }
  else {
//    for(i=0; i<tamBusca; i++){
      for(j=0 , i=0; j<tamBase; j++){
        if (vetBusca[i]==vetBase[j]){
          
          contaOcorrencia += 1;
          k=i+1;
          l=j+1;
          if(vetBusca[k]==vetBase[l]){
            while (vetBusca[k]==vetBase[l]){
              contaOcorrencia += 1;
              l++;
              if(contaOcorrencia==tamBusca){
                qtdOcorrencias += 1;
                k=0;
                break;
              } 
            }
          continue;
          }
        }
        else
          contaOcorrencia=0;
      }
//    }
  }
  return qtdOcorrencias;
}