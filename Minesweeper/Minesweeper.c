#include "game.h"
#include <time.h>

void menu(void);
void game();


int main(void){
    int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("Make Your choice:>");
		scanf("%d", &input);
		switch (input){
			case 1:
				game();
				// printf("Minesweeper!");
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



void menu(void){

	printf("--------------------------------\n");
	printf("-----Welcome To Minesweeper-----\n");
	printf("--------------------------------\n");
	printf("-------     1.Play     ---------\n");
	printf("-------     0.Exit     ---------\n");
	printf("--------------------------------\n");
}

void game(){
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	Inite(mine,ROWS,COLS,'0');
	Inite(show,ROWS,COLS,'*');
	// DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);

	// set Mine
	SetMine(mine, ROW, COL);
	DisplayBoard(mine,ROW,COL);
	
	//Find Mine
	FindMine(mine, show, ROW, COL);
}
