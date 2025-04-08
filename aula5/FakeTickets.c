#include <stdio.h>
void Check(int p[], int m){
    int cont=0,contR=0;

    for(int i=0;i<m;i++){
        for(int j=1+i;j<m;j++){
            if(p[i]==p[j]&&p[j]>0){
                cont++;
                p[j]=0;
                
            }
        }if(cont>=1){
            contR+=1;
            cont=0;
        }
    }printf("%d\n", contR);
    
}


int main(){

    int exit=1;
    
 while(exit!=0){
    int n=0,m=0;
    scanf("%d", &n);
    scanf("%d", &m);
    int people[m];
    if(n==0 && m==0){
        exit=0;
        break;
    }

    for(int i=0;i<m;i++){
        scanf("%d",&people[i]);
    }

    Check(people,m);


}
    return 0;
}


   // for(int i=0;i<m;i++){
   //     for(int j=1+i;j<m;j++){
   //         if(people[i]==people[j]&&people[j]>0){
    //            cont++;
    //            people[j]=0;
                
      //      }
      //  }if(cont>=1){
       //     contR+=1;
      //      cont=0;
     //   }
  // }printf("%d\n", contR);
   // cont=0;
    //contR=0;