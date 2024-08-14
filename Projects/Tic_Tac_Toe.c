#include<stdio.h>  //all extensions
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER='X';
const char COMPUTER='O';

//all functions to be formed
void resetboard();
void printboard();
int checkfreespace();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);

int main(){
    char winner=' ';

    resetboard();
    while( winner==' ' && checkfreespace() != 0){
        printboard();
        
        playermove();
        winner=checkwinner();
        if(winner!=' ' || checkfreespace()==0){
            break;
        }

        computermove();
        winner=checkwinner();
        if(winner!=' ' || checkfreespace()==0){
            break;
        }


    }
    printboard();
    printwinner(winner);
    return 0;
}
void resetboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}
void printboard(){
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n");
    printf("\n");
}

int checkfreespace(){
    int freespaces=9;
    for(int i=0;i<3;i++){
        for(int  j=0;j<3;j++){
            if(board[i][j]!=' '){
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playermove(){
    int x,y;
    do{
        printf("Enter the row no.(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter the no. of column (1-3): ");
        scanf("%d",&y);
        y--;
        if(board[x][y]!=' '){
            printf("Invalid input!!!");
        }
        else{
            board[x][y]=PLAYER;
            break;
        }
    }while(board[x][y]!=' ');

}

void computermove(){
    //create a seed based on current time
    srand(time(0));
    int x,y;
    
    if(checkfreespace()>0){
        do{
            x=rand()%3;
            y=rand()%3;

        }while(board[x][y]!=' ');
        board[x][y]=COMPUTER;
    }
    else{
        printwinner(' ');
    }
    

}

char checkwinner(){
    //check rows
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[0][i]== board[2][i] ){
            return board[0][i];
        }
    }
    //check diognals
    
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2]){
        return board[0][0];
    }
   
    if(board[0][2]==board[1][1] && board[0][2]==board[2][0]){
        return board[0][2];
    }
    return ' ';
}

void printwinner(char  winner){
    if (winner==PLAYER)
    {
        printf("You win!!!");
    }
    else if(winner==COMPUTER){
        printf("You Lose!!!");
    }
    else{
        printf("Its a tie!!");
    }
}
