#include <stdio.h>

int main(){
    int n[20];
    int x[20];
    for(int i=0;i<20;i++){
        scanf("%d",&n[i]);
       }

       for(int i=0;i<20;i++){
        x[19-i]=n[i];
       }

       for(int i=0;i<20;i++){
        printf("N[%d] = %d\n",i, x[i]);
       }
     
    return 0;
}