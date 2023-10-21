#pragma once
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

extern const char* text1;
extern const char* text2;
extern const char* text3;
extern const char* rule1;
extern const char* rule2;
extern const char* rule3;
extern const char* rule4;
extern const char* text7;
extern const char* text5;
extern const char* text6;
/*
 * for some reason, i need to declare these here even tho I didn't need to 
 * declare the char here. I'm not sure but it's probably due to the type. Otherwise,
 * if I didn't do this, I need to include library.c file on the main file.
 * 
 * update: 
 * I know the reason now. I need to declare it here but with extern. extern ensures
 * that the content of the intialization is somewhere in the files.
 */


//===============================================================================================
//                                        funtions
//===============================================================================================

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
