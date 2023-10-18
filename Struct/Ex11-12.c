#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct census{
    char city[20];
    long int population;
    float literacy;
}c[5];
int i=0,j=0;
void sort_city(struct census c[]);
struct census sort_population(struct census c[]);
struct census sort_literacy(struct census c[]);
int main(){
    printf("\nEnter details for 5 cities\n");
    for ( i = 0; i < 5; i++){
        /* code */
        printf("\nEnter name of city %d ",i+1);
        scanf("%s",c[i].city);
        printf("\nEnter population of city %d ",i+1);
        scanf("%ld",&c[i].population);
        printf("\nEnter literacy rate of city %d ",i+1);
        scanf("%f",&c[i].literacy);
    }
    sort_city(c);
    
    return 0;
}
void sort_city(struct census c[]){
    for ( i = 0; i < 2; i++){
        /* code */
        for ( j= 0; j < 2; j++){
            /* code */
            if(strcmp(c[j].city,c[j+1].city)>0){
                char x[20];
                strcpy(x,c[j].city);
                strcpy(c[j].city,c[j+1].city);
                strcpy(c[j+1].city,x);
            }
        }
    }
    printf("\nThe sorted list alphabetically:");
    for ( i = 0; i < 3; i++){
        /* code */
        printf("\n%s %ld %f\n",c[i].city,c[i].population,c[i].literacy);
    }
    
}