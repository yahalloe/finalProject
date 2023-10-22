#ifndef __header_h
#include "header.h"
#endif
char board [3][3]; 
const char PLAYER = 'X';
const char COMPUTER = 'O';

const char* text1 = "Welcome to the world's most played 2D game!\n";
const char* text2 = "The Tic-tac-toe!\n";
const char* text3 = "Press 1 to play\nPress 2 to read rules\n";
const char* rule1 = "Rules:-\n";
const char* rule2 = "\n1:Each player will be entering the number to put respective X or O in the desired position";
const char* rule3 = "\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner";
const char* rule4 = "\n\nEnjoy the game! Be a Winner!\n\n";
const char* text7 = "Wrong choice.\nNOW THE WOLRD WILL FALL!\n\n...\n\n...\n\n...";
const char* text5 = "\nRestart? (Y/N): ";
const char* text6 = "Thanks for playing!";

void typeString(const char *text)   
{
    for (int i = 0; text[i] != '\0'; i++) {   
        putchar(text[i]);
        fflush(stdout);
        Sleep(100);
    }
}

void resetBoard() 
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() 
{
    printf("Tic-tac-toe\n");
    printf("You play as X, Bot will play as 0\n\n");
    printf(" %c | %c | %c \n", board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0],board[2][1],board[2][2]);
}

int checkFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if  (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x,y;
    do {
        printf("\nEnter row #(1-3)(horizontal): ");
        scanf("%d", &x);
        x--;
        printf("Enter collumn #(1-3)(vertical): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ') {
            printf("Invalid Move!\n");
        }
        else{
            board[x][y] = PLAYER;
            break;
        } 
    } while (board[x][y] != ' ');
} 

void computerMove()
{
    //
    srand(time(0));
    int x,y;
    if (checkFreeSpaces() > 0) {
        do 
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else {
        printWinner(' ');
    }
}

char checkWinner() 
{
    // rows
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // collums
     for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // diagonals
       for (int i = 0; i < 3; i++){
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }
    }
       for (int i = 0; i < 3; i++){
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];
        }
    }
    return ' ';
}   

void printWinner(char winner) 
{
    if(winner == PLAYER) {
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER) {
        printf("YOU LOSE!");
    }
    else {
        printf("IT'S A TIE!");
    }
}
