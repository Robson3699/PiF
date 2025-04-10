#include <stdio.h>
#include <stdlib.h>


int Sort(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void Print(int *vet, int n){
    
    for(int j=0; j<n;j++){
        if(j==n-1){
        printf("%d\n",*(vet+j));
        }else{
            printf("%d ",*(vet+j));
        }
    
    }
}

typedef struct 
{int n;
    int *vet;
    
}HeightCity;



int main(){
int nc=0;//n=0;


HeightCity height;
scanf("%d",&nc);

for(int i=0;i<nc;i++){
    scanf("%d",&height.n);
    height.vet=malloc(height.n* sizeof(int));

    for(int i=0;i<height.n;i++){
        scanf("%d",&*(height.vet+i));
    }

    qsort(height.vet,height.n,sizeof(int),Sort);
    
    Print(height.vet,height.n);
    

}


return 0;

}




