#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (){

    char w[50];
    int cont=0;
    double avg[cont];
    int words=0,size=0,spc=0,spcP[50],points=0,poitsP[50],num=0,numP[50];
    

    while(scanf(" %[^\n]",w)!=EOF){
        for(int i=0;i<50;i++){
            if(isalpha(w[i])!=0){
                
                words+=1;
                
            }
        }

        avg[cont]=words;
        words=0;
        cont++;
        
        printf("%d\n",cont);
        
        
    }

    for(int i=0;i<cont;i++){
        printf("%lf\n",avg[i]);
    }



    return 0;
}

//O numero de Letras dividido por numero de palavras
//This is a problem statement
//Implement a class H5 which contains some method.
//csly c.npwlrh.xkcirg evjxp.b .xug
//rhgsmwjkmbw tv