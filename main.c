#include "header.h"

int main (void)
{   
    COLORBLUE;
    CLEAR;
    typeString(text1);
    Sleep(1000);
    CLEAR;
    typeString(text2);
    Sleep(1000);
    CLEAR;
    typeString(text3);

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
                    if (winner != ' ' || checkFreeSpaces() == 0) {break;}
    
                    computerMove();
                    winner = checkWinner();
                    if (winner != ' ' || checkFreeSpaces() == 0) {break;}
                }
                CLEAR;
                printBoard();
                printWinner(winner);
            
            } while (winner == ' ');
            printf("\nrestart? (Y/N)");
            scanf(" %c",&resp);
            resp = toupper(resp);
        } while (resp == 'Y');
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
