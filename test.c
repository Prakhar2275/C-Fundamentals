#include<stdio.h>
#include<math.h>
int count(int n){
    int r;
    int c=0;
    while(n!=0){
        r=n%10;
        c++;
        n/=10;
    }
    return (c);
}
int  arms(int n){
    int r,sum=0;
    int ogno=n;
    int c=count(n);
    while(n!=0){
        r=n%10;
        sum+=pow(r,c);
        n/=10;
    }
    return (ogno==sum);
}
int main(){
    int a;
    printf("Enter the no. to check it is armstrong or not : ");
    scanf("%d",&a);
    int n=arms(a);
    if(n==1){
        printf("It is an armstrong no.!!!!!");
    }
    else if(n==0){
        printf("It is not an armstrong no. !!!!!");
    }
    return 0;
}