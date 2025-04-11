#include <stdio.h>


void Check(int c[], int m){
    int cont=0;

    for(int i=0;i<m;i++){
        for(int j=1+i;j<m;j++){
            if(c[i]==c[j]&&c[j]>0){
                c[j]=-1;   
            } 
    }
    for(int i=0;i<m;i++){
        for(int j=1+j;j<m;j++){
            if(c[i]!=c[j]&&c[j]>0){
            cont++;
            
            }
        }
    }


    
}printf("%d\n", cont);
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