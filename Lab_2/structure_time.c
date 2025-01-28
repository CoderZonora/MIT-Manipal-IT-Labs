#include<stdio.h>
#include<stdlib.h>
struct time{
    int hour;
    int min;
    int sec;
};
void add(struct time t1,struct time t2){
    struct time time_add;
    time_add.hour = t1.hour + t2.hour;
    time_add.min = t1.min + t1.min;
    time_add.sec = t1.sec + t2.sec;
    printf("The sum of time is %d hrs %d mins %d sec",time_add.hour,time_add.min,time_add.sec);
    if(time_add.min>=60){
        time_add.hour += (time_add.min/60);
        time_add.min = (time_add.min%60);
    }
        if(time_add.sec>=60){
        time_add.min += (time_add.sec/60);
        time_add.sec = (time_add.sec%60);
    }
    printf("The sum of time is %d hrs %d mins %d sec",time_add.hour,time_add.min,time_add.sec);
}
void difference(struct time t1, struct time t2){
    struct time t_diff;
    t_diff.hour = t1.hour - t2.hour;
    t_diff.min = t1.min - t2.min;
    t_diff.sec = t1.sec - t2.sec;

    printf("The time difference is %d hrs %d min %d sec",t_diff.hour,t_diff.min,t_diff.sec);
}

int main(){
    struct time t1,t2;
    printf("Enter hour of t1: \n");
    scanf("%d",&(t1.hour));
    printf("Enter min of t1: \n");
    scanf("%d",&(t1.min));
    printf("Enter sec of t1: \n");
    scanf("%d",&(t2.sec));
    printf("Enter hour of t2: \n");
    scanf("%d",&(t2.hour));
    printf("Enter min of t2: \n");
    scanf("%d",&(t2.min));
    printf("Enter sec of t2: \n");
    scanf("%d",&(t2.sec));

    add(t1,t2);
    difference(t1,t2);
}
