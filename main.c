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
    //greet();
    COLORBLUE;
    int s;
    while (1) 
    {
        scanf("%d",&s);
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
            printf("Bruh. *sigh*\nchoice 1 or 2!\n\a> ");
            }
        int c;   
        while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }

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

                        // Reverse the letter
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                    } 

                    else if (mode == 2) {
                        // Player vs computer

                            if (switchHumanBot == 'h') {
                                humanMove('X');
                                switchHumanBot = 'b';
                            } else {
                                computerMove();
                                switchHumanBot = 'h';
                            }
                    }
                    // else if (mode == 3) {
                        // hard bot 
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

        } while (resp == 'Y');

        CLEAR;
        typeString(text6);
    }
    else if (s == 2) {
        printRules();
    }

    return 0;
}
