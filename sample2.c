#include<stdio.h>

int main(){
    int a,b;
    printf("Enter the first no. :");
    scanf("%d",&a);
    printf("Enter the second no. :");//input the characters
    scanf("%d",&b);
    if(a==30 || b==30 || a+b==30){//checking the condition
        printf("True!!!!! \n");
    }
    else{
        printf("False!!!!!\n");
    }
    return 0;
}