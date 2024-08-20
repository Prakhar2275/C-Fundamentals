#include<stdio.h>

int triple(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1] && arr[i]==arr[i+2]){
            return 1;
        }
    }
    return 0;
}

int main(){
    int a;
    printf("Enter the size of the array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter %d characters in the array: ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array Entered by the user is: \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    int n=triple(arr,a);
    if(n==0){
        printf("There is no triplet in the array: \n");
    }
    else if(n==1){
        printf("An Triple lies inside the array!!!!\n");
    }
    int sum=0;
    for(int i=0;i<a;i++){
        sum+=arr[i];
    }
    printf("Sum of all the characters inside the array is %d \n",sum);
    printf("You can easily detect the tripplet inside the array then why are you bothering me !!!! \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    return 0;


}
