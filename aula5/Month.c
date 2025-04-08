#include <stdio.h>

void Month(int m){
    if(m==1){
        printf("January\n");
    }else if(m==2){
        printf("February\n");
    }else if (m==3)
    {
        printf("March\n");
    }else if (m==4)
    {
        printf("April\n");
    }else if (m==5)
    {
        printf("May\n");
    }else if (m==6)
    {
        printf("June\n");
    }else if (m==7)
    {
        printf("July\n");
    }else if (m==8)
    {
        printf("August\n");
    }else if (m==9)
    {
        printf("September\n");
    }else if (m==10)
    {
        printf("October\n");
    }else if (m==11)
    {
        printf("November\n");
    }else
    {
        printf("December\n");
    }
    
}

int main(){
    int M;
    scanf("%d",&M);
    Month(M);


    
    return 0;
}