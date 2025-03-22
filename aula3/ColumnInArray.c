#include <stdio.h>

int main(){
    double m[12][12];
    int col=0;
    double sum=0,avg=0;
    char carecter;
    scanf("%d",&col);
    scanf(" %c",&carecter);

    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            scanf("%lf",&m[i][j]);
        }
    }

    for(int i=0;i<12;i++){
        sum+=m[i][col];
    }
    if(carecter=='S'){
        printf("%.1lf\n",sum);
    }if(carecter=='M'){
        avg=sum/12;
        printf("%.1lf\n",avg);
    }

    
    return 0;
}