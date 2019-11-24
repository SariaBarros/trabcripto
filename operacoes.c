#include"operacoes.h"


void Fabio(){
	long int s, v, n, r, g; //valores usados para identificar
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
					g = Gerar_Numero(n);
					printf("C %ld", g);
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

			default:
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

long int Gerar_Numero(long int n){
	long int MAX, MIN;
	int al;
	MAX =  n;
	MIN = 2;
	srand(time(NULL));

	while(MIN != MAX){
		al=rand();

		if(al%2 == 0){
			MAX = MAX/2;
		}
		else
			MIN = MAX/2;		
	}

	return MAX;
}

void Patricia(){
	char Tarefa;
	long int n, v, x, xb;
	int t, bit; //quantidade de vezes que patricia quer a resposta c
	int validado = 1;
	int aux;

	do{
		scanf(" %c", &Tarefa);

		switch (Tarefa){
			case 'I':
				scanf("%ld %ld %d", &n, &v, &t);
				Inicializar(t);
				aux = t;

			break;

			case 'Q':
				scanf("%ld", &x);
				if(validado){
					bit = Gerar_bit(x);
					printf("C %d\n", bit);
				}
				else
					printf("E\n");
					
				validado = 0;
			break;

			case 'V':
				scanf("%ld", &xb);
				if(t>0)
					printf("C %d\n", t);
				else
					printf("E %d\n", t);
				t--;
				validado = 1;
			break;
		
			case 'C':
				scanf("%ld %d %ld", &x, &bit, &xb);
				Testar_Compromisso(x, bit, xb, v, n, &t, aux);
			break;
			
			case 'T':
				printf("C\n");
			break;

			default:
			break;
		}

	}while(Tarefa != 'T');
}

void Inicializar(int t){
	if(3<=t && t<=50)
		printf("C\n");
	else
		printf("E\n");
}

int Gerar_bit(long int x){
	long int MAX, MIN;
	int al;
	MAX =  x;
	MIN = 2;
	srand(time(NULL));

	while(MIN != MAX){
		al=rand();

		if(al%2 == 0){
			MAX = MAX/2;
		}
		else
			MIN = MAX/2;		
	}

	return  MAX%2;
}

void Testar_Compromisso(long int x,int bit, long int xb, long int v, long int n, int *t, int aux){
	
	long int teste;


	if(*t==0)
		printf("E %d\n", *t);

	else{
		if(bit==0){
			teste = ((((__uint128_t)xb*xb)-x)%n); //atenção
			if(teste==0){
				*t = *t - 1;
				printf("C %d\n", *t);
			}	
			else{
				printf("E %d\n", *t);
				*t = aux;
			}
		}
		else if(bit==1){
			teste = (((__uint128_t)v*xb*xb)-x)%n;
			if(teste==0){
				*t = *t - 1;
				printf("C %d\n", *t);
			}
			else{
				printf("E %d\n", *t);
				*t = aux;
			}
		}	
		else{
			//*t = *t - 1;
			printf("E %d\n", *t);
			*t = aux;
		}
	}
			
	return;
}

void Teodoro(){
	char Tarefa;
	int p, q;
	long int n, s;

	do{
        scanf(" %c", &Tarefa);
        	
		switch(Tarefa){
			case 'I': 
				scanf("%d %d", &p, &q);
				n = Inicializar_Teodoro(p,q);
				printf("C %ld\n", n);
			break;

			case 'A':
				Autenticar(n);
			break;

			case 'F':
				scanf("%ld", &s);
				Forjar(s, n);				
			break;	

			case 'T':
				printf("C\n");
			break; 

			default:
			break;

		}

	}while(Tarefa!='T');
}

long int Inicializar_Teodoro(int a, int b){
	return a*b;
}

void Autenticar(long int n){
	long int s, v;

	s = Gerar_Numero(n);
	v = EuclidesE(s*s, n);

	printf("C %ld %ld\n", v, s);

}
long int EuclidesE(long int a, long int b){
    long int M[1000][1000];
    int i = 2, t = 2;

    
    M[0][0] = a;
    M[1][0] = b;
    M[0][2] = 1; 
    M[1][2] = 0; 
    M[0][3] = 0;
    M[1][3] = 1;

    do{
        M[i][0]= M[i-2][0] % M[i-1][0];
        M[i][1]= M[i-2][0] / M[i-1][0];
        i++;
    }while(M[i-3][0] % M[i-2][0] != 0);

    while (t<=i){
        M[t][2] = M[t-2][2] - (M[t-1][2]*M[t][1]);
        M[t][3] = M[t-2][3] - (M[t-1][3]*M[t][1]);
        t++;
    }
        

    return M[i-2][2];
}

void Forjar(long int s, long int n){
	long int v;
	v = EuclidesE(s*s, n);

	while(v<0){
		v = v+n;
	}

	printf("C %ld\n", v);
}