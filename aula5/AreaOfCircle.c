#include <stdio.h>
#define n 3.14159

void Area(double r){
    double a= n*(r*r);
    printf("A=%.4lf\n", a);
}
typedef struct 
{double raio;
    
}AreaOfCircle;


int main(){
AreaOfCircle r;
scanf("%lf",&r.raio);
Area(r.raio);



    return 0;
}