//Write a C program that will take a number as input and find the absolute difference between the input number and 51. If the input number is greater than 51, it will return triple the absolute difference.
#include<stdio.h>

int main(){
    int a;
    printf("Enter a no. :");//taking input of a no.
    scanf("%d",&a);
    if(a<51){
        printf("Diffrence between 51 and %d is %d \n",a,51-a);
    }
    else if(51<a){
        printf("Triple of absolute diffrence is %d",((a-51)*3));
    }
    else{
        printf("Diffrence is zero ad the input is 51 \n");
    }
    return 0;
}