/*
   Dice6 : 주사위 6개를 던져 서로 다른 모든 숫자가 표시될 확률 계산
   2018-06-08 Kim TaeHyeong

   <Description>
   이 확률은 6! / (6^6) = 720 / 46,656 ≒ 1.5432% 이다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX_COUNT 1000000

typedef int dice;
typedef struct {
    dice dice1;
    dice dice2;
    dice dice3;
    dice dice4;
    dice dice5;
    dice dice6;
} DICE;

DICE throwDice();       // 주사위 던지기
bool checkDice(DICE d); // 숫자가 서로 다른지 체크

void main()
{
    int count_hit = 0;   // 주사위 던진 횟수, 다른 숫자 횟수
    DICE dices;

    srand(time(NULL));
    for (int i = 0; i < MAX_COUNT; i++)
    {
        dices = throwDice();
        if (checkDice(dices) == true)
            count_hit++;
    }

    printf("COUNT  %d\nHIT    %d\n\nRESULT %2.2f%%\n\n", MAX_COUNT, count_hit, (float)count_hit * 100.0 / (float)MAX_COUNT);
	system("pause");
}

DICE throwDice()
{
    DICE result;
    result.dice1 = rand() % 6 + 1;
    result.dice2 = rand() % 6 + 1;
    result.dice3 = rand() % 6 + 1;
    result.dice4 = rand() % 6 + 1;
    result.dice5 = rand() % 6 + 1;
    result.dice6 = rand() % 6 + 1;
	return result;
}

bool checkDice(DICE d)
{
	int dices[6];
	dices[0] = d.dice1;
	dices[1] = d.dice2;
	dices[2] = d.dice3;
	dices[3] = d.dice4;
	dices[4] = d.dice5;
	dices[5] = d.dice6;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dices[i] == dices[j])
				return false;
		}
	}
	return true;
}