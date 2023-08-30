// Cadastro Disciplina

#include <stdio.h>
#include "menus.h"
#include "alunos.h"
#include "relatorios.h"
#include "professores.h"
#include "disciplina.h
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

nome 
codigo
semestre
professor

// Função para cadastrar a Disciplina

int main() {



Digite o código da disciplina: \n

Digite o nome da disciplina: \n

Informe o semestre da disciplina: \n

Qual a matricula do professor que ministra essa disciplina?

scanf("%d", &buscaProfessorDisciplina);

// adicionar uma disciplina ao cadastro do professor ou vice versa

for (int i=0, i<nrProfessor; i++) {

	if(professor[i].matrícula==buscaProfessorDisciplina) {

	professor[i].matricula=disciplina[i].codigo;
	break;	
	}
	else
		printf("\nMatrícula não localizada\n");
}



}