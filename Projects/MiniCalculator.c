#include<stdio.h>
void sum(int a);
void sum(int a){
    int result=0;
    for(int i=1;i<=a;i++){
        int no;
        printf("Enter the no. \n:");
        scanf("%d",&no);
        result=result+no;
    }
    printf("sum of all the no. entered is: %d \n",result);
}
void product(int a);
void product(int a){
    int multi=1;
    for(int i=1;i<=a;i++){
        int no;
        printf("Enter the no. : \n");
        scanf("%d",&no);;
        multi=multi*no;
    }
    printf("Product of given no. is %d \n",multi);
}
void subtract(int a);
void subtract(int a){
    int sub=0;
    for(int i=1;i<=a;i++){
        int no;
        printf("Enter the no. : \n");
        scanf("%d",&no);
        sub=sub-no;

    }
    printf("Total of given no. is %d \n",sub);

}
void division(int a,int b);
void division(int a,int b){
    float c;
    c=a/b;
    printf("Division result %f \n",c);
}
int main(){
    printf("WELCOME TO MINI CALCUTOR!!!!! \n");
    for(int i=1;;i++){
        int a;
        printf("Enterr the type of calcultion 1=sum 2=subtraction 3=mutiplication 4=divisionn 5=calculatorr close:");
        scanf("%d",&a);
        if(a==5){
            break;
        }
        else if(a==1){
            int c;
            printf("Enter the total no. to add: \n ");
            scanf("%d",&c);
            sum(c);
        }
        else if(a==2){
            int c;
            printf("Enter the total no. to subtaract: \n");
            scanf("%d",&c);
            subtract(c);
        }
        else if(a==3){
            int c;
            printf("Enter the total no to be multipplied: /n");
            scanf("%d",&c);
            product(c);
        }
        else if(a==4){
            int one,two;
            printf("Enter the divident: ");
            scanf("%d",&one);
            printf("Enter the divisor");
            scanf("%d",&two);
            division(one,two);
        }
        else{
            printf("Wronng choice entered!!!!!");
        }

    }
    printf("PROGRAM FINISHED CALCULATOR CLOSED!!!!!");
    return 0;
}