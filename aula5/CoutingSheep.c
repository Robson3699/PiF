#include <stdio.h>
#include <stdlib.h>

int Sort(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void Check(int c[], int m){
    qsort(c, m, sizeof(int), Sort);

    int cont = 1;

    for (int i = 1; i < m; i++) {
        if (c[i] != c[i - 1]) {
            cont++;
        }
    }

    printf("%d\n", cont);
}





int main(){

    int t=0,n=0;
    scanf("%d", &t);
    
 for(int i=0;i<t;i++){
    scanf("%d",&n);
    int c[n];
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    
    Check(c,n);



 }
   
  


    return 0;
}