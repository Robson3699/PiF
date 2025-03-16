#include <stdio.h>

int main(){
    int x=0;
    int y=0;
    scanf("%d",&x);
    scanf("%d",&y);
    if(x>=y){
        if(x%y==0){
            printf("Sao Multiplos\n");
        }
        else{
            printf("Nao sao Multiplos\n");
        }
    }
    else{
        if(y%x==0){
            printf("Sao Multiplos\n");
        }
        else{
            printf("Nao sao Multiplos\n");
        }
    }
    return 0;
}