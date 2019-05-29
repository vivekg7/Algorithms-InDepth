/* Direct the output of event_sched.c to a file
 * I can check If the output was correct or not
 * Use linux Terminal
 * if wrong output would be 'N'*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    float p1=0, p2;
    int flag=0;
    while(1){
        if(scanf("%f", &p2) != 1) break;
        if(p2 < 100.0){
            flag = 1;
        }else if(flag){
            flag = 0;
            p1 = p2;
        }else{
            if(p1 > p2)
                printf("N ");
            p1 = p2;
        }
    }
    return 0;
}
