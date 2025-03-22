#include <stdio.h>
 
int main() {
   int x=0,y=0,z=0;
   scanf("%d", &x);
   scanf("%d", &y);
   scanf("%d", &z);
   int sort[3]={x,y,z};
   for(int i=0;i<3;i++){
         for(int j=i+1;j<3;j++){
              if(sort[i]>sort[j]){
                int temp=sort[i];
                sort[i]=sort[j];
                sort[j]=temp;
              }
         }
   }
   printf("%d\n",sort[0]);
   printf("%d\n",sort[1]);
   printf("%d\n",sort[2]);
   printf("\n");
   printf("%d\n",x);
   printf("%d\n",y);
   printf("%d\n",z);
    return 0;
}