//假设我们想在长度为n的字符串中求m个字符的组合。我们先从头扫描字符串的第一个字符。针对第一个字符，
//我们有两种选择：一是把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选取m-1个字符；
//而是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符。
vector<string> Combination(string str, int m)
{
	vector<string> array;
	string substr;
	if (str.size() < m)
		return array;
	CombinationCore(array, str, 0, m);
	sort(array.begin(), array.end());
	return array;
}
void CombinationCore(vector<string>& array, string str, string substr, int begin, int m)
{
	//凑齐m个字符
	if (m == 0)
	{
		array.push_back(substr);
		return;
	}
	//剩下的长度不够
	if (str.size()-begin < m)
		return;
	//不考虑当前字符
	CombinationCore(array, str, substr, begin+1, m);
	//考虑当前字符
	substr += str[begin];
	CombinationCore(array, str, substr, begin+1, m-1);
}