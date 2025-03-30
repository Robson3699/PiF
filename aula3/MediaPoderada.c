#include <stdio.h>

int main(){

    double notas[5][2];
    double media[5];


 for(int i=0;i<5;i++){
    for(int j=0;j<2;j++){
        scanf("%lf",&notas[i][j]);
    }
 } 

 for(int i=0;i<5;i++){
    notas[i][0]=notas[i][0]*7;

 }
 for(int i=0;i<5;i++){
    notas[i][1]=notas[i][1]*3;

 }

 for(int i=0;i<5;i++){
    media[i]=(notas[i][0]+notas[i][1])/10;
    printf("media do aluno (%d) eh %.1lf\n",i+1,media[i]);
 }


 

return 0;
}