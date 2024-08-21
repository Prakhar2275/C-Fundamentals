#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter the three no. :");
    scanf("%d%d%d",&a,&b,&c);
    int d;
    d=a+b;
    if(d==c){
        printf("True!!!!");
    } 
    else{
        printf("False!!");
    }
    return 0;
}