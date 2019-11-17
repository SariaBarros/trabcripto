#include"operacoes.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Fabio(){
	int p=0, q=0;
	long int s, v, n, r; //valores usados para identificar
	int b;//bit usado para calcular a resposta
	int aux=0, resp = 0, val=0;
	char Tarefa;

	while(Tarefa!='T'){
        printf("T: ");
        scanf(" %c", &Tarefa);
        	
		switch(Tarefa){
			case 'I': 
				scanf("%ld %ld %ld", &n, &s, &v);
				Identificar(n, s, v);
				aux = 1;
			break;

			case 'X':
				if(aux){
					srand(time(NULL));
					r = rand();
					printf("C %ld\n", r);
				}
				else
					printf("E\n");
			break;

			case 'P':
				if(aux){
					scanf("%ld", &r);
					Preparar(r, n);
				}
				else
					printf("E\n");	
			break;

			case 'T':
				printf("C\n");
			break; 

			case 'R':
				scanf("%d", &b);	
				if(b==0||b==1)
					val = 1;
				if(aux && resp==0 && val){
					Responder(b, r, s, n);
					resp = 1;
				}
				else
					printf("E\n");					
		}

	}
}

//função identificar: utilizada por fabio
void Identificar(long int n, long int s, long int v){
	__uint128_t B, A, R;
	long long int r=0, s1;
	s1=s;
	s = s%n;
	while(v>0){
		if(v%2==1)
			r = (r+s)%n;
		s = (s*2)%n;
		v = v/2;
		}
	B = r % n;
	A = ((B%n) * (s1%n))%n;
	R = ((A%n)-(1%n))%n;
	
	if(R==0)
		printf("C\n");
	else
		printf("E\n");

	return; 
}
//função Preparar: utilizada por Fabio
void Preparar (long int r, long int n){
	long int x, resto=0;
	__uint128_t R;
	R = r;

	r = r%n;
	while(R>0){
		if(R%2==1)
			resto = (resto+r)%n;
		r = (r*2)%n;
		R = R/2;
		}
	x = resto % n;
	printf("C %ld\n", x);

	return;
}

//Função Responder: utilizada por Fabio
void Responder (int b, long int r, long int s, long int n){
	long int resto=0, x;

	if(b==0){
		printf("C %ld", r);
	}
	else{                 //xb = r · s mod n
		r = r%n;
		while(s>0){
			if(s%2==1)
				resto = (resto+r)%n;
			r = (r*2)%n;
			s = s/2;
			}
		x = resto % n;
		printf("C %ld\n", x);
	}
}