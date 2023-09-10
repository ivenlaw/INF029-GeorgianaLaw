// Arquivo central do Projeto Escola

#include <stdio.h>
#include "geral.h"
#include "alunos.h"
#include "professores.h"
#include "relatorios.h"
#include "disciplinas.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int sairGeral = 0;
  Ficha aluno[TAM_ALUNO];
  Ficha professor[TAM_PROFESSOR];
  Materia disciplina[TAM_DISCIPLINA];
  int i, j, v, sexo;
  int nr_aluno = 0;
  int nr_professor=0;
  int nr_disciplina=0;
  int aluno_disciplina=0;


// ABERTURA E RECUPERAÇÃO DO ARQUIVO DE DADOS

  nr_aluno = aberturaArquivoAluno (aluno);
  nr_professor = aberturaArquivoProfessor (professor);
  nr_disciplina = aberturaArquivoDisciplina (disciplina, nr_professor, professor);

// MENU GERAL
  
  while (!sairGeral) {
    int opcaoGeral;
    
    opcaoGeral = menuGeral();

// Direcionamento das opções gerais

    switch (opcaoGeral) {

// opção SAIR
      case 0:
        if (opcaoGeral == 0) {
          printf("\nSistema da escola encerrado.\n\n");
          fechaAluno(aluno, nr_aluno);
          fechaProfessor(professor, nr_professor);
          fechaDisciplina(disciplina, nr_disciplina, nr_professor, professor, aluno, aluno_disciplina, nr_aluno);
          sairGeral = 1;
          break;
        }

// opção CADASTRO DE ALUNOS 
      case 1:{
        if (opcaoGeral == 1) {
        int sairAluno = 0;
         // Menu inicial para Aluno
          while (!sairAluno) {
          printf("\n\n*** Menu Cadastro de Aluno ***\n\n");
          int opcao = menuCadastro(aluno, nr_aluno);
       
          // Direcionamento das opções
            switch (opcao) {
              // Sair do menu Aluno
              case 0:{
                if (opcao == 0) {
                  printf("\nSaindo do cadastro dos alunos.\n\n");
                  
                  sairAluno = 1;
                }
              break;
              }
              // Incluir um aluno no cadastro
              case 1:{
                if (opcao == 1) {
                  int retorno=cadastarAluno(aluno, nr_aluno);
                  if (retorno == CADASTRO_FINALIZADO){
                    nr_aluno++;
                    printf("\nCadastro finalizado.\n\n");
                  } 
                }
              sairAluno = 1;
              break;
              }
              // excluir um aluno do cadastro
              case 2:{
                if (opcao == 2) {
                  int retorno = excluirAluno(aluno, nr_aluno);
                  if(retorno == CADASTRO_EXCLUIDO){
                    printf("\nCadastro excluído\n");
                    nr_aluno--;
                    sairAluno = 1;
                  }
                }
              break;
              }
              // atualizar o cadastro do aluno
              case 3:{
                if (opcao == 3) {
                  int retorno = atualizarAluno (aluno, nr_aluno);
                  if(retorno==CADASTRO_ATUALIZADO) {
                    printf("\nCadastro atualizado\n");
                    sairAluno = 1;
                  }
                  else{
                    if (retorno==MATRICULA_INVALIDA){
                      printf("Matrícula não localizada");
                      sairAluno = 1;
                    }
                  }
                }
              break;
              }
              // Fazer a consulta do cadastro de um alunos
              case 4:{
                if (opcao == 4) {
                  if (nr_aluno==0){
                    printf("\nNão há alunos cadastrados.\n");
                    sairAluno = 1;
                    break;
                  }
                  else {
                    int retorno = listarAluno (aluno, nr_aluno);
                    sairAluno = 1;
                    break; 
                  } 
                }
              break;
              }
              default: {
                printf("Opção inválida.\n");
                break;
              } 
            }
          }
        }
      break;
      }

// opção CADASTRO DE PROFESSORES
      case 2:
        if (opcaoGeral == 2) {
         int sairProfessor = 0;
          // Menu inicial para Professor
          while (!sairProfessor) {
          printf("\n\n*** Menu Cadastro de Professor ***\n\n");
          int opcao = menuCadastro(professor, nr_professor);
          // Direcionamento das opções
            switch (opcao) {
              // Sair do menu Professor
              case 0:{
                if (opcao == 0) {
                  printf("\nSaindo do cadastro dos professor.\n\n");
                  sairProfessor = 1;
                }
              break;
              }
              // Incluir um professor no cadastro
              case 1:{
                if (opcao == 1) {
                  int retorno=cadastarProfessor(professor, nr_professor);
                  if (retorno == CADASTRO_FINALIZADO){
                    printf("\nCadastro finalizado.\n\n");
                    nr_professor++;
                  } 
                }
              sairProfessor = 1;
              break;
              }
              // excluir um professor do cadastro
              case 2:{
                if (opcao == 2) {
                  int retorno = excluirProfessor(professor, nr_professor);
                  if(retorno == CADASTRO_EXCLUIDO){
                    printf("\nCadastro excluído\n");
                    nr_professor--;
                    sairProfessor = 1;
                  }
                }
              break;
              }
              // atualizar o cadastro do professor
              case 3:{
                if (opcao == 3) {
                  int retorno = atualizarProfessor (professor, nr_professor);
                  if(retorno==CADASTRO_ATUALIZADO) {
                    printf("\nCadastro atualizado\n");
                    sairProfessor = 1;
                  }
                  else{
                    if (retorno==MATRICULA_INVALIDA){
                      printf("Matrícula não localizada");
                      sairProfessor = 1;
                    }
                  }
                }
              break;
              }
              // Fazer a consulta do cadastro dos professor
              case 4:{
                if (opcao == 4) {
                  if (nr_professor==0){
                    printf("\nNão há professores cadastrados.\n");
                    sairProfessor = 1;
                    break;
                  }
                  else {
                    int retorno = listarProfessor (professor, nr_professor);
                    sairProfessor = 1;
                    break; 
                  } 
                }
              break;
              }
              default: {
                printf("Opção inválida.\n");
                break;
              } 
            }
          }
          break;
        }

// opção CADASTRO DAS DISCIPLINAS    
      case 3:
        if (opcaoGeral == 3) {
         int sairDisciplina = 0;
          // Menu inicial para Disciplinas
          while (!sairDisciplina) {
          printf("\n\n*** Menu Cadastro de Disciplinas ***\n\n");
          int opcao = menuDisciplina();
          // Direcionamento das opções
            switch (opcao) {
              // Sair do menu Disciplina
              case 0:{
                if (opcao == 0) {
                  printf("\nSaindo do cadastro das Disciplinas.\n\n");
                  sairDisciplina = 1;
                }
              break;
              }
              // Incluir uma disciplina no cadastro
              case 1:{
                if (opcao == 1) {
                  int retorno=cadastarDisciplina(disciplina, nr_disciplina, nr_professor, professor);
                  if (retorno == CADASTRO_FINALIZADO){
                    printf("\nCadastro finalizado.\n\n");
                    nr_disciplina++;
                  } 
                }
              sairDisciplina = 1;
              break;
              }
              // excluir uma disciplina do cadastro
              case 2:{
                if (opcao == 2) {
                  int retorno = excluirDisciplina(disciplina, nr_disciplina);
                  if(retorno == CADASTRO_EXCLUIDO){
                    printf("\nCadastro excluído\n");
                    nr_disciplina--;
                    sairDisciplina = 1;
                  }
                }
              break;
              }
              // atualizar o cadastro da disciplina
              case 3:{
                if (opcao == 3) {
                  int retorno = atualizarDisciplina (disciplina, nr_disciplina, nr_professor, professor);
                  if(retorno==CADASTRO_ATUALIZADO) {
                    printf("\nCadastro atualizado\n");
                    sairDisciplina = 1;
                  }
                  else{
                    if (retorno==CODIGO_INVALIDO){
                      printf("Código não localizado");
                      sairDisciplina = 1;
                    }
                  }
                }
              break;
              }
              // Incluir aluno à disciplina
              case 4:{
                if (opcao == 4) {
                  if (nr_professor==0){
                    printf("\nNão há alunos matriculados.\n");
                    sairDisciplina = 1;
                    break;
                  }
                  else {
                    int retorno = matricularAluno (disciplina, nr_disciplina, nr_aluno, aluno, aluno_disciplina);
                    sairDisciplina = 1;
                    break; 
                  } 
                }
              break;
              }

              // Fazer a consulta do cadastro das disciplina
              case 5:{
                if (opcao == 5) {
                  if (nr_professor==0){
                    printf("\nNão há professores cadastrados.\n");
                    sairDisciplina = 1;
                    break;
                  }
                  else {
                    int retorno = listarDisciplina (disciplina, nr_disciplina, aluno_disciplina);
                    sairDisciplina = 1;
                    break; 
                  } 
                }
              break;
              }
              default: {
                printf("Opção inválida.\n");
                break;
              } 
            }
          }
        break;
      }
// opção RELATÓRIOS

      case 4:
        if (opcaoGeral == 4) {
          int sairRelatorio = 0;
          int opcaoRelatorios = menuRelatorios();
          // Menu inicial de Relatórios
          while (!sairRelatorio) {
          // Direcionamento das opções
            switch (opcaoRelatorios) {
              // Sair do menu Relatórios
              case 0:{
                if (opcaoRelatorios == 0) {
                  printf("\nSaindo do menu Relatórios.\n\n");
                  sairRelatorio = 1;
                  break;
                }
              
              }

              // Listagem de alunos
              case 1:{
                if (opcaoRelatorios == 1) {
                  listarAlunos (aluno, nr_aluno);
                  sairRelatorio = 1;
                  break;
                 }
              }

              // Listar professores
              case 2:{
                if (opcaoRelatorios == 2) {
                  listarProfessores (professor, nr_professor);
                  sairRelatorio = 1;
                }
              break;
              }

              // Listar disciplinas
              case 3:{
                if (opcaoRelatorios == 3) {
                  listarDiscipinas(disciplina, nr_disciplina, aluno_disciplina);
                  sairRelatorio = 1;
                }
              break;
              }

              // Administrativo
              case 4:{
                if (opcaoRelatorios == 4) {
                  listarSexo (aluno, nr_aluno, professor, nr_professor);
                  sairRelatorio = 1;
                }
              break;
              }

              default: {
                printf("Opção inválida.\n");
                break;
              }
            }
          }
          break;
        }   
      default: 
        printf("\nOpção inválida.\n");        
    }
  }
  
  return 0;
}
