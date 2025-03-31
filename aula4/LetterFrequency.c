#include <stdio.h>
#include <string.h>
#include <ctype.h>



void alphCont(char text[199]){
    char al[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int size=strlen(text);
    int cont[26];
    

    for(int i=0;i<26;i++){
        cont[i]=0;
        
    }
    for(int i=0;i<199;i++){
        text[i]=toupper(text[i]);
    }


    for(int i=0;i<size;i++){
        for(int j=0;j<26;j++){
            if(text[i]==al[j]){
                cont[i]+=1;
                
            }

        }

    }




}



typedef struct{
    char text[199];
    
}Dados;



int main(){
    int n=0;
    scanf("%d",&n);
    Dados dados[n];
    
    for(int i=0;i<n;i++){
    scanf(" %[^\n]",dados[i].text);
    }
    for(int i=0;i<n;i++){
       alphCont(dados[i].text); 
    }

    


    return 0;
}