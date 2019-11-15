#include"operacoes.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Fabio(){
	int p=0, q=0, r;
	long int s, v, n; //valores usados para identificar
	int aux=0;
	char Tarefa;

	do{
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
						printf("C %d\n", r);
					}
					else
						printf("E\n");
			
			break;
	}

	}while(Tarefa!='T');
}

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