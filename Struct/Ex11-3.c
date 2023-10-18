#include<stdio.h>
struct time_struct
    {
       int hour,minute,second;
    };
    struct time_struct time;
struct time_struct input_value(struct time_struct time);
struct time_struct update(struct time_struct time);
int main()
{
    
    time=input_value(time);
    
    printf("\n This is the test code...Running 1 2 3.....");
    printf("\nThe time is %d:%d:%d \n",time.hour,time.minute,time.second);
    time=update(time);
    printf("The updated time is : %d %d %d",time.hour,time.minute,time.second);
    return 0;
    
}
struct time_struct input_value(struct time_struct time)
{
    printf("Enter time in hour, minutes and seconds\n");
    scanf("%d %d %d",&time.hour,&time.minute,&time.second);
    return time;
}
struct time_struct update(struct time_struct time)
{
    printf("Enter time in seconds to update");
    int sec;
    scanf("%d",&sec);
    time.second+=sec;
    if(time.second>=60)
    {
        time.minute+=time.second/60;
        time.second=time.second%60;
    }
    if(time.minute>=60)
    {
        time.hour+=time.minute/60;
        time.minute=time.minute%60;
    }
    if(time.hour>24)
        time.hour=0;
    return time;
}