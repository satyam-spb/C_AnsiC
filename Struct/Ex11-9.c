#include<stdio.h>
struct vector{
    int a[10];
}v1,v2;
struct vector sum(struct vector v1,struct vector v2,int n);
void main(){
    printf("Enter no. of values of vector\n");
    int n,i;
    scanf("%d",&n);
    printf("\nEnter vector 1\n");
    for ( i = 0; i < n; i++){
        /* code */
        scanf("%d",&v1.a[i]);
    }
    printf("\nEnter vector 2\n");
    for ( i = 0; i < n; i++){
        /* code */
        scanf("%d",&v2.a[i]);
    }
    v1=sum(v1,v2,n);
    printf("\nThe sum is:");
    for ( i = 0; i < n; i++){
        /* code */
        printf("%d ",v1.a[i]);
    }
}
struct vector sum(struct vector v1,struct vector v2,int n){
    //Sum
    int i=0;
    for ( i = 0; i < n; i++){
        /* code */
        v1.a[i]+=v2.a[i];
    }
    return v1;
}