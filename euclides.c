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

int main(void){
    int a, b, r;
    scanf("%d %d", &a, &b);

    r = MDC(a, b);

    printf("%d\n", r);

    return 0;
}