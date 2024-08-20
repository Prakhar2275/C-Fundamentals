//Write a C program to check if two given non-negative integers have the same last digit.

#include<stdio.h>
#include<math.h>

int main(){
    int a,b;
    printf("Enter the first no. :");
    scanf("%d",&a);
    printf("Enter the second no. :");
    scanf("%d",&b);
    int r1,r2;
    r1=a%10;
    r2=b%10;
    if(a>0 && b>0){
        if(r1==r2){
            printf("Both the numbers have same last digit!!!!");
        }
        else{
            printf("Both no. do not have same last digit!!!");
        }
    }
    else{
        printf("Wrong Input!!!!!");
    }
    return 0;
}