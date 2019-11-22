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
   

    switch(a){
        case 'F'://Fabio
            Fabio();
        break;

        case 'P': //Patricia
            Patricia();
        break;

        case 'T': //Teodoro
        break;

        case 'E': //Ester
        break;
    }


    return 0;
}