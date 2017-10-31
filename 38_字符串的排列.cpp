//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
//则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> array;
        if (str.size() == 0)
            return array;
        PermutationCore(array, str, 0);
        sort(array.begin(), array.end());
        return array;
    }
    void PermutationCore(vector<string>& array, string str, int begin)
    {
        if (begin == str.size()-1)
        {
            array.push_back(str);
            return;
        }
        PermutationCore(array, str, begin+1);
        for (int i = begin+1; i < str.size(); i++)
        {
            if (str[i] != str[begin])
            {
                swap(str[i], str[begin]);
                PermutationCore(array, str, begin+1);
                swap(str[i], str[begin]);
            }
        }
    }
};