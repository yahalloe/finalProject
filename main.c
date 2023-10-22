/*
 * TIC_TAC_TOE
 *  23 10.20
 * 
 * GitHub Repository: https://github.com/yahalloe/finalProject-.git
 *
 * main.c
 */

#ifndef __header_h
#include "header.h"
#endif

int main (void)
{   
    greet();
    int s;
    scanf("%d",&s);
    if (s == 1)
    {   
    char resp = ' ';
        do 
        {char winner = ' ';
            do 
            {
                system("color f4");
                resp = ' ';
                winner = ' ';
                resetBoard();

                while(winner == ' ' && checkFreeSpaces() != 0)
                {
                    CLEAR;
                    printBoard();

                    playerMove();
                    winner = checkWinner();
                    if (winner != ' ' || checkFreeSpaces() == 0) 
                    {break;}
    
                    computerMove();
                    winner = checkWinner();
                    if (winner != ' ' || checkFreeSpaces() == 0) 
                    {break;}
                }
                CLEAR;
                printBoard();
                printWinner(winner);
            
            } while (winner == ' ');
            printf("\n\t\t\t\t  restart?\n\t\t\t\t   (Y/N)\n");
            scanf(" %c",&resp);
            resp = toupper(resp);
        } while (resp == 'Y');
        CLEAR;
        typeString(text6);
    }
    else if (s == 2) {
        CLEAR;
        typeString(rule1);
        typeString(rule2);
        typeString(rule3);
        typeString(rule4);
    }
    else {
        CLEAR;
        typeString(text7);
        getchar();
    }
    return 0;
}
