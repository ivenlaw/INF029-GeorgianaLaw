// Cadastro Disciplina

#include <stdio.h>
#include "geral.h"
#include "alunos.h"
#include "relatorios.h"
#include "professores.h"
#include "disciplinas.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


// FUNÇÃO com Opcao de cadastramento das disciplinas

int cadastarDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]) {

  int v;

// Cadastrar código da disciplina
  
  printf("\nDigite o código da disciplina: ");
  scanf("%d", &disciplina[nr_disciplina].codigo);
  getchar(); 

// Ativando cadastro 

  disciplina[nr_disciplina].ativo=0;
  
// Cadastrar o nome da disciplina
  
  printf("\nDigite o nome da disciplina: ");
  fflush(stdin);
  fgets(disciplina[nr_disciplina].nome, 51, stdin);
  size_t x = strlen(disciplina[nr_disciplina].nome) - 1;
  if (disciplina[nr_disciplina].nome[x] == '\n')
    disciplina[nr_disciplina].nome[x] = '\0';

// Cadastrar o semestre da disciplina
  
  do {
    printf("\nInforme o semestre da disciplina: (do 1 ao 8): ");
    scanf("%d", &disciplina[nr_disciplina].semestre);
    getchar();
    if (disciplina[nr_disciplina].semestre >= 1 || disciplina[nr_disciplina].semestre <= 8) {      
      v = 1;
    } else {
      printf("\nSemestre inválido. Digite valor entre 1 e 8.\n");

    }
  } while (v == 0);

// Cadastrar o professor vinculado a disciplina

  do {
    int consulta;
    printf("\nQual a matricula do professor que ministra essa disciplina? \n");
    scanf("%d", &consulta);
    for (int i = 0; i < nr_professor; i++) {
      if (professor[i].matricula == consulta) {
        strcpy (disciplina[nr_disciplina].professor,professor[i].nome);
        break;
      }
      else{
        printf("Matrícula %d não localizada", consulta);
      }
    }
  } while (!v); 
  return CADASTRO_FINALIZADO; 
}


// FUNÇÃO para excluir disciplina

int excluirDisciplina (Materia disciplina[], int nr_disciplina) {

  int consulta, i;
  printf("Digite a disciplina a ser excluida: ");
  scanf("%d", &consulta);

  for (i=0; i<nr_disciplina; i++) {
    if (disciplina[i].ativo == -1) {
      printf("Cadastro já inativo");
    }
    else if (disciplina[i].codigo == consulta) 
      disciplina[i].ativo=-1;
    else if (nr_disciplina>0) {
      for(int j=i+1; j<nr_disciplina; j++) {
        disciplina[i]=disciplina[j];
        return CADASTRO_EXCLUIDO;
        break;
      }
    }
  }
return 0;
}

// FUNÇÃO para atualizar um Professor

int atualizarDisciplina (Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]) {
  
  int consulta;
  // TROCA do codigo
  printf("\n\nDigite o código a ser atualizada\n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_disciplina; i++) {
    if (disciplina[i].codigo == consulta) {
      char troca;
      printf("\n** Cadastro do código %d **\n\n", disciplina[i].codigo);
      // TROCA do nome
      printf("Deseja alterar o nome %s? ", disciplina[i].nome);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        printf("\nDigite o novo nome: ");
        fflush(stdin);
        fgets(disciplina[i].nome, 51, stdin);
        size_t x = strlen(disciplina[i].nome) - 1;
        if (disciplina[i].nome[x] == '\n')
          disciplina[i].nome[x] = '\0';
      }
      // TROCA do semestre
      printf("\nDeseja alterar o semestre '%d'? ", disciplina[i].semestre);
      scanf("%c", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o novo semestre (de 1 a 8): ");
          scanf("%d", &disciplina[nr_disciplina].semestre);
          getchar();
          if (disciplina[nr_disciplina].semestre >= 1 || disciplina[nr_disciplina].semestre <= 8) {
            v = 1;
          } else {
            printf("\nSemestre inválido. Digite valor entre 1 e 8.\n");
    //            getchar();
          }
        } while (v == 0);
      }
      //TROCA do professor que ministra a disciplina
      int consulta=0;
      printf("\nDeseja alterar o professor que ministra a disciplina:  %s? ", disciplina[nr_disciplina].professor);
      scanf("%d", &consulta);
      for (int i = 0; i < (nr_professor); i++) {
        if (professor[i].matricula == consulta) {
        strcpy (disciplina[nr_disciplina].professor,professor[i].nome);
        return CADASTRO_ATUALIZADO;
        break;
        }
        else{
          printf("Matrícula %d não localizada", consulta);
          break;
        }
      }
    }
    else{
      return CODIGO_INVALIDO;
      break;
    }
    break;
  }
  return 0;
}


int matricularAluno (Materia disciplina[], int nr_disciplina, int nr_aluno, Ficha aluno[], int aluno_disciplina){

  int sairMatriculando = 0;
  int consulta, x, y, i;
  
  while (!sairMatriculando){
    int opcaoMatriculando;
    printf("\nDeseja realizar uma matricula (s/n)?");
    scanf("%d", &consulta);
      if(consulta =='n' || consulta == 'N') {
        sairMatriculando=1;
        break;
      }
      else if(consulta=='s' || consulta=='S'){
        printf("Digite o codigo da disciplina: \n");
        scanf("%d", &x);
        for(i=0; i<=nr_disciplina; i++) {
          if (disciplina[i].codigo == x){
            printf("\nDigite a matricula do aluno: \n");
            scanf("%d", &y);
            for(i=0; i<=nr_aluno; i++){
              if (aluno[i].matricula == y){
                disciplina[nr_disciplina].alunosMatriculados[aluno_disciplina]= aluno[i].nome;
                sairMatriculando=1;
                break;
              }  
              else {
                printf("Aluno não localizado.\n");
                sairMatriculando=1;
                break;
              }
            }
          }
          else{
            printf("Disciplina não localizada.\n");
            sairMatriculando=1;
            break;
          }
        }
      }
    break;
  }
  return 0;
}


// FUNÇÃO para listar uma Disciplina

int listarDisciplina (Materia disciplina[], int nr_disciplina, int aluno_disciplina){
  int consulta, j;
  printf("\n\nDigite o código a ser consultado: \n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_disciplina; i++) {
    if (disciplina[i].codigo == consulta) {
      printf("\n** Cadastro do código %d **\n\n",
             disciplina[i].codigo);
      printf("Nome: %s\n", disciplina[i].nome);
      printf("Semestre: %d\n", disciplina[i].semestre);
      printf("Professor: %s\n", disciplina[i].professor);
      printf("Alunos matriculados:");
        for(int j=0; j<aluno_disciplina; j++){
          printf("%d", disciplina[i].alunosMatriculados[j]);
            }
      break;
    }
    else{
      printf("Matrícula %d não localizada", consulta);
      break;
    }
}
  return 0;
}

int aberturaArquivoDisciplina (Materia disciplina[], int nr_professor, Ficha professor[]){

  FILE* abrirArquivoDisciplina;
  char linhaDisciplina[TAM_DISC_FICHA];
  int nr_disciplina=0;

  abrirArquivoDisciplina = fopen("fichasDisciplina.txt", "r");
  if(abrirArquivoDisciplina==0){
    printf("Arquivo de dados não disponível. Criando novo arquivo!");
    abrirArquivoDisciplina = fopen("fichasDisciplina.txt", "w");
  }
  else {
    do {
      fgets(linhaDisciplina, TAM_DISC_FICHA, abrirArquivoDisciplina);
      carregarDisciplina (linhaDisciplina, disciplina, nr_disciplina, nr_professor, professor);
      nr_disciplina++;
    } while (!feof(abrirArquivoDisciplina));
  }
  return nr_disciplina;
}

void fechaDisciplina(Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[], Ficha aluno[], int aluno_disciplina, int nr_aluno){

  FILE* abrirArquivoDisciplina;
  abrirArquivoDisciplina = fopen("fichasDisciplina.txt", "w+");
  //char linhaDisciplina[80];
  int i;
  
  for (i = 0; i < nr_disciplina; i++) {
    fprintf(abrirArquivoDisciplina, "%d", disciplina[i].codigo);
    fputs(";", abrirArquivoDisciplina);
    fputs(disciplina[i].nome, abrirArquivoDisciplina);
    fputs(";", abrirArquivoDisciplina);
    fputc(disciplina[i].semestre, abrirArquivoDisciplina);
    fputs(";", abrirArquivoDisciplina);
    fprintf(abrirArquivoDisciplina, "%s", disciplina[i].professor);
    fputs(";", abrirArquivoDisciplina);
    fprintf(abrirArquivoDisciplina, "%s", disciplina[i].alunosMatriculados);
    fputs(";", abrirArquivoDisciplina);
    fprintf(abrirArquivoDisciplina, "%d", disciplina[i].ativo);
    if (i < nr_disciplina - 1)
      fputs("\n", abrirArquivoDisciplina);
  }
  
  fclose(abrirArquivoDisciplina);
  
}

void carregarDisciplina(char linhaDisciplina[], Materia disciplina[], int nr_disciplina, int nr_professor, Ficha professor[]) {

  char *tokD;

  printf("%s", linhaDisciplina);
  
  int cont = 1;
  tokD = strtok(linhaDisciplina, ";");

  while (tokD != 0) {
    switch (cont) {
    case 1: {
      disciplina[nr_disciplina].codigo = atoi(tokD);
      break;
    }
    case 2: {
      strcpy(disciplina[nr_disciplina].nome, tokD);
      break;
    }
    case 3: {
      disciplina[nr_disciplina].semestre=*tokD;
      break;
    }
    case 4: {
      strcpy(disciplina[nr_disciplina].professor, tokD);
      break;
    }
    case 5: {
      strcpy(disciplina[nr_disciplina].alunosMatriculados, tokD);
      break;
    }
    case 6: {
      disciplina[nr_disciplina].ativo = atoi(tokD);
      break;
    }
    }
    printf(" %s\n", tokD);
    tokD = strtok(0, ";");
    cont++;
  }
}
