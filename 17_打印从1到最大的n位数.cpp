#include <cstdio>
#include <cstdlib>


void PrintNum(int *number, int n);
bool Increment(int* number, int n);
void Print1ToMaxOfNDigits(int n)
{
	int* number = new int[n];
	for (int i = 0; i < n; i++)
		number[i] = 0;
	while (!Increment(number, n))
	{
		PrintNum(number, n);
	}
}
bool Increment(int* number, int n)
{
	bool isFull = true;
	for (int i = 0; i < n; i++)
		if (number[i] != 9)
			isFull = false;
	if (!isFull)
	{
		number[0]++;
		int idx = 0;
		while(number[idx] > 9)
		{
			number[idx+1]++;
			number[idx] = number[idx] - 10;
			idx++;
		}
	}
	return isFull;
}
void PrintNum(int *number, int n)
{
	int notZero = n - 1;
	while (number[notZero] == 0 && notZero >= 0)
    {
        notZero--;
    }
	for (int i = notZero; i >=0; i--)
		printf("%d ", number[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{
    Print1ToMaxOfNDigits(3);
    return 0;
}
