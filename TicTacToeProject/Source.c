#include <stdio.h>
void displayTicTacToe();
int tictactoe[3][3];


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




int main() {





	displayTicTacToe();



}