class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //特殊情况
        if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        
        //定义矩阵，判断是否用过
        bool *isUsed = new bool[rows*cols]();
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (hasPathCore(matrix, rows, cols, str, isUsed, i, j))
                    return true;
            }
        return false;
    }
    bool hasPathCore(char* matrix, int rows, int cols, char* str, bool* isUsed, int i, int j)
    {
        if (str[0] == '\0')
            return true;
        //边界条件
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return false;
        bool isExisted = false;
        if (matrix[i*cols + j] == str[0] && isUsed[i*cols + j] == false)
        {
            isUsed[i*cols + j] = true;
            isExisted = hasPathCore(matrix, rows, cols, str + 1, isUsed, i - 1, j) || 
                hasPathCore(matrix, rows, cols, str + 1, isUsed, i + 1, j) ||
                hasPathCore(matrix, rows, cols, str + 1, isUsed, i, j - 1) ||
                hasPathCore(matrix, rows, cols, str + 1, isUsed, i, j + 1);
            isUsed[i * cols + j] = false;
        }
        return isExisted;
    }
};
