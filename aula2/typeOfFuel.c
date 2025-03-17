#include <stdio.h>

int main(){
    int a=0,g=0,d=0,i=0;
    while(i!=4){
        scanf("%d",&i);
        if(i==1){
            a++;
        }else if(i==2){
            g++;
        }else if(i==3){
            d++;
        }
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n",a);
    printf("Gasolina: %d\n",g);
    printf("Diesel: %d\n",d);
    return 0;
}