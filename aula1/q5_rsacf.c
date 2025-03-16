#include <stdio.h>
int main(){
    float A;
    float B;

    scanf("%f", &A);
    scanf("%f", &B);

    float media= (A*3.5 + B*7.5)/11;
    printf("MEDIA = %.5f\n", media);
    return 0;

}