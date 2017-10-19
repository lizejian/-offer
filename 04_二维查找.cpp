#include <vector>
using std::vector;
class Solution {
public:
    bool Find(int target, vector<vector<int>> array)
    {
		int rowCount = array.size();
        int colCount = array[0].size();
        int i, j;
        for (i = 0, j = colCount - 1; i < rowCount && j >= 0;)
        {
            if (target == array[i][j])
            {
                return true;
            }
            if (target > array[i][j])
            {
                i++;
            }
            else 
            {
                j--;
            }
        }
        return false;
    }
};
