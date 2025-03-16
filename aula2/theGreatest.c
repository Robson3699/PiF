#include <stdio.h>
 
int main() {
 
    int vetor[3]={0,0,0};
    int aux = 0;
    scanf("%d", &vetor[0]);
    scanf("%d", &vetor[1]);
    scanf("%d", &vetor[2]);
    for(int i = 0; i < 3; i++) {
        if(vetor[i]>aux){
            aux=vetor[i];
        }
        
    }printf("%d eh o maior\n", aux);
 
    return 0;
}