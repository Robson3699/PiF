#include <stdio.h>
#include <stdlib.h>

int Sort(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void Check(int *c, int m){

    int cont = 1;

    for (int i = 1; i < m; i++) {
        if (c[i] != c[i - 1]) {
            cont++;
        }
    }

    printf("%d\n", cont);
}

typedef struct 
{int n;
    int *c;

}Sheep;


int main(){

    int t=0;
    scanf("%d", &t);
    Sheep sheep;
    
 for(int i=0;i<t;i++){
    scanf("%d",&sheep.n);
    sheep.c=malloc(sheep.n*sizeof(int));
    for(int i=0;i<sheep.n;i++){
        scanf("%d",&sheep.c[i]);
    }
    qsort(sheep.c, sheep.n, sizeof(int), Sort);
    Check(sheep.c,sheep.n);
    free(sheep.c);

 }
   
    return 0;
}