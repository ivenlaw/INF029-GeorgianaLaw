// Arquivo central do Projeto Escola

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
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
          int opcao = menuCadastro();
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
              // Inclur um aluno no cadastro
              case 1:{
                if (opcao == 1) {
                  int retorno=cadastarAluno();
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
                  printf("\nDigite a matrícula do aluno que deseja excluir: ");
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
              // Fazer a consulta do cadastro de um aluno
              case 4:{
                if (opcao == 4) {
                listarAluno (aluno, nr_aluno);
                int retorno = listarAluno (aluno, nr_aluno);
                if (retorno == MATRICULA_INVALIDA)
                   printf("\nMatrícula não localizada.\n");
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
  
      case 4:
        if (opcaoGeral == 4) {
//         relatorios ();

        break;
        }
  
      default: {
        printf("Opção inválida.\n");
        break;
      }
    }
  }



  
  return 0;

  
  return 0;
}