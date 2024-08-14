#include<stdio.h>
int main(){
    int a;
    printf("Enter the size of hourglass (half):");
    scanf("%d",&a);
    for(int i=1;i<=a*2-1;i++){
        printf("*");
    }
    printf("\n");
    for(int i=a-1;i>=1;i--){
        for(int j=1;j<=a-i;j++){
            printf(" ");
        }
        printf("*");
        for(int k=1;k<=i*2-3;k++){
            printf(" ");
        }
        if(i>1){
            printf("*");
        }   
        printf("\n");
    }
    for(int i=1;i<=a-1;i++){
        for(int j=1;j<=a-i;j++){
            printf(" ");
        }
        if(i==1){
            printf("*");
            printf("\n");
        }
        if(i>1){
            printf("*");
            for(int k=1;k<=i*2-3;k++){
                printf(" ");
            }
            printf("*");
            printf("\n");
        }
    }
    for(int i=1;i<=a*2-1;i++){
        printf("*");
    }
    printf("\n");

    return 0;
}