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
        case 'F':
            Fabio();
        break;

        case 'P':
            Patricia();
        break;

        case 'T': //Teodoro
            Teodoro();
        break;

        case 'E': //Ester
            Ester();
        break;
    }


    return 0;
}