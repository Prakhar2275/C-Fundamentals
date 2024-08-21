#include<stdio.h>

int main(){
    int a;
    printf("Enter the  first no. :");
    scanf("%d",&a);
    int c=0;
    for(int  i=2;i<=10;i++){
        if(a%i==0){
            printf("%d is multiple of %d \n",a,i);
            c++;
        }
    }
    if(c==0){
        printf("not within the range of 2 to 10!!!");
    }
    else if(c>0){
        printf("The given no. is within multiple of 2 to 10!!!");
    }
    return 0;
}
