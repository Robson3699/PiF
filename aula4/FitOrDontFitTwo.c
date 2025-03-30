#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n=0,comprimentoA=0,comprimentoB=0,cont=0,exit=0;
    char a[1001];
    char b[1001];
    scanf("%d", &n);
    int resp[n];

    while(exit!=n){
    scanf("%s", a);
    scanf("%s", b);

    comprimentoA=strlen(a);
    comprimentoB=strlen(b);
    

    for(int i=0;i<comprimentoB;i++){
        if(a[comprimentoA-i]==b[comprimentoB-i]){
            cont+=1;
        }
    }
    if(cont==comprimentoB){
        resp[exit]=1;
    }else{
        resp[exit]=0;
    }
    cont=0;
    exit++;
}

for(int i=0;i<n;i++){
    if(resp[i]==1){
        printf("encaixa\n");
    }else{
        printf("nao encaixa\n");
    }
}


    
    return 0;
}