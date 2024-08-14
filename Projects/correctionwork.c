#include<stdio.h>
int main(){
    int  a,b;
    printf("Enter the size of first array: ");
    scanf("%d",&a);
    printf("Enter the size of seccond array : ");
    scanf("%d",&b);
    if(a==b){
        int og1[a];
        int og2[a];
        printf("Enter %d cahracters in first array: ",a);
        for(int i=0;i<a;i++){
            scanf("%d",&og1[i]);
        }
        printf("Enter %d character in second array: ",a);
        for(int i=0;i<a;i++){
            scanf("%d",&og2[i]);
        }
        int cpy[a*2];
        for(int i=0;i<a;i++){
            cpy[i]=og1[i];
        }
        for(int i=0;i<a;i++){
            cpy[i+a]=og2[i];
        }
        printf("First array: ");
        for(int i=0;i<a;i++){
            printf("%d ",og1[i]);
        }
        printf("\n");
        printf("Second array: ");
        for(int i=0;i<a;i++){
            printf("%d ",og2[i]);
        }
        printf("\n");
        printf("New formed array: ");
        for(int i=0;i<a*2;i++){
            printf("%d ",cpy[i]);
        }
        printf("\n");
        int c=a*2;
        for(int i=0;i<c;i++){
            for(int j=0;j<c-1;j++){
                if(cpy[j]<=cpy[j+1]){
                    i=cpy[j+1];
                    cpy[j+1]=cpy[j];
                    cpy[j]=j;
                }
            }
        }
        printf("Sorted array: ");
        for(int i=0;i<c;i++){
            printf("%d",&cpy[i]);
        }

    }
    else{
        printf("Entered value is invalid as both the arrays are not having equal character so it wiill not initate the program!!!");
    }
    return 0;

}