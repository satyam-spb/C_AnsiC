#include<stdio.h>
struct hotel{
    char name[20],grade;
    float charge;
    int total_rooms;

}h[4];
void sort(struct hotel h[],int n);
int i,j,n;
int main(){
    printf("\nEnter total no. of hotels");
    scanf("%d",&n);
    for ( i = 0; i < n; i++){
        /* code */
        printf("\nFor hotel %d",i+1);
        printf("\nEnter name of the hotel: ");
        scanf(" %s",h[i].name);
        printf("\nEnter grade of the hotel:");
        scanf(" %c",&h[i].grade);
        printf("\nEnter average charge:");
        scanf("%f",&h[i].charge);
        printf("\nEnter total number of rooms:");
        scanf("%d",&h[i].total_rooms);
    }
    sort(h,n);
    printf("\nEnter a grade :");
    char grade;
    float charge;
    scanf(" %c",&grade);
    for ( i = 0; i < n; i++){
        /* code */
        if(h[i].grade==grade)
            printf("\nHotel: %s Charge: %.2f Total rooms: %d",h[i].name,h[i].charge,h[i].total_rooms);

    }
    printf("\nEnter charge:");
    scanf("%f",&charge);
    i=0;
    while (h[i].charge<=charge){
        /* code */
        printf("\nHotel: %s Charge: %.2f Total rooms: %d",h[i].name,h[i].charge,h[i].total_rooms);
        i++;
    }
    if(i==0)
        printf("\nNo hotels below the price range");
    
    
    return 0;
}
void sort(struct hotel h[],int n){
    for ( i = 0; i < n-1; i++){
        /* code */
        for ( j = 0; j< n-1; j++){
            /* code */
            if (h[i].charge>h[i+1].charge){
                /* code */
                float x=h[i].charge;
                h[i].charge=h[i+1].charge;
                h[i+1].charge=x;
            }
            
        }
        
    }
    
}