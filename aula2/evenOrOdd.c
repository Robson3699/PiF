#include <stdio.h>

int main(){
    int n=0,cont=0;
    scanf("%d",&cont);
    while(cont!=0){
        scanf("%d",&n);
    if(n%2==0 && n>0){
    printf("EVEN POSITIVE\n");
    }else if (n%2==0 && n<0){
        printf("EVEN NEGATIVE\n");
    }if(n%2!=0 && n>0){
        printf("ODD POSITIVE\n");
    }else if(n%2!=0 && n<0){
        printf("ODD NEGATIVE\n");
    }if(n==0){
        printf("NULL\n");
    }
    cont--;
}


    
    return 0;
}