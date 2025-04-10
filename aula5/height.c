#include <stdio.h>


int main(){
int nc=0,n=0;
scanf("%d",&nc);
for(int i=0;i<nc;i++){
    scanf("%d",&n);
    int p[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             if(p[i]>p[j]){
               int temp=p[i];
               p[i]=p[j];
               p[j]=temp;
             }
        }
  }

  for(int j=0; j<n;j++){
    if(j==n-1){
    printf("%d\n",p[j]);
    }else{
        printf("%d ",p[j]);
    }

}
    

}


return 0;

}




