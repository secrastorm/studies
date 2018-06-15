/*
	Queen : N-Queens Problem
	2018-06-15 Kim TaeHyeong

	<Description>
	N-N 2���� �迭�� ������ ��,
	 0 : �ƹ� �͵� ���� (Queen ��ġ ����)
	-1 : Queen ����
	+n : Queen�� ���� ����(n > 0), �� ���� Queen�� ���� ���������� ����
	�� �����Ͽ� ��������� Queen�� ��ġ�Ѵ�.

	N���� �����Ͽ� �׽�Ʈ�� �� �ִ�. (N < 14���� �׽�Ʈ�� ��)
 */

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#define N 10

int board[N][N];	// 2���� ü���� ����

bool matchQueen(int queen);			// ��������� Queen�� ��ġ
bool addQueen(int x, int y);		// Queen �߰�
bool removeQueen(int x, int y);		// Queen ����
void initBoard();
void printBoard();

void main()
{
	int q;		// Queen�� ����
	int i, j;	// Board�� x, y��

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
	if (board[x][y] != 0)	// Queen�� �ְų�, Queen�� ���� ������ �ִٸ�
	{
		return false;
	}
	else
	{
		for (int i = 0; i < N; i++)	// Queen�� ���� ������ ����
		{
			board[i][y]++;
			board[x][i]++;
			if ((x - i >= 0) && (y - i >= 0)) board[x - i][y - i]++;
			if ((x - i >= 0) && (y + i < N)) board[x - i][y + i]++;
			if ((x + i < N) && (y - i >= 0)) board[x + i][y - i]++;
			if ((x + i < N) && (y + i < N)) board[x + i][y + i]++;
		}
		board[x][y] = -1;	// Queen ��ġ ǥ��
	}
	return true;
}

bool removeQueen(int x, int y)
{
	if (board[x][y] != -1)	// Queen�� ���ٸ�
	{
		return false;
	}
	else
	{
		for (int i = 0; i < N; i++)	// Queen�� ���� ������ ����
		{
			board[i][y]--;
			board[x][i]--;
			if ((x - i >= 0) && (y - i >= 0)) board[x - i][y - i]--;
			if ((x - i >= 0) && (y + i < N)) board[x - i][y + i]--;
			if ((x + i < N) && (y - i >= 0)) board[x + i][y - i]--;
			if ((x + i < N) && (y + i < N)) board[x + i][y + i]--;
		}
		board[x][y] = 0;	// Queen ��ġ ����
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