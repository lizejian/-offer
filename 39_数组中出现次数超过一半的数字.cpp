
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
//超过数组长度的一半，因此输出2。如果不存在则输出0。

//摩尔投票算法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int len = numbers.size();
        if (len == 0)
            return 0;
        int res;
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (count == 0)
            {
                res = numbers[i];
                count++;
            }
            else if (numbers[i] == res)
                count++;
            else
                count--;
        }
        count = 0;
        for (int i = 0; i < len; i++)
            if (numbers[i] == res)
                count++;
        return count > len/2? res : 0;
    }
};