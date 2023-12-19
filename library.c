/*
 * TIC_TAC_TOE
 *  23 10.20
 * 
 * GitHub Repository: https://github.com/yahalloe/finalProject-.git
 *
 * library.c
 */
#include "h.h"
static char board [3][3]; 
const char PLAYER = 'X';
const char COMPUTER = 'O';

const char *text1 = "Welcome to the world's most played 2D game! ";
const char *text2 = "The Tic-tac-toe! ";
const char *text3 = "Play\t\t(1)\nRead rules\t(2)\n\nchoice: ";
const char *text4 = "Choose mode:\n\nPlayer vs Player\t(1)\nPlayer vs Bot\t\t(2)\nPlayer vs Hard Bot\t(3)\n\nchoice: ";
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
    int m;
    int c; 
    CLEAR;
    typeString(text4);
    while (1) {
        scanf_s("%d", &m);
        if (m == 1 || m == 2 || m == 3) {
            break;
        }
        else {
        CLEAR;
        printf("\nAgain bruh.\n\n\a> ");  
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
        printf("Selected coordinates: (%d, %d)\n", x, y); // Debugging print statement
        if(board[x][y] != ' ') {

            printf("\t\t\t\tInvalid Move!\n");
        }
        else{
            board[x][y] = playerLetter;
            break;
        } 
    } while (board[x][y] != ' ');
} 

void computerMove(int mode) {
    int i, j;
    int found = 0; // Flag to determine if an empty space is found

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = COMPUTER;
                found = 1;
                break; // Break out of the inner loop
            }
        }
        if (found) {
            break; // Break out of the outer loop
        }
    }

    if (!found) {
        printWinner(' ', mode);
    }
}

// Function to find the best move for the computer player using Minimax
void hardComputerMove(void) {
    int bestMove = -1;
    int bestVal = -1000; // Initialize with a very small value
    int moveVal;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                // Make the move
                board[i][j] = COMPUTER;

                // Calculate the evaluation score for this move using Minimax
                moveVal = minimax(0, 0);

                // Undo the move (backtrack)
                board[i][j] = ' ';

                // If the current move is better than the best move so far, update bestMove and bestVal
                if (moveVal > bestVal) {
                    bestMove = i * 3 + j; // Convert 2D coordinates to a 1D index
                    bestVal = moveVal;
                }
            }
        }
    }

    // Make the best move on the board
    if (bestMove != -1) {
        int i = bestMove / 3;  // Row index
        int j = bestMove % 3;  // Column index

        if (board[i][j] == ' ') {
            board[i][j] = COMPUTER; // Place the move only if the cell is empty
        }
        // Add an error message or handle the case where the cell is already occupied
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

void printWinner(char winner, int mode) 
{
    if (winner != ' ') {
        if (mode == 1) {
            printf("\n\t\t\t\t  %c WINS!\n", winner);
        } else {
            if (winner == 'X') {
                printf("\n\t\t\t\t  Player WINS!\n");
            } else if (winner == 'O') {
                printf("\n\t\t\t\t  Computer WINS!\n");
            }
        }
    }
    else {
        printf("\n\t\t\t\t  IT'S A TIE!\n");
    }
}

// Function to check if the current board configuration is terminal (game-over)
int isTerminal(void) {
    // Check for a winner
    char winner = checkWinner();
    if (winner == PLAYER || winner == COMPUTER) {
        return 1; // Game-over: there's a winner
    }

    // Check if the board is full (tie)
    if (checkFreeSpaces() == 0) {
        return 1; // Game-over: board is full (tie)
    }

    return 0; // Game is still in progress
}


// Function to evaluate the score of the current board configuration
int evaluate(void) {
    char winner = checkWinner();
    if (winner == COMPUTER) {
        return 10; // Computer wins, assign a high score
    } else if (winner == PLAYER) {
        return -10; // Player wins, assign a low score
    }

    return 0; // If no winner, return a neutral score
}

// Minimax function
int minimax(int depth, int isMaximizingPlayer) {
    int value;
    if (isTerminal()) {
        return evaluate();
    }

    if (isMaximizingPlayer) {
        int bestVal = -1000; // Initialize with a very small value
        // Loop through available moves
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    // Make the move
                    board[i][j] = COMPUTER;

                    // Calculate the evaluation score for this move using Minimax
                    value = minimax(depth + 1, !isMaximizingPlayer);

                    // Undo the move (backtrack)
                    board[i][j] = ' ';

                    // Update bestVal if needed
                    bestVal = (value > bestVal) ? value : bestVal;
                }
            }
        }
        return bestVal;
    }
    else {
        int bestVal = 1000; // Initialize with a very large value
        // Loop through available moves
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    // Make the move
                    board[i][j] = PLAYER;

                    // Calculate the evaluation score for this move using Minimax
                    value = minimax(depth + 1, !isMaximizingPlayer);

                    // Undo the move (backtrack)
                    board[i][j] = ' ';

                    // Update bestVal if needed
                    bestVal = (value < bestVal) ? value : bestVal;
                }
            }
        }
        return bestVal;
    }
}