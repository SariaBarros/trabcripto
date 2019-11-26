//Programa: algoritmo de Euclides
#include<stdio.h>
#include<stdlib.h>

void EuclidesE(long int a, long int b){
    long int M[1000][1000];
   // long int q1, q2;
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
        
   for(int j=0; j<i; j++){
        for(int n=0; n<4; n++)
            printf("%ld ", M[j][n]);
        printf("\n");    
    }

    
  

    //return M[0][0];
}

int main(void){
    long int a, b ;
    
    scanf("%ld %ld", &a, &b);
   
    EuclidesE(a, b);

    return 0;
}