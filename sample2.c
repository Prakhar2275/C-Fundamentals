#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the first no. :");
    scanf("%d",&a);
    printf("Enter the second no. :");
    scanf("%d",&b);
    int sum;
    sum=a+b;
    if(10<sum<20){
        printf("The answer is 30!!!");
    }
    printf("The real answer is %d",sum);
    return 0;
}