#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the first no.:");
    scanf("%d",&a);
    printf("Enter the second nno. :");
    scanf("%d",&b);
    if(a==5 || b==5  || a+b==5  || a-b==5  ||  b-a==5){
        printf("True!!!");
    }
    else{
        printf("False!!!");
    }
    return 0;
}