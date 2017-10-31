//在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后
//都不能处于同一行、同一列或同一斜线上，问有多少种摆法。

//回溯
#include<string>
#include<iostream>
#include<vector>
using namespace std;

void printChessBoard(vector<vector<int>> chessboard);
bool check(vector<vector<int>> chessboard, int x, int y);
void eightQueenCore(vector<vector<int>> chessboard, int row);
int num = 0;

void eightQueenCore(vector<vector<int>> chessboard, int row)
{
	if (row == 8)
	{
		printChessBoard(chessboard);
		return;
	}
	for (int col = 0; col < 8; col++)
	{
		if (check(chessboard, row, col))
		{
			chessboard[row][col] = 1;
			eightQueenCore(chessboard, row+1);
			chessboard[row][col] = 0;
		}
	}
	return;
}
bool check(vector<vector<int>> chessboard, int x, int y)
{
	//check column
	for (int k = 0; k < x; k++)
		if (chessboard[k][y] == 1)
			return false;
	//check diagonal
	int i = x, j = y;
	while (i >= 0 && i < 8 && j >= 0 && j < 8)
	{
		if (chessboard[i][j] == 1)
			return false;
		i--;
		j--;
	}
	i = x;
	j = y;
	while (i >= 0 && i < 8 && j >= 0 && j < 8)
	{
		if (chessboard[i][j] == 1)
			return false;
		i--;
		j++;
	} 
	return true;
}
void printChessBoard(vector<vector<int>> chessboard)
{
	num++;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d ", chessboard[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", num);
}
int main()
{
	vector<vector<int>> chessboard(8, vector<int>(8, 0));
	eightQueenCore(chessboard, 0);
}


