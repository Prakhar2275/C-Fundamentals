#include<stdio.h>
void bubsort(int arr[],int n){
    int c;
    int swapped;
    for(int i=0;i<n-1;i++){
        swapped=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                c=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=c;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}
int main(){
    int a;
    printf("Enter the size of the array: ");
    scanf("%d",&a);
    printf("Enter %d charachters in the array: \n",a);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Entered array by the user is \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    bubsort(arr,a);
    printf("Sorted array: \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return 0;
}
