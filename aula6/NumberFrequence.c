#include <stdio.h>  
#include<stdlib.h>

typedef struct 
{int n;
    int *tam;
    
}NumberFrequence;

int Sort(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void count(NumberFrequence numb){
    for(int i = 0; i < numb.n; i++){
        int current = numb.tam[i];
        int alrdSee = 0;
        for(int k = 0; k < i; k++){
            if (numb.tam[k] == current) {
                alrdSee = 1;
                break;
            }
        }
        if (alrdSee) 
            continue;   

        int freq = 0;
        for(int j = 0; j < numb.n; j++){
            if (numb.tam[j] == current)
                freq++;
        }



        printf("%d aparece %d vez(es)\n", current, freq);
    }
}


int main(){
    
    NumberFrequence number;
    scanf("%d", &number.n);
    number.tam=malloc(number.n*sizeof(int));
    for(int i=0;i<number.n;i++){
        scanf("%d",&*(number.tam+i));
    }
    qsort(number.tam,number.n,sizeof(int),Sort);
    count(number);


    return 0;
}