#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n=0,comprimentoA=0,comprimentoB=0,cont=0,exit=0,spc=0;
    scanf(" %d", &n);
    char a[1001];
    char b[1001];
    int resp[n];

   while(exit!=n){
    scanf(" %[^\n]", a);
    comprimentoA=strlen(a);
    
    for(int i=0;i<comprimentoA;i++){
        if(isspace(a[i])!=0){
            spc=i;
            }
            
        }

        for(int i=0;i<comprimentoA-spc;i++){
            b[i]=a[spc+i+1];
        }

        comprimentoB=strlen(b);
        
        for(int i=0;i<comprimentoB;i++){
            if(a[spc-i-1]==b[comprimentoB-i-1]){
                cont+=1;
                
            }
        }if(cont==comprimentoB){
            resp[exit]=1;
            cont=0;
        }else{
            resp[exit]=0;
            cont=0;
        
        }
        
        fflush(stdin);

        exit++;

    }for(int i=0;i<n;i++){
        if(resp[i]==1){
            printf("encaixa\n");
        }else{
            printf("nao encaixa\n");
        }
    }printf("\n");
      
    return 0;
}
    
    
