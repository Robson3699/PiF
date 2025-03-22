#include <stdio.h>

int main(){
    int n=0,s=0,p=0;
    scanf("%d",&n);
    int x[n];
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    s=x[0];
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[j]<x[i]&&x[j]<s){
                s=x[j];
                p=j;
            
            }
        }
    }printf("Menor valor: %d\nPosicao: %d\n",s,p);
    
    return 0;

}