#include <stdio.h>
 
int main() {
 
   int x=0;
   int y=0;
   float total=0;
   scanf("%d",&x);
   scanf("%d",&y);
   
   if(x==1){
       total=y*4;
       printf("Total: R$ %.2f\n", total);
   }
   else if(x==2){
       total=y*4.5;
       printf("Total: R$ %.2f\n", total);
   }
   else if(x==3){
       total=y*5;
       printf("Total: R$ %.2f\n", total);
   }
   else if(x==4){
       total=y*2;
       printf("Total: R$ %.2f\n", total);
   }
   else if(x==5){
       total=y*1.5;
       printf("Total: R$ %.2f\n", total);
   }
    
 
    return 0;
}