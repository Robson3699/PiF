#include <stdio.h>

int main(){
    double x=0,y=0,z=0;
    scanf("%lf",&x);
    scanf("%lf",&y);
    scanf("%lf",&z); 
    double vect[3]={x,y,z};
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