/*
 * TIC_TAC_TOE
 *  23 10.20
 * 
 * GitHub Repository: https://github.com/yahalloe/finalProject-.git
 *
 * library.c
 */
#include "header.h"
static char board [3][3]; 
const char PLAYER = 'X';
const char COMPUTER = 'O';

const char *text1 = "Welcome to the world's most played 2D game! ";
const char *text2 = "The Tic-tac-toe! ";
const char *text3 = "Play\t\t(1)\nRead rules\t(2)\n\nchoice: ";
const char *text4 = "Choose mode:\n\nPlayer vs Player\t(1)\nPlayer vs Bot\t\t(2)\n\nchoice: ";
const char *rule1 = "Rules:-\n";
const char *rule2 = "\n1: Each player will be entering the number to put respective X or O in the desired position";
const char *rule3 = "\n2: Player who gets a combination of 3 same characters either diagonal or horizontally or \nvertically will be declared as the winner";
const char *rule4 = "\n\nEnjoy the game! Be a Winner!\n\n";
const char *text5 = "\n\t\t\t\t Game over\n\t\t\t\t  restart?\n\t\t\t\t   (Y/N)\n\t\t\t\t";
const char *text6 = "\n\t\t\t\t\tOKAY!\n\t\t\t\tThanks for playing!\n\n";

void typeString(const char *text)   
{
    for (int i = 0; text[i] != '\0'; i++) {   
        putchar(text[i]);
        fflush(stdout);
        Sleep(INTER_CHAR_DURATION);
    }
}

void greet(void)
{
    COLORBLUE;
    CLEAR;
    typeString(text1);
    Sleep(INTER_TEXT_DURATION);
    printf("\n\nPress enter");
    getchar();
    CLEAR;
    typeString(text2);
    Sleep(INTER_TEXT_DURATION);
    printf("\n\nPress enter");
    getchar();
    CLEAR;
    typeString(text3);
}

void printRules(void) 
{
    CLEAR;
    typeString(rule1);
    typeString(rule2);
    typeString(rule3);
    typeString(rule4);
}

int getMode(void) {
    CLEAR;
    typeString(text4);
    int m;
    while (1) {
        scanf_s("%d", &m);
        if (m == 1 || m == 2) {
            break;
        }
        else {
        CLEAR;
        printf("\nAgain bruh.\n\n\a> ");
        int c;   
        while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
    return m;
}

void resetBoard(void) 
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(void) 
{
    printf("\n\n\n\t\t\t\tTic-tac-toe\n");
    // printf("\n\t\t\t\t  You = X\n\t\t\t\t  Bot = 0\n\n");
    printf("\t\t\t\t %c | %c | %c \n", board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t\t---|---|---\n");
    printf("\t\t\t\t %c | %c | %c \n", board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t\t---|---|---\n");
    printf("\t\t\t\t %c | %c | %c \n", board[2][0],board[2][1],board[2][2]);
}

int checkFreeSpaces(void)
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

void humanMove(char playerLetter)
{
    int x,y;
    do {
        printf("\n\t\t\t\t  Player %c \n\t\t\tEnter row #(1-3) (horizontal): ", playerLetter);
        scanf_s("%d", &x);
        x--;
        printf("\n\t\t\t\t  Player %c \n\t\t\tEnter column #(1-3) (vertical): ", playerLetter);
        scanf_s("%d", &y);
        y--;

        if(board[x][y] != ' ') {

            printf("\t\t\t\tInvalid Move!\n");
        }
        else{
            board[x][y] = playerLetter;
            break;
        } 
    } while (board[x][y] != ' ');
} 

void computerMove(void)
{
    // seed by time
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

char checkWinner(void) 
{
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // collums
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}   

void printWinner(char winner) 
{
    if (winner != ' ') {
        printf("\n\t\t\t\t  %c WINS!\n", winner);
    }
    else {
        printf("\n\t\t\t\t  IT'S A TIE!\n");
    }
}
