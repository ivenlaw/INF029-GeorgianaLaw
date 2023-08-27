// Arquivo central do Projeto Escola

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
//#include "professores.h"
#include "relatorios.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main () {

  int sairGeral = 0;
  Ficha aluno[TAM_ALUNO];
  int i, j, v, sexo;
  int nr_aluno = 0;

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
          sairGeral = 1;
          break;
        }

// opção CADASTRO DE ALUNOS 
      case 1:{
        if (opcaoGeral == 1) {
          int sairAluno = 0;
          printf("\n\n*** Menu Cadastro de Aluno ***\n\n");
          int opcao = menuCadastro(aluno, nr_aluno);
          // Menu inicial para Aluno
          while (!sairAluno) {
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
                    printf("\nCadastro finalizado.\n\n");
                    nr_aluno++;
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
                  printf("menu 3.\n");
                }
              break;
              }
              // Fazer a consulta do cadastro dos alunos
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
//        menuCadastro();
        break;
        }

// opção CADASTRO DE PROFESSORES
      case 2:
        if (opcaoGeral == 2) {
//          cadastarProfessor();
          break;
        }

// opção CADASTRO DAS DISCIPLINAS    
      case 3:
        if (opcaoGeral == 3) {
//          cadastarDisciplina();
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
                  printf("\nListar professores.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              // Listar disciplinas
              case 3:{
                if (opcaoRelatorios == 3) {
                  printf("\nListar disciplinas.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              // Administrativo
              case 4:{
                if (opcaoRelatorios == 4) {
                  printf("\nAdministrativo.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              default: {
                printf("Opção inválida.\n");
                break;
              }
                
            break;
            }
          }
        }   
                
    }
  }
  return 0;
}




/* 
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
                  printf("\nListar alunos.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              // Listar professores
              case 2:{
                if (opcaoRelatorios == 2) {
                  printf("\nListar professores.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              // Listar disciplinas
              case 3:{
                if (opcaoRelatorios == 3) {
                  printf("\nListar disciplinas.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              // Administrativo
              case 4:{
                if (opcaoRelatorios == 4) {
                  printf("\nAdministrativo.\n\n");
                  sairRelatorio = 1;
                }
              break;
              }

              default: {
                printf("Opção inválida.\n");
                break;
              }
              
            break;
            }
          }
        }  
            */