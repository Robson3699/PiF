#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int a,b,c,d;
    
}Triangle;

//A<B+C
//B<A+C
//C<A+B

//A<B+D
//B<A+D
//D<A+B

//A<C+D
//C<A+D
//D<A+C

//B<C+D
//C<B+D
//D<C+B

void Exist(Triangle tr){
   if((tr.a<tr.b+tr.c && tr.b<tr.a+tr.c && tr.c<tr.a+tr.b) || 
      (tr.a<tr.b+tr.d && tr.b<tr.a+tr.d && tr.d<tr.a+tr.b) ||
      (tr.a<tr.c+tr.d && tr.c<tr.a+tr.d && tr.d<tr.a+tr.c) ||
      (tr.b<tr.c+tr.d && tr.c<tr.b+tr.d && tr.d<tr.c+tr.b)){
    printf("S\n");

   }else{
    printf("N\n");
   }
}

int main(){
    Triangle tr;
    int *y=malloc(4*sizeof(int));
    for(int i=0;i<4;i++){
        scanf("%d",&y[i]);

    }
    tr.a=y[0];
    tr.b=y[1];
    tr.c=y[2];
    tr.d=y[3];
    Exist(tr);

    free(y);

    return 0;
}