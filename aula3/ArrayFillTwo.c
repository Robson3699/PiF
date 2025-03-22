#include <stdio.h>

int main(){
    int t[1000];
    int n=0,cont=0;
    scanf("%d",&n);
    
    for(int i=0;i<1000;i++){
        
        t[i]=n-n+cont++;
        if(t[i]==n-1){
            cont=0;

        }
        printf("N[%d] = %d\n",i, t[i]);
    }
    
    return 0;
}
