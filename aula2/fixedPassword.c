#include <stdio.h>
int main(){
    int i=0,p=0;
    while(i!=1){
        scanf("%d",&p);
        if(p!=2002){
            printf("Senha Invalida\n");
        }else{
            printf("Acesso Permitido\n");
            i=1;
        }
    }
    return 0;
}