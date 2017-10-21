//动态规划 空间0(n) 时间O(n^2)
int maxProductAfterCutting(int length)
{
	if (length < 1)
		return 0;
	if (length < 3)
		return 1;
	int* products = new int[length+1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 1;
	products[3] = 2;
	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i /2; j++)
		{
			if (products[j]*products[i-j] > max)
				max = products[j]*products[i-j];
		}
		products[i] = max;
	}
	return products[length];
}

//贪心算法 分成2或者3
int maxProductAfterCutting(int length)
{
	if (length < 1)
		return 0;
	if (length < 3)
		return 1;
	int timesOf3 = length/3;
	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;
	int timesOf2 = (length - timesOf3 * 3)/2;
	return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}
