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

int arms(int n){
    int ogno=n;
    int r,sum=0;
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

    printf("Enter a no. to check it is armstrong or not: ");
    scanf("%d",&a);

    int i=arms(a);

    if(i==0){
        printf("It is not an armstrong no. !!!");
    }
    else if(i==1){
        printf("It is an armstrong no.!!!!!");
    }
    return 0;
}