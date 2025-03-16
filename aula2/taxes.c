#include <stdio.h>

int main(){
    float x=0,tx=0;
    scanf("%f",&x);
    if(x<=2000){
        printf("Isento\n");
    }else{
        if(x>2000||x<=3000 && x>0){
        x=x-2000;
        if(x>1000){
            tx+=1000*0.08;
            x=x-1000;
        }else{
        tx+=x*0.08;
        x=x-1000;
        }
    }if(x>0.1||x<=1500 && x>0){
        if(x>1500){
            tx+=1500*0.18;
            x=x-1500;
        }else{
            tx+=x*0.18;
            x=x-1500;
        }
        
    }if(x>0.1){
        tx+=x*0.28;
    }
    printf("R$ %.2f\n",tx);
}


    
    return 0;
}