/*
 * TIC_TAC_TOE
 *  23 10.20
 * 
 * GitHub Repository: https://github.com/yahalloe/finalProject-.git
 *
 * main.c
 */
#include "header.h"

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
            } while (winner == ' ' && resp == 'Y');     // fixed a bug on the first try: when Tie, it auto restart
            typeString(text5);
            scanf(" %c",&resp);
            resp = toupper(resp);
        } while (resp == 'Y');
        CLEAR;
        typeString(text6);
    }
    else if (s == 2) {
    printRules();
    }
    else {
        CLEAR;
        typeString(text7);
        getchar();
    }
    return 0;
}
