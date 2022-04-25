#include "game.h"


void Inite(char board[ROWS][COLS],int rows,int cols,char set){
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            board[i][j] = set;
        } 
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col){
    int i = 0;
    int j = 0;
    printf("----------MineSweeper----------\n");
	for(i = 0; i <= row; i++){
		printf("%d ",i);
	}
	printf("\n");
    for (i = 1; i <= row; i++){	
		printf("%d ",i);
        for (j = 1; j <= col; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("----------MineSweeper----------\n");  
}

void SetMine(char board[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;
	while(count){
		x = rand() % row + 1;
		y = rand() % col + 1;
		if(board[x][y] == '0'){
			board[x][y] = '1';
			count--;
		}
	}
	
}

static int get_mine_count(char board[ROWS][COLS], int x, int y){
    return board[x-1][y-1] + board[x-1][y] + board[x-1][y+1] + 
            board[x][y-1] + board[x][y+1] +
            board[x+1][y-1] + board[x+1][y] + board[x+1][y+1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
	int x = 0;
	int y = 0;
    int win_count = 0;
	while(win_count < row * col - EASY_COUNT){
        printf("Please input:> ");
        scanf("%d %d", &x, &y);
        if(x >= 1 && y <= row && y >= 1 && y <= col){
            if(mine[x][y] == '1'){
                printf("Unfortunately, YOU FAILED! Good luck next time.\n");
                DisplayBoard(mine, row, col);
                break;
            }else{
                // number of mine around [x][y]
                int mine_count = get_mine_count(mine, x, y);
                show[x][y] = mine_count + '0';
                DisplayBoard(show, row, col);
                win_count++;	
            }
        
        }else{
            printf("Wrong input!");
        }
	}
    if(win_count == row * col - EASY_COUNT){
        printf("Congratulations, YOU WIN!\n");
        DisplayBoard(mine, row, col);	
    }    
}
// 优化：
// 1. 如果不是累，周围没有累，展开一片(函数递归)
// 2. 标记累