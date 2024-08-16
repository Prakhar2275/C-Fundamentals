#include<string.h>
#include<stdio.h>
void bubsort(char str[]);
void bubsort(char str[]){
  char temp;
  int swapped;
  int n=strlen(str);
  for(int i=0;i<n-1;i++){
    swapped=0; 
    for(int j=0;j<n-i-1;j++){
      if(str[j]>str[j+1]){
        temp=str[j];
        str[j]=str[j+1];
        str[j+1]=temp;
        swapped=1;
      }
    }
    if(swapped==0){
      break;
    }
  }
}
  


int main(){
  char str[100];
  printf("Enter the string to sort it : ");
  fgets(str,sizeof(str),stdin);
  str[strcspn(str,"\n")]="\0";
  bubsort(str);
  printf("Sorted string is: %s \n",str);
  return 0;
}