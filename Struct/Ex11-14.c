#include<stdio.h>
#include<string.h>
struct cricket{
    char player[20],team[20];
    float batting_avg;
}c[10];
int sort_team(struct cricket c[],int n,char [][20]);
int main(){
    printf("\nEnter total no. of players ");
    int n=0,i,j;
    scanf("%d",&n);
    for ( i = 0; i < n; i++){
        /* code */
        printf("\nFor player %d",i+1);
        printf("\nEnter player name: ");
        scanf(" %s",c[i].player);
        printf("\nEnter his team ");
        scanf(" %s",c[i].team);
        printf("\nEnter his batting average ");
        scanf("%f",&c[i].batting_avg);
    }
    char team[n][20];
    strcpy(team[0],c[0].team);
    int total_team=sort_team(c,n,team),k=0;
    printf("\nTotal teams: %d",total_team);
    
    /*for ( i = 1; i < n; i++){
        for ( j = 0; j < total_team; j++){
            if(strcmp(c[i].team,team[j])==0)
                break;
            else{
                strcpy(team[++k],c[i].team);
                break;
            }
        }
    } */

    //For testing 
    /*for ( i = 0; i < total_team; i++){
        printf("\nTeam %s",team[i]);
    } */
    
    printf("\n\nPlayers according to their teams: \n\n");
    for ( i = 0; i < total_team; i++){
        printf("\nTeam %s:",team[i]);
        for ( j = 0; j < n; j++){
            if(strcmp(c[j].team,team[i])==0)
                printf("\nName: %s\tBatting average: %.2f\n",c[j].player,c[j].batting_avg);
        }
        
    } 
    
    
    return 0;
}

int sort_team(struct cricket c[],int n,char team[][20]){
    int t=0,i,j,k=0;
    /*for (int i = 0; i < n; i++){
        if(strcmp(c[0].team,c[i].team))
            t++;
    }*/
    for ( i = 1; i < n; i++){
        for ( j = 0; j < i; j++){
            if(strcmp(c[i].team,team[j])==0){
                break;
            }
            /*else{
                strcpy(team[++k],c[i].team);
                break;
            }*/
        }
        if(j==i)
            strcpy(team[++k],c[i].team);
    }

    return ++k;
    
}