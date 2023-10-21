#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#if defined(_WIN32) || defined(__WIN32__)
#ifndef __windows_h
#include <windows.h>
#define CLEAR system("cls")
#define COLORBLUE system("color 09")
#endif
#else
#ifndef __termios_h
#include <termios.h>
#endif
#ifndef __unistd_h
#include <unistd.h>
#define CLEAR system("clear")   //tput reset
#define COLORBLUE COLOR(\033[34m)
#endif
#endif

/*
 *  function put out text 1 and so on in a type-writter like fashion
 */
void typeString(const char* text);

/*
 * resets the board after the move had inputed by the user
 */
void resetBoard();

/*
 * Prints the 2d board
 */
void printBoard();

/*
 * Checks whether there is no input on the coordinate on the board
 */
int checkFreeSpaces();

/*
 * funtion for the player's move
 */
void playerMove();

/*
 * funtion for the player's move
 */
void computerMove();

/*
 * checks all winning condition 
 */
char checkWinner();

/*
 * prints if there is a winner, unless tie
 */
void printWinner(char winner);
