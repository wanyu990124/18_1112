#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3
int g_board[ROW][COL];

int Menu() {
	printf("-----��������Ϸ-----\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//���̳�ʼ��
void Init() {
	srand((unsigned int)time(0));
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_board[row][col] = ' ';
		}
	}
}

//��ӡ����
void Printboard() {
	for (int row = 0; row < ROW; ++row) {
		printf("  %c | %c | %c  \n", g_board[row][0], g_board[row][1], g_board[row][2]);
		if (row != ROW - 1)
			printf(" ---|---|--- \n");
	}
}

//�������
void Playermove() {
	printf("���������!\n");
	int row, col;
	while (1) {
		printf("�������������(row col):");
		scanf("%d  %d", &row, &col);
		if (row < 0 || row > ROW || col < 0 || col > COL) {
			printf("���������Ƿ�,����������!\n");
			continue;
		}
		if (g_board[row-1][col-1] != ' ') {
			printf("��ǰλ���Ѿ�����������,����������!\n");
			continue;
		}
		g_board[row-1][col-1] = 'x';
		break;
	}
}

//��������
void Computermove() {
	printf("��������!\n");
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

//�ж�Ӯ��
char Checkwinner() {
	//�����,��,б���Ƿ���������
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
	//�жϺ���
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
		printf("��һ�ʤ!\n\n");
	}
	else if (winner == 'o') {
		Printboard();
		printf("���Ի�ʤ!\n\n");
	}
	else {
		Printboard();
		printf("����!\n\n");
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