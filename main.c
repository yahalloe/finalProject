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
    COLORBLUE;
    int s;
    scanf("%d",&s);
    if (s == 1)
    {   
        char resp = ' ';

        do {

            int mode = getMode();

            char winner = ' ';
            do {
                system("color f4");
                resp = ' ';
                winner = ' ';

                // Used for switching the letters
                char currentPlayer = 'X';

                // Used for switching between human & bot
                char switchHumanBot = 'h';

                resetBoard();

                while(winner == ' ' && checkFreeSpaces() != 0)
                {
                    CLEAR;
                    printBoard();

                    if (mode == 1) {
                        // Player vs player

                        humanMove(currentPlayer);

                        // Reverse letter
                        if (currentPlayer == 'X') {
                            currentPlayer = 'O';
                        } else {
                            currentPlayer = 'X';
                        }

                    } else if (mode == 2) {
                        // Player vs computer
                        
                        if (switchHumanBot == 'h') {
                            humanMove('X');
                            switchHumanBot = 'b';
                        } else {
                            computerMove();
                            switchHumanBot = 'h';
                        }

                    }

                    winner = checkWinner();
                    CLEAR;
                    printBoard();
                }

                printWinner(winner);
            } 
            while (winner == ' ' && resp == 'Y');

            typeString(text5);
            scanf(" %c",&resp);
            resp = toupper(resp);

        } 
        while (resp == 'Y');

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
    COLORBLUE;
    return 0;
}
