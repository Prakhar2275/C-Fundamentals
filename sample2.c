#include<stdio.h>
int main(){
    int a;
    printf("Enter the no. :");
    scanf("%d",&a);
    if(a%13==0 || (a+1)%13==0){
        printf("True!!!!");

    }
    else{
        printf("False!!");
    }
    return 0;
}