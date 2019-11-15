//Programa: soueu.c
//Programadora: Sandy
//Trabalho de criptografia

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"operacoes.h"

int main(int argc, char *argv[]){

    char *op;
    op = argv[1];
    char a=op[0];
    char Tarefa;

    switch(a){
        case 'F'://Fabio
            do{
                printf("T: ");
                scanf(" %c", &Tarefa);
                printf("\n");
                Fabio(Tarefa);
            }while(Tarefa!='T');
        break;

        case 'P': //Patricia
        break;

        case 'T': //Teodoro
        break;

        case 'E': //Ester
        break;
    }


    return 0;
}