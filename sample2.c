#include<stdio.h>

int bubsort(int arr[],int n){
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
    printf("Array after getting swapped: \n");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}

int main(){
    int a;
    printf("Enter the size of the arrya: ");
    scanf("%d",&a);
    int arr[a];
    printf("Enter %d characters in the array: \n");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before Getting swapped: \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    bubsort(arr,a);
    return 0;
}