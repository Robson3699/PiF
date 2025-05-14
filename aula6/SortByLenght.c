#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void SortByLenght(Name name[]){


}

typedef struct 
{
    char *tam;
}Name;


int main(){
    int n=0;
    scanf("%d",&n);
    Name name[n];
    char x[51];
    
    for(int i=0;i<n;i++){
    scanf(" %50[^\n]", x);
    size_t len = strlen(x);
    name[i].tam = malloc(len + 1);
    strcpy(name[i].tam, x);

    }
    


    return 0;
}