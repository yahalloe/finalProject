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
    printf("too many arguments to function: %s",argv[1]);
    return 0;
  } else if (argc > 2) {
    printf("too many arguments to function: %s",argv[1]);
  } //else
  greet();
  COLORBLUE;

  while (1) {
    scanf_s("%d", &s);
    if (s == 1 || s == 2) {
      break; }
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
      while ((c = getchar()) != '\n' && c != EOF) {}
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

          switch (mode) {
            case 1:
              // Player vs player

              humanMove(currentPlayer);

              // Reverses the letter
              currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            break;

            case 2: 
              // Player vs randComputer

              if (switchHumanBot == 'h') {
                humanMove('X');
                switchHumanBot = 'b';
              } else {
                computerMove(mode);
                switchHumanBot = 'h';
              }
            break;

            case 3: 
              // Player vs hardComputer
              system("color 75");
              if (switchHumanBot == 'h') {
                humanMove('X');
                switchHumanBot = 'b';
              } else {
                hardComputerMove();
                switchHumanBot = 'h';
              }
            break;
          }
          winner = checkWinner();
          CLEAR;
          printBoard();
        }

        printWinner(winner, mode);
      } while (winner == ' ' && resp == 'Y');

      do {      
          CLEAR;
          printBoard ();
          printWinner(winner, mode);
          typeString(text5);
          resp = _getch(); // experimenting with getch
          resp = toupper(resp);
          if (resp == 'Y' || resp == 'N') {
            break;
          }
      }while  (resp != 'Y' && resp != 'N'); 
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
