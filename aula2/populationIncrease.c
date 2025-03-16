#include <stdio.h>

int main(){
    int t=0,pa=0,pb=0;
    float gUm=0,gDois=0;
    int cont=0;
    scanf("%d", &t);
    int temp[t];
    for(int i=0;i<t;i++){
        scanf("%d",&pa);
        scanf("%d",&pb);
        scanf("%f",&gUm);
        scanf("%f",&gDois);
        
        cont=0;

        while(pa<=pb){
            pa+=pa*(gUm/100);
            pb+=pb*(gDois/100);
            cont++;
            if(cont>100){
             temp[i]=cont;
             break;   
            }else{
                temp[i]=cont;
            }

        } 

    }for(int i=0;i<t;i++){
        if(temp[i]>100){
            printf("Mais de 1 seculo.\n");
        }else{
            printf("%d anos.\n",temp[i]);
            
        }
    }
    
    return 0;
}