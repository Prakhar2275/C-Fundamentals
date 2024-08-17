//sorting of a sting iin c 
#include<stdio.h>
#include<string.h>

void bubsort(char str[]){
    int n=strlen(str);
    int i,j;
    char temp;
    int swapped;
    for(int i=0;i<n-1;i++){
        swapped=0;
        for(int j=0;j<n-1-i;j++){
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
    printf("Enter the string to sort it:  ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]="\0";
    bubsort(str);
    printf("Sorted string: %s",str);
    return 0;
 }
