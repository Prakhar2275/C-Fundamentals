#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    float v1,v2;
    char op;
    float ans;

    printf("Enter the calculation: ");
    scanf("%f %c %f",&v1,&op,&v2);

    switch(op){
        case '/':ans=v1/v2;
        break;
        case '*':ans=v1*v2;
        break;
        case '+':ans=v1+v2;
        break;
        case '-':ans=v1-v2;
        break;
        case '^':ans=pow(v1,v2);
        break;
        case ' ':sqrt(v2);
        break;
        default:goto fail;
    }
    printf("%.9g%c%.9g=%.6g",v1,op,v2,ans);
    goto exit;
    fail:
    printf("Calculation failed!!!");
    exit:
    return 0;
}