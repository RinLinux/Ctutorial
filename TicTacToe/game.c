
#include "game.h"

void menu(void){

	printf("--------------------------------\n");
	printf("-----Welcome To Tic-Tac-Toe-----\n");
	printf("--------------------------------\n");
	printf("-------     1.Play     ---------\n");
	printf("-------     0.Exit     ---------\n");
	printf("--------------------------------\n");
}


void IniteBoard(char(* board)[COL], int row, int col){
	int i = 0;
	for(i = 0; i < row; i++){
		int j = 0;
		for (j = 0; j < col; j++){
			board[i][j] = ' ';
		}
		
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	for(i = 0; i < row; i++){
		int j = 0;
		for (j = 0; j < col; j++){
			printf(" %c ",board[i][j]);
			if ( j < col - 1){
				printf("|");
			}	
		}
		printf("\n");
		if(i < row - 1){
			for ( j = 0; j < col; j++){
				printf("---");
				if (j < col - 1){
					printf("|");
				}
			}
		}
		printf("\n");
	}
	
}


void player_move(char board[ROW][COL], int row, int col){
	printf("Player Move:\n");
	int x = 0; 
	int y = 0;
	while (1){
		printf("Please input your coordinate:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col){
			if(board[x-1][y-1] == ' '){
				board[x-1][y-1] = '*';
				break;
			}else{
				printf("Postion has been Occupied! Try another one!\n");
			}
		}else{
			printf("Incorrect Coordinates! Try another one!\n");
		}
	}	
}

// TODO: add some rules for computer to improve the difficulty
void computer_move(char board[ROW][COL], int row, int col){
	printf("Computer Move:\n");
	int x = 0; 
	int y = 0;
	while (1){
		x = rand() % row;
		y = rand() % col;
		if(board[x][y] == ' '){
			board[x][y] = '#';
			break;
		}
	}
	
}

static int is_full(char board[ROW][COL], int row, int col){
	int i = 0;
	for ( i = 0; i < row; i++){
		for ( int j = 0; j < col; j++){
			if(board[i][j] == ' '){
				return 0;
			}
		}
		
	}
	return 1;	
}

char judge(char board[ROW][COL], int row, int col){
	int i = 0;

	// ROW:
	for ( i = 0; i < row; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ' )
		return board[i][0];
	}

	// COL
	for ( i = 0; i < row; i++){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' )
		return board[0][i];
	}
	
	// diagonal
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
		return board[0][0];
	}
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '){
		return board[0][2];
	}

	if(is_full(board, row, col) == 1){
		return 'Q';
	}

	return 'C';
}