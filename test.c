#include<string.h>
#include<stdio.h>
void bubusort(char str[]);
int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]="\0";
    bubsort(str);
    printf("Sorted string is %s",str);
    return 0;
}
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