#include <stdio.h>

int main (void) {
    
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } 
    else {
    currentPlayer = 'X';
    }
}

=>    currentPlayer == 'X' ? currentPlayer = 'O' : currentPlayer = 'X';