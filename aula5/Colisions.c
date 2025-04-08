#include <stdio.h>

typedef struct{
    int  Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, Rx, Ry;

}Dados;

void Verify(int Ax,int Ay,int Bx,int By,int Cx,int Cy,int Dx,int Dy,int Rx,int Ry){
    
    printf("%d\n", Ax <= Rx && Dx <= Rx &&
        Rx <= Bx && Rx <= Cx &&
        Ay <= Ry && By <= Ry &&
        Ry <= Cy && Ry <= Dy);

}




int main()
{
    int N;

    scanf("%d", &N);
    Dados dados[N];

    for (int i = 0; i < N; ++i)
    {
        scanf("%d %d %d %d %d %d %d %d %d %d", &dados[i].Ax, &dados[i].Ay, &dados[i].Bx, &dados[i].By, &dados[i].Cx, &dados[i].Cy, &dados[i].Dx, &dados[i].Dy, &dados[i].Rx, &dados[i].Ry);

        Verify(dados[i].Ax, dados[i].Ay, dados[i].Bx, dados[i].By, dados[i].Cx, dados[i].Cy, dados[i].Dx, dados[i].Dy, dados[i].Rx, dados[i].Ry);
    }

    return 0;
}