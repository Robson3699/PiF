#include <stdio.h>


typedef struct{
    int code,qtd;
    double price;
}ProductOne;
typedef struct{
    int code,qtd;
    double price;
}ProductTwo;


int main(){
    ProductOne a;
    ProductTwo b;
    double calc=0;
    scanf("%d",&a.code);
    scanf("%d",&a.qtd);
    scanf("%lf",&a.price);
    scanf("%d",&b.code);
    scanf("%d",&b.qtd);
    scanf("%lf",&b.price);

    calc=(a.qtd*a.price)+(b.qtd*b.price);

    printf("VALOR A PAGAR: R$ %.2lf\n",calc);

    return 0;
}