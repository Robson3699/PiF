#include <stdio.h>

int main(){
    double m[12][12];
    double sum=0,avg=0;
    char carecter;
    int div=0;
    scanf(" %c",&carecter);

    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            scanf("%lf",&m[i][j]);
        }
    }

    
        for(int i=7;i<12;i++){
            for(int j=12-i ;j<i;j++){
                sum+=m[j][i];
                div+=1;
            }
            
        }
        
    if(carecter=='S'){
        printf("%.1lf\n",sum);
    }if(carecter=='M'){
        avg=sum/div;
        printf("%.1lf\n",avg);
    }
    

    
    return 0;
}