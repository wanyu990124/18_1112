#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3
int g_board[ROW][COL];

int Menu() {
	printf("-----三子棋游戏-----\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//棋盘初始化
void Init() {
	srand((unsigned int)time(0));
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_board[row][col] = ' ';
		}
	}
}

//打印棋盘
void Printboard() {
	for (int row = 0; row < ROW; ++row) {
		printf("  %c | %c | %c  \n", g_board[row][0], g_board[row][1], g_board[row][2]);
		if (row != ROW - 1)
			printf(" ---|---|--- \n");
	}
}

//玩家落子
void Playermove() {
	printf("请玩家落子!\n");
	int row, col;
	while (1) {
		printf("请玩家输入坐标(row col):");
		scanf("%d  %d", &row, &col);
		if (row < 0 || row > ROW || col < 0 || col > COL) {
			printf("输入的坐标非法,请重新输入!\n");
			continue;
		}
		if (g_board[row-1][col-1] != ' ') {
			printf("当前位置已经有其他棋子,请重新输入!\n");
			continue;
		}
		g_board[row-1][col-1] = 'x';
		break;
	}
}

//电脑落子
void Computermove() {
	printf("电脑落子!\n");
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_board[row][col] != ' ') {
			continue;
		}
		g_board[row][col] = 'o';
		break;
	}
}

//判断赢家
char Checkwinner() {
	//检查行,列,斜线是否连成三个
	for (int row = 0; row < ROW; ++row) {
		if (g_board[row][0] == g_board[row][1] && g_board[row][0] == g_board[row][2] && g_board[row][0] != ' ') {
			return g_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col) {
		if (g_board[0][col] == g_board[1][col] && g_board[0][col] == g_board[2][col] && g_board[0][col] != ' ') {
			return g_board[0][col];
		}
	}
	if (g_board[0][0] == g_board[1][1] && g_board[0][0] == g_board[2][2] && g_board[0][0] != ' ') {
		return g_board[0][0];
	}
	if (g_board[2][0] == g_board[1][1] && g_board[2][0] == g_board[0][2] && g_board[2][0] != ' ') {
		return g_board[2][0];
	}
	//判断和棋
	int winner;
	if (g_board[0][0] != ' ' && g_board[0][1] != ' ' && g_board[0][2] != ' ' && g_board[1][0] != ' ' 
		&& g_board[1][1] != ' ' && g_board[1][2] != ' ' && g_board[2][0] != ' ' && g_board[2][1] != ' ' 
		&& g_board[2][2] != ' ') {
		return winner = 1;
	}
	return ' ';
}

void Game() {
	char winner;
	Init();
	while (1) {
		Printboard();
		Playermove();
		winner = Checkwinner();
		if (winner != ' ') {
			break;
		}
		Computermove();
		winner = Checkwinner();
		if (winner != ' ') {
			break;
		}
	}
	if (winner == 'x') {
		Printboard();
		printf("玩家获胜!\n\n");
	}
	else if (winner == 'o') {
		Printboard();
		printf("电脑获胜!\n\n");
	}
	else {
		Printboard();
		printf("和棋!\n\n");
	}
}

int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else {
			printf("Goodbye!\n");
			break;
		}
	}
	system("pause");
	return 0;
}