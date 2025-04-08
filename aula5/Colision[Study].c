#include <stdio.h>


int Bsort(int r[]){
    int Biggest=0;

    for(int j=0;j<4;j++){
        if(Biggest<r[j]){
            Biggest=r[j];
        }
    }return Biggest;

}

int Ssort(int r[]){
    int Smallest=r[0];

    for(int j=0;j<4;j++){
        if(Smallest>r[j]){
            Smallest=r[j];
        }
    }return Smallest;

}//int IsRet(int r[],int c[]){
   // int t=0;
   // if(r[0]==r[1]&&r[2]==r[3] && c[0]==c[3]&&c[1]==c[2] && c[1]>=c[0] &&c[2]>=c[3] && r[0]>=r[3] &&r[1]>=r[2]){
    //  return t=1;
   // }else{
    //    return t;
   // }
    
    //ay&&by>dy&&cy

    //ax&&dx<cx&&bx

//}

void Position(int Rx, int Ry, int BigR, int SmaR,int BigC,int SamC){

    

    if(Ry>=SmaR && Ry<=BigR && Rx>=SamC && Rx<=BigC){
        printf("1\n");

    }else{printf("0\n");
    }


}

typedef struct
{   int rx;
    int ry;
    int BiggestRows;
    int SmallestRows;
    int BiggestColums;
    int SmallestColums;
    
}Robot;


int main(){

    int n=0;
    scanf("%d",&n);
    Robot robot[n];
    int rx=0,ry=0;
    int rows[4];
    int colums[4];
    

    

    for(int i=0;i<n;i++){


        for(int j=0;j<4;j++){
           scanf("%d",&colums[j]);
           scanf("%d",&rows[j]);
        }
        scanf("%d", &rx);
        scanf("%d", &ry);
        rx=rx-1;
        ry=(ry*-1)+10;

        robot[i].rx=rx;
        robot[i].ry=ry;
        

        //Organazing******
        for(int j=0;j<4;j++){
            rows[j]=(rows[j]*-1)+10;
        }

        for(int j=0;j<4;j++){
            colums[j]=(colums[j]-1);
        }

         //Organazing******

        //Sorting************************

        robot[i].BiggestRows=Bsort(rows);
        robot[i].BiggestColums=Bsort(colums);
        robot[i].SmallestRows=Ssort(rows);
        robot[i].SmallestColums=Ssort(colums);
       

        //Sorting************************


    }

    for(int i=0;i<n;i++){
        //int t=IsRet(rows,colums);
        //if(t==1){
        Position(robot[i].rx,robot[i].ry,robot[i].BiggestRows,robot[i].SmallestRows,robot[i].BiggestColums,robot[i].SmallestColums);
       // }else{
       //     printf("%d\n",t);
       // }
        
       
    }



return 0;
}