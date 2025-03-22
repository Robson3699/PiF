#include <stdio.h>

int main(){
    int n[10];
    scanf("%d", &n[0]);

    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            n[j]=n[i]*2;
        }
        printf("N[%d] = %d\n",i, n[i]);
    }

    return 0;
}