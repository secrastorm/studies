/*
	Queen : N-Queens Problem
	2018-06-15 Kim TaeHyeong

	<Description>
	N-N 2차원 배열을 선언한 후,
	 0 : 아무 것도 없음 (Queen 배치 가능)
	-1 : Queen 있음
	+n : Queen의 공격 범위(n > 0), 몇 명의 Queen이 공격 가능한지를 뜻함
	로 지정하여 재귀적으로 Queen을 배치한다.

	N값을 조절하여 테스트할 수 있다. (N < 14에서 테스트할 것)
 */

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#define N 10

int board[N][N];	// 2차원 체스판 선언

bool matchQueen(int queen);			// 재귀적으로 Queen을 배치
bool addQueen(int x, int y);		// Queen 추가
bool removeQueen(int x, int y);		// Queen 제거
void initBoard();
void printBoard();

void main()
{
	int q;		// Queen의 갯수
	int i, j;	// Board의 x, y값

	initBoard();
	matchQueen(0);
	printBoard();
	system("pause");
}

bool matchQueen(int queen)
{
	if (queen == N)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (addQueen(i, j) == true)
				{
					if (matchQueen(++queen) == false)
					{
						removeQueen(i, j);
						queen--;
					}
					else
					{
						return true;
					}
				}
			}
		}
		return false;
	}
}

bool addQueen(int x, int y)
{
	if (board[x][y] != 0)	// Queen이 있거나, Queen의 공격 범위에 있다면
	{
		return false;
	}
	else
	{
		for (int i = 0; i < N; i++)	// Queen의 공격 범위값 증가
		{
			board[i][y]++;
			board[x][i]++;
			if ((x - i >= 0) && (y - i >= 0)) board[x - i][y - i]++;
			if ((x - i >= 0) && (y + i < N)) board[x - i][y + i]++;
			if ((x + i < N) && (y - i >= 0)) board[x + i][y - i]++;
			if ((x + i < N) && (y + i < N)) board[x + i][y + i]++;
		}
		board[x][y] = -1;	// Queen 위치 표시
	}
	return true;
}

bool removeQueen(int x, int y)
{
	if (board[x][y] != -1)	// Queen이 없다면
	{
		return false;
	}
	else
	{
		for (int i = 0; i < N; i++)	// Queen의 공격 범위값 감소
		{
			board[i][y]--;
			board[x][i]--;
			if ((x - i >= 0) && (y - i >= 0)) board[x - i][y - i]--;
			if ((x - i >= 0) && (y + i < N)) board[x - i][y + i]--;
			if ((x + i < N) && (y - i >= 0)) board[x + i][y - i]--;
			if ((x + i < N) && (y + i < N)) board[x + i][y + i]--;
		}
		board[x][y] = 0;	// Queen 위치 제거
	}
}

void initBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}
}

void printBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%2d ", board[i][j]);
		}
		printf("\n");
	}
}