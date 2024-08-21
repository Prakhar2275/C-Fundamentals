#include<stdio.h>
int main(){
    int a;
    printf("Enter the no. :");
    scanf("%d",&a);
    if(a%3==0){
        printf("True!!3");
    }
    else if(a%7==0){
        printf("True!!7");
    }
    else{
        printf("False");
    }
    return 0;
}