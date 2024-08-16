#include<stdio.h>
void bubsot(int arr[],int n);
void bubsort(int arr[],int a){
  int c;
  int swapped;
  for(int i=0;i<a-1;i++){
    swapped=0;
    for(int j=0;j<a-1-i;j++){
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
  int arr[a];
  printf("Enter %d characters in the array: ");
  for(int i=0;i<a;i++){
    scanf("%d",&arr[i]);
  }
  printf("\n");
  printf("entered array by the user is: \n");
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
