#include<stdio.h>
#include<stdlib.h>
struct date
{
    int day,month,year,valid;
};
struct date today;
struct date input(struct date today);
struct date validate(struct date today);
struct date update(struct date today);
struct date nextdate(struct date today);
int days=1;
void main(){
    char month[20][13]={"","January","February","March","April","May","June","July",
    "August","September","October","November","December"};
    today=input(today);
    today=validate(today);
    if(today.valid==5)
        printf("\nThere are only 12 months: 1-12\n");
    else if(today.valid==4)
        printf("\nNot a leap year so February has only 28 days");
    else if(today.valid==3)
        printf("\n%s does not have more than 31 days",month[today.month]);
    else if(today.valid==2)
        printf("\n%s does not have more than 30 days",month[today.month]);
    else if(today.valid==1)
        printf("\nFebruary does not have more than 29 days");
    else{
        printf("\nToday's date is: %d %s %d",today.day,month[today.month],today.year);
        // today=update(today);
        // printf("\nThe updated date is: %d %s %d",today.day,month[today.month],today.year);
        today=nextdate(today);
        printf("\nThe next date is : %d %s %d",today.day,month[today.month],today.year);
    }
} 
struct date input(struct date today) { //To input values
    printf("Enter today's date(dd-mm-yyyy)\n");
    scanf("%2d%2d%4d",&today.day,&today.month,&today.year);
    return today;
}
struct date validate(struct date today) { //To validate the date
    
    if (today.month>12 || today.month<1){
        /* code */
        today.valid=5;
    }
    else{
        if(today.month<8)
        {
            if(today.month==2){ //Check for leap year
                //today.day=today.day-days+1;
                if(today.day>29)
                    today.valid=1; //If Feb input has more days
                else
                {
                    if(today.day==29)
                        if(today.year%4==0 && today.year%100!=0 || today.year%400==0){
                            today.valid=0; // a leap year
                        }
                        else
                            today.valid=4; //Not a leap year
                
                }
            }
            else if(today.month%2!=0 && today.day>31)
                today.valid=3;
            else if(today.month%2==0 && today.day>30)
                today.valid=2;
            else
                today.valid=0;
        }
        else
        {
            if(today.month%2==0 && today.day>31)
                today.valid=3;
            else if(today.month%2!=0 && today.day>30)
                today.valid=2;
            else
                today.valid=0;
        }
    }
    
    return today;
}

struct date update(struct date today){
    today.day+=days; //To use validate fnc
    today=validate(today);
    if(today.valid==4 || today.valid==1){
        today.day=1;
        today.month++;
    }
    else if (today.valid==3 || today.valid==2){
        /* code */
        if(today.month==12){
            today.year++;
            today.day=today.month=1;
        }
        else{
            today.day=1;
            today.month++;
        }
        
    }
    return today;    
}

struct date nextdate(struct date today){
    
    printf("\nEnter the number of days to be added");
    scanf("%d",&days);
    today.day+=days;
    today=validate(today); 
    if(today.month==2){
        if(today.year%4==0 && today.year%100!=0 || today.year%400==0){
            today.month+=today.day/29;
            today.day=today.day%29; // a leap year
        }
        else{
            today.month+=today.day/28;
            today.day=today.day%28; //Not a leap year
        }
    }
    else if(today.valid==2){
        today.month+=today.day/30;
        today.day=today.day%30;
    }
    else if(today.valid==3){
        today.month+=today.day/31;
        today.day=today.day%31;
    }
    if(today.month>12){
        today.year+=today.month/12;
        today.month=today.month%12;
    }
    printf("\n valid=%d",today.valid);
    return today;
}