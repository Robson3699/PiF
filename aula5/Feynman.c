#include <stdio.h>

void Square(int n){
    int side=0;
    side=(n*(n+1)*(n*2+1))/6;
    printf("%d\n",side);
}

typedef struct
{
    int n;
}Feyman;


int main(){
    int exit=1;

    while(exit!=0){
        Feyman fey;
        scanf("%d",&fey.n);
        if(fey.n==0){
            exit=0;
            break;
        }
        Square(fey.n);



    }


    return 0;
}