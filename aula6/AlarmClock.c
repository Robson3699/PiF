#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hour,hourFinal;
    int minute,minuteFinal;
} AlarmClock;

void TimeToRest(AlarmClock alarm){
    int hourRest,*x=malloc(sizeof(int));
    x=&hourRest;
    alarm.hour=(alarm.hour*60)+alarm.minute;
    alarm.hourFinal=(alarm.hourFinal*60)+alarm.minuteFinal;

    hourRest=alarm.hourFinal-alarm.hour;
    

    printf("%d\n",*x);
    free(x);
 

}
    

int main(){
    
    int exit=0;
    while(exit==0){
        AlarmClock alarm;
        scanf("%d %d %d %d",&alarm.hour,&alarm.minute,&alarm.hourFinal,&alarm.minuteFinal);
        if(alarm.hour==0 && alarm.minute==0 && alarm.hourFinal==0 && alarm.minuteFinal==0){
            exit=1;
            break;
        }
        if(alarm.hour==0){
            alarm.hour=24;
        }
        
        
        if (alarm.hourFinal < alarm.hour ||
          (alarm.hourFinal == alarm.hour && alarm.minuteFinal < alarm.minute)) {
            alarm.hourFinal += 24;
        }
        TimeToRest(alarm);
    }
    

return 0;
}