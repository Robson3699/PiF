#include <stdio.h>
#include <stdint.h>

int main(){
    int n=0;
    //**Ou Voce pode declarar unsigned long long int**//
    int64_t fib[61]={0,1,1,2,3,5,8,13,21};
    //**preencher Fibonacci**//
    for(int i=9;i<61;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    //***********************//
    scanf("%d",&n);
    int vet[n];
    for(int i=0;i<n;i++){
        
        scanf("%d",&vet[i]);
        
    }for(int i=0;i<n;i++){
        printf("Fib(%d) = %ld\n",vet[i],fib[vet[i]]);
    }

    
    return 0;
}