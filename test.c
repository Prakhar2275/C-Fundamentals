# include<stdio.h>


int bubsort(int arr[], int n){
    int c;
    int swapped;

    for(int i=0;i<n-1;i++){
        swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                c=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=c;
                swapped=0;
            }
        }
        if(swapped==0){
            break;
        }
    }

    printf("Array After Getting Sorted: \n");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    
}



int main(){
  
   
}