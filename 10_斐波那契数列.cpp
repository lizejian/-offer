class Solution {
public:
    int Fibonacci(int n) {
        //特殊情况
        if (n == 0)
            return 0;
        //n = 1, 2
		if (n < 3)
            return 1;
        int firstItem;
        int secondItem = 1;
        int result = 1;
        for (int i = 3; i <= n; i++)
        {
            firstItem = secondItem;
            secondItem = result;
            result = firstItem + secondItem;
        }
        return result;
    }
};
