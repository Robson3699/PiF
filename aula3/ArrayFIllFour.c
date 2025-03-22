#include <stdio.h>

int main(){
    int x[15];
    int even[5];
    int odd[5];
    int eCont=0;
    int oCont=0;
    for(int i=0;i<15;i++){
        scanf("%d",&x[i]);
    }

    for(int i=0;i<15;i++){
        if(x[i]%2==0){
            even[eCont]=x[i];
            eCont++;
            if(eCont>4){
                eCont=0;
                for(int i=0;i<5;i++){
                    printf("par[%d] = %d\n",i, even[i]);
                }
            }

        }else{
            odd[oCont]=x[i];
            oCont++;
            if(oCont>4){
                oCont=0;
                for(int i=0;i<5;i++){
                    printf("impar[%d] = %d\n",i, odd[i]);
                }
            }
        }

    }for(int i=0;i<eCont;i++){
        printf("par[%d] = %d\n",i, even[i]);
    }
    for(int i=0;i<oCont;i++){
        printf("impar[%d] = %d\n",i, odd[i]);
    }
   

    return 0;
}