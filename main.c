/*
 * TIC_TAC_TOE
 *  23 10.20
 *
 * GitHub Repository: https://github.com/yahalloe/finalProject-.git
 *
 * main.c
 */
#include "h.h"

int main(const int argc, const char *argv[]) {
  int s;
  int c;
  if (argc != 1) {
    printf("too many arguments to function: %s",*argv);
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
    int resp;

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
            system("color 75");
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
      COLORBLUE;
    } while (resp == 'Y');

    system("color f4");
    CLEAR;
    typeString(text6);
    COLORBLUE;
  } else if (s == 2) {
    printRules();
  }

  return 0;
}
