#include <iostream>
#include <conio.h>

using namespace std;

#define WIDTH 19
#define HEIGHT 19

#define BLANK 0
#define WHITE 1
#define BLACK 2

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

#define PLAYER_BLACK 1
#define PLAYER_WHITE -1 

void drawBoard(int board[][HEIGHT], int x, int y);
bool isWin(int board[][HEIGHT], int player);

int main()
{
	int board[HEIGHT][WIDTH];
	int y = HEIGHT / 2, x = WIDTH / 2;

	int player = BLACK;

	char input = 0;
	int turnCount = 1;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			board[i][j] = BLANK;
	}

	drawBoard(board, x, y);

	while (true)
	{
		char ch = _getch();
		system("cls");

		if (ch == UP)
		{
			y--;

			if (y == -1)
				y = HEIGHT - 1;
		}

		else if (ch == DOWN)
		{
			y++;

			if (y == HEIGHT)
				y = 0;
		}
		else if (ch == LEFT)
		{
			x--;

			if (x == -1)
				x = WIDTH - 1;
		}

		else if (ch == RIGHT)
		{
			x++;

			if (x == WIDTH)
				x = 0;
		}
		else if (ch == SPACE)
		{
			turnCount++;

			if (board[y][x] == BLANK)
				board[y][x] = player;
			else
			{
				cout << "이미 돌이 존재합니다.." << endl;
				continue;
			}

		}

		drawBoard(board, x, y);

		cout << "Turn : " << turnCount;

		if (player == BLACK)
			cout << "(흑)";

		else if (player == WHITE)
			cout << "(백)";


		if (isWin(board, player))
		{
			cout << endl << endl;

			if (player == BLACK)
			{
				cout << "흑의 승리~!!" << endl;
			}
			else if (player == WHITE)
			{
				cout << "백의 승리~!!" << endl;
			}
			break;
		}

		if (player == BLACK)
			player = WHITE;
		else
			player = BLACK;
	}


	system("pause");
	return 0;
}

void drawBoard(int board[][HEIGHT], int x, int y)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{

			if (i == y && j == x)
				cout << "☆";

			else if (board[i][j] == BLACK)
				cout << "○";

			else if (board[i][j] == WHITE)
				cout << "●";

			else if (board[i][j] == BLANK)
			{
				if (i == 0 && j == 0)
					cout << "┌";

				else if (i == HEIGHT - 1 && j == 0)
					cout << "└";

				else if (i == 0 && j == WIDTH - 1)
					cout << "┐";

				else if (i == HEIGHT - 1 && j == WIDTH - 1)
					cout << "┘";

				else if (i == 0)
					cout << "┬";

				else if (i == HEIGHT - 1)
					cout << "┴";

				else if (j == 0)
					cout << "├";

				else if (j == WIDTH - 1)
					cout << "┤";

				else
					cout << "┼";
			}
		}
		cout << endl;

	}
}

bool isWin(int board[][HEIGHT], int player) // 넘오래걸리는데 게에바임
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			// 가로(→) 방향 체크,
			if (board[y][x] == player && board[y][x + 1] == player &&
				board[y][x + 2] == player && board[y][x + 3] == player &&
				board[y][x + 4] == player)
				return true;

			// 세로(↓) 방향 체크,
			else if (board[y][x] == player && board[y + 1][x] == player &&
				board[y + 2][x] == player && board[y + 3][x] == player &&
				board[y + 4][x] == player)
				return true;

			// 대각선(↘) 방향 체크,
			else if (board[y][x] == player && board[y + 1][x + 1] == player &&
				board[y + 2][x + 2] == player && board[y + 3][x + 3] == player &&
				board[y + 4][x + 4] == player)
				return true;

			// 대각선(↙) 방향 체크,
			else if (board[y][x] == player && board[y + 1][x - 1] == player &&
				board[y + 2][x - 2] == player && board[y + 3][x - 3] == player &&
				board[y + 4][x - 4] == player)
				return true;
		}
	}
	return false;
}
















