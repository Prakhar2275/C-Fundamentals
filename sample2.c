#include<stdio.h>
#include<string.h>
void bubsort(char str[]){
  int n=strlen(str);
  int i,j;
  char temp;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(str[j]>str[j+1]){
        temp=str[j];
        str[j]=str[j+1];
        str[j+1]=temp;
      }
    }
  }
}

int main(){
  char str[100];
  printf("Enter the string to sort it: ");
  fgets(str,sizeof(str),stdin);
  str[strcspn(str,"\n")]="\0";
  bubsort(str);
  printf("Sorted string : %s \n",str);
  return 0;
}