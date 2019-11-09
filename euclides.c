//Programa: algoritmo de Euclides
#include<stdio.h>
#include<stdlib.h>

int MDC(int a, int b){
    if(b==0 && a>0)
        return a;
    
    else{
        if(a>0)
            return MDC(b, a%b);
        else{
            while(a<0){
                a=a+b;
            }
            return MDC(b, a%b); 
        }
    }
}

int EuclidesE(int a, int b){
    int oR, nR, oA, nA, oB, nB; //oR="old resto"; nR="new resto"; oA:"antigo coeficiente de A"
    int auxA, auxB, auxR;
    oR = a; nR = b; oA = 1; nA = 0; oB = 0; nB = 1; 
    while(nR != 0){
        auxA = nA; 
        nA = oA - ((oR/nR)*nA);
        auxB = nB;
        nB = oB - ((oR/nR)*nB);
        auxR = nR;
        nR = oR - ((oR/nR)*nR);
        
        oA = auxA;
        oB = auxB;
        oR = auxR;
    }

        printf("a:%d e b: %d\n", nA, nB);
    return 1;
}

int main(void){
    int a, b, r;
    scanf("%d %d", &a, &b);

    r = EuclidesE(a, b);

    printf("%d\n", r);

    return 0;
}