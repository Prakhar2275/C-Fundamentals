#include<stdio.h>
void bubsort(int arr[],int n){
    int c;
    int swapped;
    for(int i=0;i<n-1;i++){
        swapped=0;
        for(int j=0;j<n-i-1;j++){
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
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
int main(){
    int a;
    printf("Enter the size of the array: ");
    scanf("%d",&a);
    int arr[a];
    printf("Enter %d elements in the array: ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("Elemnets enetered by the user in the array: \n");
    for(int i=0;i<a;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    printf("Elements of the arrayy after getting sorteed is: \n");
    bubsort(arr,a);
    return 0;
}