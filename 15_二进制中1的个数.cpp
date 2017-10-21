//增加n
int NumberOf1(int n)
{
	int count = 0;
	int mask = 1;
	while (mask <= n)
	{
		if (n & mask)
			count++;
		mask = mask << 1;	
	}
	return count;
}

// 数字减1 & 数字
int NumberOf1(int n)
{
	int count = 1;
	while (n)
	{
		count++;
		n = (n-1)&n;
	}
}
