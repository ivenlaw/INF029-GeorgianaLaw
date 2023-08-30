// Cadastro Disciplina

#include <stdio.h>
#include "menus.h"
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
    disciplina[nr_disciplina].semestre = getchar();
    if (disciplina[nr_disciplina].semestre >= 1 || disciplina[nr_disciplina].semestre <= 8) {
      v = 1;
    } else {
      printf("\nSemestre inválido. Digite valor entre 1 e 8.\n");
      v = 0;
      getchar();
    }
  } while (v == 0);

// Cadastrar o professor vinculado a disciplina

    do {
    int consulta, v=0;
    printf("\n\nQual a matricula do professor que ministra essa disciplina? \n");
    scanf("%d", &consulta);
    for (int i = 0; i < (nr_professor); i++) {
    if (professor[i].matricula == consulta) {
      strcpy (disciplina[nr_disciplina].professor,professor[i].nome);
      v=1;
      break;
    }
    else{
      printf("Matrícula %d não localizada", consulta);
      break;
    }
    }
    v=1;
    } while (!v);
  return 0;  
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
    else if (disciplina[i].codigo == consulta) {
      disciplina[i].ativo=-1;
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
      printf("\nDeseja alterar o semestre '%c'? ", disciplina[i].semestre);
      scanf("%s", &troca);
      getchar();
      if((troca=='s') || (troca=='S')) {
        int v=0;
        do {
          printf("\nDigite o novo semestre (de 1 a 8): ");
          disciplina[i].semestre = getchar();
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
}



// FUNÇÃO para listar um Disciplina

int listarDisciplina (Materia disciplina[], int nr_disciplina){
  int consulta, j;
  printf("\n\nDigite o código a ser consultado: \n");
  scanf("%d", &consulta);
  for (int i = 0; i < nr_disciplina; i++) {
    if (disciplina[i].codigo == consulta) {
      printf("\n** Cadastro do código %d **\n\n",
             disciplina[i].codigo);
      printf("Nome: %s\n", disciplina[i].nome);
      printf("Semestre: %c\n", disciplina[i].semestre);
      printf("Professor: %s\n", disciplina[i].professor);
      break;
    }
    else{
      printf("Matrícula %d não localizada", consulta);
      break;
    }
}
  return 0;
}

