#include <stdio.h>

int main(){
    float valor=0;
    float moedas=0;
    int moedasInt=0;
    int valorInt=0;
    scanf("%f", &valor);
    int vetorN[6]={0,0,0,0,0,0};
    int vetorM[5]={0,0,0,0,0};

    ///conversao para inteiros
    valorInt=valor;
    moedas=valor-valorInt;
    moedasInt=moedas*100+0.01;

    ////*NOTAS////
    if(valorInt/100>0){
        vetorN[0]=valorInt/100;
        valorInt=valorInt%100;
    }
        if(valorInt/50>0){
            vetorN[1]=valorInt/50;
            valorInt=valorInt%50;
        }
            if(valorInt/20>0){
                vetorN[2]=valorInt/20;
                valorInt=valorInt%20;
            }
                if(valorInt/10>0){
                    vetorN[3]=valorInt/10;
                    valorInt=valorInt%10;
                }
                    if(valorInt/5>0){
                        vetorN[4]=valorInt/5;
                        valorInt=valorInt%5;
                    }
                        if(valorInt/2>0){
                            vetorN[5]=valorInt/2;
                            valorInt=valorInt%2;
                        }

    ////*MOEDAS////
    if(moedasInt/50>0){
        vetorM[0]=moedasInt/50;
        moedasInt=moedasInt%50;
    }
        if(moedasInt/25>0){
            vetorM[1]=moedasInt/25;
            moedasInt=moedasInt%25;
        }
            if(moedasInt/10>0){
                vetorM[2]=moedasInt/10;
                moedasInt=moedasInt%10;
            }
                if(moedasInt/5>0){
                    vetorM[3]=moedasInt/5;
                    moedasInt=moedasInt%5;
                }if(moedasInt>0){
                    vetorM[4]=moedasInt;
                    
                }
             
   
printf("NOTAS:\n");
printf("%d nota(s) de R$ 100.00\n", vetorN[0]);
printf("%d nota(s) de R$ 50.00\n", vetorN[1]);
printf("%d nota(s) de R$ 20.00\n", vetorN[2]);
printf("%d nota(s) de R$ 10.00\n", vetorN[3]);
printf("%d nota(s) de R$ 5.00\n", vetorN[4]);
printf("%d nota(s) de R$ 2.00\n", vetorN[5]);
printf("MOEDAS:\n");
printf("%d moeda(s) de R$ 1.00\n",valorInt);
printf("%d moeda(s) de R$ 0.50\n", vetorM[0]);
printf("%d moeda(s) de R$ 0.25\n", vetorM[1]);
printf("%d moeda(s) de R$ 0.10\n", vetorM[2]); 
printf("%d moeda(s) de R$ 0.05\n", vetorM[3]); 
printf("%d moeda(s) de R$ 0.01\n", vetorM[4]);


return 0;
}