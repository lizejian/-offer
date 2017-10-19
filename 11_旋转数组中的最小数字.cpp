'''
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
'''

//顺序查找，复杂度O(n)
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        //特殊情况
        if (len == 0)
            return 0;
        int i = 0;
        for (i = 0; i < len-1; i++)
        {
            if (rotateArray[i+1] < rotateArray[i])
                return rotateArray[i+1];
        }
        return rotateArray[0];
    }
};

//二分查找
class Solution {
public:
    int minNumberInRotateArray(vector<int> array) {
        int len = array.size();
        //特殊情况
        if (len == 0)
            return 0;
        int left = 0;
        int right = len - 1;
        int mid;
        //递增序列
        if (array[left] < array[right])
            return array[0];
        while(array[left] >= array[right] && right > left + 1)
        {
            mid = (left + right)/2;
            //三者值相等，顺序查找
            if (array[mid] == array[left] && 
                array[mid] == array[right])
            {
                int minNum = array[left];
                for (int i = left + 1; i <= right; i++)
                    if (minNum < array[i])
                        minNum = array[i];
                return minNum;
            }
            if (array[mid] > array[right])
                left = mid;
            else
                right = mid;
        }
        return array[right];
    }
};