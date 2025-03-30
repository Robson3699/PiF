#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



void Cypher(char cc[], int k){
    char al[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char dc[50]="";
    int size=strlen(cc);
        for(int i=0;i<size;i++){
            for(int j=0;j<26;j++){
            if(cc[i]==al[j]){
                if(j-k<0){
                    dc[i]=al[j-k+26]; 
                }else{
                dc[i]=al[j-k];
                }
                
            }

        }
    }printf("%s\n",dc);

}

typedef struct {
    char cc[50];
    int code;

}Dados;
        
    


int main(){
    int n=0;
    scanf("%d",&n);
    Dados dados[n];
    

    for(int i=0;i<n;i++){
        scanf("%s",dados[i].cc);
        scanf("%d", &dados[i].code);
    
    }

    for(int i=0;i<n;i++){
        Cypher(dados[i].cc,dados[i].code);
    }


    return 0;
}