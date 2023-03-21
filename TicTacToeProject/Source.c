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

    
}
int main() {
    int player = 1;
    int row, col;
  


    for (int turn = 1; turn <= BOARD_SIZE * BOARD_SIZE; turn++) {
        displayTicTacToe();
        printf("please enter a location for the player 1 (0,0 / 2,1)");
        printf("Player %d's turn (enter row and column): ", player);
        scanf_s("%d %d", &row, &col);

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Wrong move, try again.\n");
            turn--;
            continue;
        }
        if (tictactoe[row][col] != ' ') {
            printf("That space is taken.\n");
            turn--;
            continue;
        }
        // Set the current player's x or o
        if (player == 1) {
            tictactoe[row][col] = 'X';
        }
        else {
            tictactoe[row][col] = 'O';
        }

        if (check_win(tictactoe[row][col])) {
            displayTicTacToe();
            printf("Player %d wins!\n", player);
            return 0;
        }
        player = (player % 2) + 1;
    }
    displayTicTacToe();
    printf("its tie");
    return 0;
}