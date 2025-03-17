#include <stdio.h>

int main(){
    double vect[3]={0,0,0};
    scanf("%lf",&vect[0]);
    scanf("%lf",&vect[1]);
    scanf("%lf",&vect[2]); 
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(vect[i]<vect[j]){
                double temp=vect[i];
                vect[i]=vect[j];
                vect[j]=temp;
              }
        }
    }
    if(vect[0]>=vect[1]+vect[2]){
        printf("NAO FORMA TRIANGULO\n");
    }else if(vect[0]*vect[0]==(vect[1]*vect[1])+(vect[2]*vect[2])){
        printf("TRIANGULO RETANGULO\n");
    }else if(vect[0]*vect[0]>(vect[1]*vect[1])+(vect[2]*vect[2])){
        printf("TRIANGULO OBTUSANGULO\n");
    }else if(vect[0]*vect[0]<(vect[1]*vect[1])+(vect[2]*vect[2])){
        printf("TRIANGULO ACUTANGULO\n");
    }if(vect[0]==vect[1]&&vect[0]==vect[2]){
        printf("TRIANGULO EQUILATERO\n");
    }else if(vect[0]==vect[1]||vect[0]==vect[2]||vect[1]==vect[2]){
        printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}