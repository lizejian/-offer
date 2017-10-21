class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0)
            return 0;
        bool* visited = new bool[rows*cols]();
        return helper(threshold, rows, cols, visited, 0, 0);
    }
    int helper(int threshold, int rows, int cols, bool* visited, int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
        	return 0;
        if (digitSum(i) + digitSum(j) > threshold || visited[i*cols + j])
            return 0;
        visited[i*cols + j] = true;
        int num = 1 + helper(threshold, rows, cols, visited, i - 1, j) +
            helper(threshold, rows, cols, visited, i + 1, j) +
            helper(threshold, rows, cols, visited, i, j - 1) +
            helper(threshold, rows, cols, visited, i, j + 1);
        return num;
    }
    int digitSum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num = num /10;
        }
        return sum;
    }
};
