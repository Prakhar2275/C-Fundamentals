//Write a C program to check whether the sequence of numbers 1, 2, 3 appears in a given array of integers somewhere.
#include<stdio.h>
int main(){
    int a;
    printf("Ehter the size of the array: ");
    scanf("%d",&a);
    int arr[a];
    printf("Enter %d elements in the array: \n");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered array by the user: \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    
    for(int j=0;j<a-3;j++){
        if(arr[j]==1 && arr[j+1]==2 && arr[j+2]){
            printf("True!!!!!");
        }
    }

    return 0;
    
}