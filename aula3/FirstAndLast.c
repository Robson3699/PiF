#include <stdio.h>

int main(){
    int vect[2][2]={{1,2},{3,4}};

    for (int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(j != 1){
                printf("%d ", vect[i][j]);
            }
        }
    }
    return 0;
}