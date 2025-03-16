#include <stdio.h>

int main(){
    int n=0;
    int fib[45]={0,1,1,2,3,5,8,13,21};
    //**preencher Fibonacci**//
    for(int i=9;i<46;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    //***********************//
    scanf("%d",&n);
    for(int j=0; j<n;j++){
        if(j==n-1){
        printf("%d\n",fib[j]);
        }else{
            printf("%d ",fib[j]);
        }

    }
    
    return 0;
}