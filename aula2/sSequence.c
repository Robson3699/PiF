#include <stdio.h> 
int main(){
    double s=1;
    double j=1;
    for(double i=1;i<39;){
        s+=(i+2)/(j*2);
        i=i+2;
        j=j*2;
        printf("%.2lf\n",s);

    }printf("%.2lf\n",s);
    return 0;
}