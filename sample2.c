//Write a C program to compute the sum of the two input values. If the two values are the same, then return triple their sum.
#include<stdio.h>

int main(){
    int a,b;
    printf("Enter the first no. : ");
    scanf("%d",&a);
    printf("Enter the seecond no. :");
    scanf("%d",&b);
    if(a==b){
        printf("Sum of both the no. and tripleng it gives:%d \n",a*6);
    }
    int sum;
    sum=a+b;
    printf("Sum of both the no. is %d",sum);
    return 0;
}
