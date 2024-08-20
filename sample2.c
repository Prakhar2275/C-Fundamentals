#include<stdio.h>
int main(){
    int a;
    printf("Enter the size of the array: ");
    scanf("%d",&a);
    int arr[a];
    printf("Enter %d characters in the array: ",a);
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Elements entered in the arrayy: \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    int i;
    for(i=0;i<a-3;i++){
        if(arr[i]==1 && arr[i+1]==2 &&  arr[i+2]==3){
            printf("Entered array have that provided seuence in it");
            break;
        }
    }
    if(i==a-3){
        printf("Given sequence not founded inside the array!!!");
    }
    return 0;
}
