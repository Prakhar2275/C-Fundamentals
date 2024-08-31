#include<stdio.h>

int isprime(int a);
int isprime(int a){
    int i;
    for(i=2;i<=a;i++){
        if(a%i==0){
            return 1;
        }
    }
    if(i==a){
        return 0;
    }
}

int main(){
    int a;
    printf("Enter the no you want to divide : ");
    scanf("%d",&a);
    int i;
    for(i=1;i<=a/2;i++){
        if(isprime(i)==0 && isprime(a-i)==0){
            printf("Two partts  oof this no. is %d and %d.",i,a-i);
            return 0;
        }
        
    }

    if(i==(a/2)-1){
        printf("Entered no. cant be seprated in this form!!!!");
    }
    return 0;
}