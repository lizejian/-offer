//在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后
//都不能处于同一行、同一列或同一斜线上，问有多少种摆法。

//排列
#include<iostream>
#include<vector>
using namespace std;
int num = 0;

void eightQueenCore(vector<vector<int>>& array, vector<int> number, int begin);
void eightQueen(vector<int> number);
bool check(vector<int> subarray);

void eightQueen(vector<int> number)
{
	vector<vector<int>> array;
	vector<int> subarray;
	eightQueenCore(array, number, 0);
}
void eightQueenCore(vector<vector<int>>& array, vector<int> number, int begin)
{
	if (begin == number.size())
	{
		if (check(number))
		{
			array.push_back(number);
			num++;
			printf("%d\n", num);
		}
		return;
	}
	eightQueenCore(array, number, begin+1);
	for (int i = begin+1; i < number.size(); i++)
	{
		swap(number[i], number[begin]);
		eightQueenCore(array, number, begin+1);
		swap(number[i], number[begin]);
	}
	
}
bool check(vector<int> subarray)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 8; j++)
		{
			if (j-i == subarray[j] - subarray[i] || j-i == subarray[i] - subarray[j])
				return false;
		}
	}
	return true;
}
int main()
{
	vector<int> number{0,1,2,3,4,5,6,7};
	eightQueen(number);
} 