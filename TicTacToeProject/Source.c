#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define BOARD_SIZE 3




void displayTicTacToe();
int check_win(char symbol);
int playAgainstPerson();
int playAgainstAI();
void makeRandomMove(char symbol);



char tictactoe[BOARD_SIZE][BOARD_SIZE] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main() {
    int choice;
    printf("Select an option:\n");
    printf("1. Play against another person\n");
    printf("2. Play against a random move AI\n");
    printf("Enter your choice: ");
    scanf_s("%d", &choice);



    if (choice == 1) {
        playAgainstPerson();
    }
    else if (choice == 2) {
        playAgainstAI();
    }
    else {
        printf("Invalid choice\n");
    }



    return 0;
}




void displayTicTacToe() // tictactoe board
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
int check_win(char symbol) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (tictactoe[i][0] == symbol && tictactoe[i][1] == symbol && tictactoe[i][2] == symbol) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (tictactoe[0][j] == symbol && tictactoe[1][j] == symbol && tictactoe[2][j] == symbol) {
            return 1;
        }
    }
    // Check diagonals
    if (tictactoe[0][0] == symbol && tictactoe[1][1] == symbol && tictactoe[2][2] == symbol) {
        return 1; // top right to bottom left
    }
    if (tictactoe[0][2] == symbol && tictactoe[1][1] == symbol && tictactoe[2][0] == symbol) {
        return 1; // top left to bottom right
    }
    return 0;
}
int playAgainstPerson() {
    int player = 1;
    int row, col;
    for (int turn = 1; turn <= BOARD_SIZE * BOARD_SIZE; turn++) {
        displayTicTacToe();
        printf("Player %d's turn (enter row and column): ", player);
        scanf_s("%d %d", &row, &col);
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Wrong move, try again.\n");
            turn--;
            continue;
        }
        if (tictactoe[row][col] != ' ') { // if the space is not blank
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
        int winner = check_win((player == 1) ? 'X' : 'O');
        if (winner) {
            displayTicTacToe();
            printf("Player %d wins!\n", player);
            return player;
        }
        // Switch players
        player = (player == 1) ? 2 : 1;
    }
    displayTicTacToe();
    printf("It's a tie!\n");
    return 0;
}
int playAgainstAI() {
    int player = 1;
    char symbol_player = 'X';
    char symbol_ai = 'O';
    srand(time(NULL));



    for (int turn = 1; turn <= BOARD_SIZE * BOARD_SIZE; turn++) {
        displayTicTacToe();
        if (player == 1) {
            printf("Player %d's turn (enter row and column): ", player);
            int row, col;
            scanf_s("%d %d", &row, &col);
            if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
                printf("Wrong move, try again.\n");
                turn--;
                continue;
            }
            if (tictactoe[row][col] != ' ') { // if the space is not blank
                printf("That space is taken.\n");
                turn--;
                continue;
            }
            tictactoe[row][col] = symbol_player;
        }
        else {
            printf("AI's turn:\n");
            makeRandomMove(symbol_ai);
        }



        if (check_win(player == 1 ? symbol_player : symbol_ai)) {
            displayTicTacToe();
            printf("%s wins!\n", player == 1 ? "Player" : "AI");
            return 0;
        }
        player = (player % 2) + 1;
    }



    displayTicTacToe();
    printf("It's a tie.\n");
    return 0;
}



void makeRandomMove(char symbol) { // ramdom ai move
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (tictactoe[row][col] != ' ');
    tictactoe[row][col] = symbol;
}