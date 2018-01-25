/*
 *在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。
 */
class Solution {
public:
    int FirstNotRepeatingChar(string str) 
    {
        if (str.empty())
            return -1;
        map<char, int> charCount;
        for (auto c : str)
        {
            ++charCount[c];
        }
        for (auto iter = str.cbegin(); iter < str.cend(); ++iter)
        {
            if (charCount[*iter] == 1)
                return iter - str.cbegin();
        }
        return -1;
    }
};
