#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#define INTER_CHAR_DURATION 75
#define INTER_TEXT_DURATION 900
#if defined(_WIN32) || defined(__WIN32__)
#include <Windows.h>
#define CLEAR system("cls")
#define COLORBLUE system("color 09")
#elif defined (unix) || defined(__unix) || defined(__unix) || defined(__linux__)
#include <termios.h>
#include <unistd.h>
#define CLEAR system("clear")   
#define COLORBLUE printf("\033[34m")
#endif

extern const char PLAYER;
extern const char COMPUTER;
extern const char *text1;
extern const char *text2;
extern const char *text3;
extern const char *text4;
extern const char *rule1;
extern const char *rule2;
extern const char *rule3;
extern const char *rule4;
extern const char *text7;
extern const char *text5;
extern const char *text6;


/*
 * for some reason, i need to declare these here even tho I didn't need to 
 * declare the char here. I'm not sure but it's probably due to the type. Otherwise,
 * if I didn't do this, I need to include library.c file on the main file.
 * 
 * update: 
 * -I know the reason now. I need to declare it here but with extern. extern ensures
 * that the content of the intialization is somewhere in the files.
 * - I can just put the declaration and everything on the source file (library.c) here but
 * I think it's much cleaner if I put them in different files like I'm doing rn.
 * 10.28 - now I know why scanf() isn't safe. It's because it can only read 
 * one type of data.
 */


//===============================================================================================
//                                     funtions 
//===============================================================================================


/*
 *  function to put out text 1 and so on in a type-writter like fashion
 */
void typeString(const char *text);

/*
 * Prints a Welcome Message
 */
void greet(void);

/*
 * Prints the rules
 */
void printRules(void);

/*
 *  gets the mode thet the players wants to play
 */
int getMode(void);

/*
 * resets the board after the move had inputed by the user
 */
void resetBoard(void);

/*
 * Prints the 2d board
 */
void printBoard(void);

/*
 * Checks whether there is no input on the coordinate on the board
 */
int checkFreeSpaces(void);

/*
 * funtion for the player's (human) move
 */
void humanMove(char playerLetter);

/*
 * funtion for the player's move
 */
void computerMove(void);

/*
 * return what chracter had won
 * else; return a ' ' for tie
 */
char checkWinner(void);

/*
 * prints if there is a winner, unless tie
 */
void printWinner(char winner);

/*
 * hard ai
 */
int minimax(int depth, int isMaximizingPlayer);

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
    int x;
    int y;
    
    // seed by time
    srand(time(0));

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

// Function to find the best move for the computer player using Minimax
void hardComputerMove() {
    int bestMove = -1;
    int bestVal = -1000; // Initialize with a very small value

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                // Make the move
                board[i][j] = COMPUTER;

                // Calculate the evaluation score for this move using Minimax
                int moveVal = minimax(0, 0);

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
        int i = bestMove / 3;
        int j = bestMove % 3;
        board[i][j] = COMPUTER;
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

// Function to check if the current board configuration is terminal (game-over)
int isTerminal() {
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
int evaluate() {
    // Check for a winner
    char winner = checkWinner();
    if (winner == COMPUTER) {
        return 10; // Computer wins, assign a high score
    } else if (winner == PLAYER) {
        return -10; // Player wins, assign a low score
    }

    // If there's no winner, return a neutral score
    return 0;
}

// Minimax function
int minimax(int depth, int isMaximizingPlayer) {
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
                    int value = minimax(depth + 1, !isMaximizingPlayer);

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
                    int value = minimax(depth + 1, !isMaximizingPlayer);

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

int main(const int argc, const char *argv[]) {
  int s;
  int c;
  if (argc != 1) {
    printf("too many arguments to function.");
    return 0;
  }
  greet();
  COLORBLUE;

  while (1) {
    scanf_s("%d", &s);
    if (s == 1 || s == 2)
      break;
    else {
      int x = rand() % 2 + 1;
      if (x == 1) {
        CLEAR;
        printf("Bruh, only 1 or 2 lol.\n\a> ");
      }
      if (x == 2) {
        CLEAR;
        printf("Bruh. *sigh*\nchoose 1 or 2!\n\a> ");
      }
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }
  }
  if (s == 1) {
    char resp = ' ';

    do {

      int mode = getMode();
      char currentPlayer = 'X';  // Used for switching the letters
      char switchHumanBot = 'h'; // Used for switching between human & bot
      char winner = ' ';
      do {
        system("color f4");
        resp = ' ';
        winner = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0) {
          CLEAR;
          printBoard();

          if (mode == 1) {
            // Player vs player

            humanMove(currentPlayer);

            // Reverses the letter
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
          }

          else if (mode == 2) {
            // Player vs randComputer

            if (switchHumanBot == 'h') {
              humanMove('X');
              switchHumanBot = 'b';
            } else {
              computerMove();
              switchHumanBot = 'h';
            }
          }

          else if (mode == 3) {
            // Player vs hardComputer

            if (switchHumanBot == 'h') {
              humanMove('X');
              switchHumanBot = 'b';
            } else {
              hardComputerMove();
              switchHumanBot = 'h';
            }
          }

          winner = checkWinner();
          CLEAR;
          printBoard();
        }

        printWinner(winner);
      } while (winner == ' ' && resp == 'Y');

      typeString(text5);
      resp = _getch(); // experimenting with getch
      resp = toupper(resp);

    } while (resp == 'Y');

    CLEAR;
    typeString(text6);
    COLORBLUE;
  } else if (s == 2) {
    printRules();
  }

  return 0;
}
