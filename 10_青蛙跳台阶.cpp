class Solution {
public:
    int jumpFloor(int number) {
        //特殊情况
        if (number <= 0)
            return 0;
        if (number == 1)
        	return 1;
        if (number == 2)
            return 2;
        int firstItem = 1;
        int secondItem = 2;
        int result;
        for (int i = 3; i <= number; i++)
        {
            result = firstItem + secondItem;
            firstItem = secondItem;
            secondItem = result;
        }
        return result;
    }
};