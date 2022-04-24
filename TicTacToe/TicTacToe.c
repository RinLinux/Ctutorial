
#include "game.h"

void game(void);

int main(void){

	int input = 0;
	srand(( unsigned int )time(NULL));
	do{
		menu();
		printf("Make Your choice:>");
		scanf("%d", &input);
		switch (input){
			case 1:
				game();
				break;
			case 0:
				printf("Game Over..\n");
				break;
			default:
				printf("You made a wrong Choice, Try again\n");
				break;
		}

	}while(input);
	return 0;
}

void game(void){
	char status = 0;
	char board[ROW][COL];
	IniteBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while(1){
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		status =  judge(board, ROW, COL);
		if (status != 'C') {break;}
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		status =  judge(board, ROW, COL);
		if (status != 'C') {break;}
	}
	if (status == '*'){printf("Player WIN!\n");}
	else if (status == '#'){printf("Computer WIN!\n");}
	else{printf("Draw!\n");}	
}
