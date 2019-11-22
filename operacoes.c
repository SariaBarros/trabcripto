#include"operacoes.h"


void Fabio(){
	long int s, v, n, r; //valores usados para identificar
	int b;//bit usado para calcular a resposta
	int identificou = 0, respondeu;
	char Tarefa;

	do{
        scanf(" %c", &Tarefa);
        	
		switch(Tarefa){
			case 'I': 
				scanf("%ld %ld %ld", &n, &s, &v);
				Identificar(n, s, v);
				identificou = 1;
			break;

			case 'X':
				if(identificou){
					
					//gerar número aleatório
				}
				else
					printf("E\n");
			break;

			case 'P':
				
				if(identificou){
					r = 0;
					scanf("%ld", &r);
					Preparar(r, n); 
					respondeu = 1;
				}
				else
					printf("E\n");	
			break;

			case 'R':
				scanf("%d", &b);	

				if(identificou && respondeu){
					Responder(b, r, s, n);
					respondeu = 0;
				}
				else
					printf("E\n");	
				
			break;	

			case 'T':
				printf("C\n");
			break; 

		}

	}while(Tarefa!='T');
}

//função identificar: utilizada por fabio
void Identificar(long int n, long int s, long int v){
	long int R;

	R = (((__uint128_t)s*s*v)-1)%n;
	
	if(R==0)
		printf("C\n");
	else
		printf("E\n");

	return; 
}
//função Preparar: utilizada por Fabio
void Preparar (long int r, long int n){
	long int x, resto;
	resto = mdc(r,n);
	

	if(resto==1 && r<n){
		x = (((__uint128_t)r*r))%n;
		printf("C %ld\n", x);
	}
	else
		printf("E\n");
	return;
}

//Função Responder: utilizada por Fabio
void Responder (int b, long int r, long int s, long int n){
	long int x;

	if(b == 0){
		printf("C %ld\n", r);
	}
	else if(b==1) {
		x = (((__uint128_t)r*s))%n;

		printf("C %ld\n", x);
	}
	else
		printf("E\n");
}


long int mdc(__uint128_t a, __uint128_t b){

	if(b==0)
		return a;
	else
		return mdc(b, a%b);
}