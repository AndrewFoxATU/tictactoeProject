#include <stdio.h>
#define BOARD_SIZE 3


void displayTicTacToe();
int tictactoe[BOARD_SIZE][BOARD_SIZE];


void displayTicTacToe()
{

    printf("\n\t|\t|\n");
    printf("\t|\t|\n");
    printf("%c\t|%c\t|%c\n", tictactoe[0][0], tictactoe[0][1], tictactoe[0][2]);
    printf("--------|-------|--------\n");
    printf("\t|\t|\n");
    printf("%c\t|%c\t|%c\n", tictactoe[1][0], tictactoe[1][1], tictactoe[1][2]);
    printf("--------|-------|--------\n");
    printf("\t|\t|\n");
    printf("%c\t|%c\t|%c\n", tictactoe[2][0], tictactoe[2][1], tictactoe[2][2]);
    printf("\t|\t|\n");

}



// Function to check if a player has won
int check_win(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (tictactoe[i][0] == player && tictactoe[i][1] == player && tictactoe[i][2] == player) {
            return 1;
        }
    }



    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (tictactoe[0][j] == player && tictactoe[1][j] == player && tictactoe[2][j] == player) {
            return 1;
        }
    }



    // Check diagonals
    if (tictactoe[0][0] == player && tictactoe[1][1] == player && tictactoe[2][2] == player) {
        return 1;
    }
    if (tictactoe[0][2] == player && tictactoe[1][1] == player && tictactoe[2][0] == player) {
        return 1;
    }




int main() {





	displayTicTacToe();



}