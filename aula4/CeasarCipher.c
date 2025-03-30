#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n=0,k=0,comprimentoCC=0;
    char cc[50],al[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    scanf("%d",&n);
    char dc[50],mResp[n][50];

    for(int i=0;i<n;i++){
        scanf(" %s",cc);
        scanf("%d",&k);
        comprimentoCC=strlen(cc);
        for(int i=0;i<comprimentoCC;i++){
            for(int j=0;j<26;j++){
            if(cc[i]==al[j]){
                if(j-k<0){
                    dc[i]=al[j-k+26]; 
                }else{
                dc[i]=al[j-k];
                }
                
            }

        }
    }for(int j=0;j<50;j++){
        mResp[i][j]=dc[j];
    }
   
        



    }
}