#include<stdio.h>
#include<math.h>

int count(int n){
    int count=0;
    int r;
    while(n!=0){
        r=n%10;
        count++;
        n/=10;
    }
    return (count);
}

int arms(int n){
    int r;
    int sum=0;
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
    int a ;
    printf("Enter the nno. to check it is armstrong or not: ");
    scanf("%d",&a);
    int i=arms(a);
    if(i==0){
        printf("Entered no. is not an armstrong no.!!!");

    }

    else if(i==1){
        printf("Entered no. is an armstrong no. !!!");;
    }
    return 0;
}