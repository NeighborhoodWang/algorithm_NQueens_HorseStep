#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <cmath>

#define N 4

using namespace std;

int triedPosi[N * N][2];
int historyPosi[N][N];
char board[N][N] = {'s', '0', '\0', '\0',
					'@', '0', '\0', '\0',
					'\0', '\0', '\0', '\0',
					'\0', '\0', '\0', 'e'};
int xs = 0, ys = 0, xe = 0, ye = 0;


void initBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 's')
			{
				xs = i;
				ys = j;
			}
			else if (board[i][j] == 'e')
			{
				xe = i;
				ye = j;
			}
		}
	}
}

void initBoardVar()
{
	for (int i = 0; i < N * N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			triedPosi[i][j] = -1;
		}
	}



	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			historyPosi[i][j] = -1;
		}
	}
}

void initLegalMovs(int legalMovs[N * N][2])
{
	for (int i = 0; i < N * N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			legalMovs[i][j] = -1;
		}
	}
}

void clearLegalMovs(int legalMovs[N * N][2])
{
	for (int i = 0; i < N * N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			legalMovs[i][j] = -1;
		}
	}
}

void printBoard()
{
	static int count = 0;
	count++;
	printf("case %d \n", count);
	int tempBoard[N][N] = {0};
	int k = 0;
	char start = 's';
	char stone = '@';
	char end = 'e';
	while (triedPosi[k][0] != -1)
	{
		tempBoard[triedPosi[k][0]][triedPosi[k][1]] = k + 1;
		k++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '@')
			{
				tempBoard[i][j] = -2;
			}
		}
	}


	tempBoard[xs][ys] = 0;
	for (int i = 0; i < N; i++)
	{
	     for (int j = 0; j < N; j++)
	     {
	    	 if ((i == xs) && (j == ys))
	    	 {
	    		 printf("%-3c", start);
	    	 }
	    	 else if ((i == xe) && (j == ye))
	    	 {
	    	 	 printf("%-3c", end);
	    	 }
	    	 else if (tempBoard[i][j] == -2)
	    	 {
	    		 printf("%-3c", stone);
	    	 }
	    	 else
	    	 {
	    		 printf("%-3d", tempBoard[i][j]);
	    	 }
	     }
	     cout << endl;
	 }
	 cout << endl;
}

void getLegalMoves(const int x, const int y, int legalMovs[N * N][2])
{
	if ((x - 1 >= 0) && (board[x - 1][y] != '@'))
	{
		if ((x - 2 >= 0) && (y - 1 >= 0))
		{
			if (board[x - 2][y - 1] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x - 2;
				legalMovs[k][1] = y - 1;
			}
		}
		if ((x - 2 >= 0) && (y + 1 < N))
		{
			if (board[x - 2][y + 1] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x - 2;
				legalMovs[k][1] = y + 1;
			}
		}
	}
	if ((x + 1 < N) && (board[x + 1][y] != '@'))
	{
		if ((x + 2 < N) && (y - 1 >= 0))
		{
			if (board[x + 2][y - 1] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x + 2;
				legalMovs[k][1] = y - 1;
			}
		}
		if ((x + 2 < N) && (y + 1 < N))
		{
			if (board[x + 2][y + 1] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x + 2;
				legalMovs[k][1] = y + 1;
			}
		}
	}
	if ((y - 1 >= 0) && (board[x][y - 1] != '@'))
	{
		if ((x - 1 >= 0) && (y - 2 >= 0))
		{
			if (board[x - 1][y - 2] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x - 1;
				legalMovs[k][1] = y - 2;
			}
		}
		if ((x + 1 < N) && (y - 2 >= 0))
		{
			if (board[x + 1][y - 2] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x + 1;
				legalMovs[k][1] = y - 2;
			}
		}
	}
	if ((y + 1 < N) && (board[x][y + 1] != '@'))
	{
		if ((x - 1 >= 0) && (y + 2 < N))
		{
			if (board[x - 1][y + 2] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x - 1;
				legalMovs[k][1] = y + 2;
			}
		}
		if ((x + 1 < N) && (y + 2 < N))
		{
			if (board[x + 1][y + 2] != '@')
			{
				int k = 0;
				while (legalMovs[k][0] != -1)
				{
					k++;
				}
				legalMovs[k][0] = x + 1;
				legalMovs[k][1] = y + 2;
			}
		}
	}
}

void addPosTotriedposi(const int x, const int y)
{
	int k = 0;
	while (triedPosi[k][0] != -1)
	{
		k++;
	}
	triedPosi[k][0] = x;
	triedPosi[k][1] = y;
}

void removeLastPosTriedposi()
{
	int k = 0;
	while (triedPosi[k][0] != -1)
	{
		k++;
	}
	triedPosi[k - 1][0] = -1;
	triedPosi[k - 1][1] = -1;
}

void horseStep(const int x, const int y)
{
	int legalMovs[N * N][2];
	initLegalMovs(legalMovs);
	if (historyPosi[x][y] != -1)
	{
		return;
	}
	if ((x == xe) && (y == ye))
	{
		printBoard();
		return;
	}
	getLegalMoves(x, y, legalMovs);
	int k = 0;
	while (legalMovs[k][0] != -1)
	{
		addPosTotriedposi(legalMovs[k][0], legalMovs[k][1]);
		historyPosi[x][y] = 1;
		horseStep(legalMovs[k][0], legalMovs[k][1]);
		removeLastPosTriedposi();
		historyPosi[x][y] = -1;
		k++;
	}
	return;
}

int main()
{
	initBoard();
	initBoardVar();
	horseStep(xs, ys);
	return 0;
}
