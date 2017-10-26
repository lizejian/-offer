#include<stdio.h>
#include<vector>

using namespace std;
vector<int> swap(vector<int> array, int i, int j);
void reOrderArray(vector<int> &array) 

    int len = array.size();
	int i = 0;
    while (i < len)
    {
      //找偶数
        if (array[i] % 2 == 0)
        {
            int j = i+1;
            //找奇数
            while (array[j] % 2 == 0 && j < len)
                j++;
            //如果找到奇数
            if (array[j] % 2 == 1)
            {
            	//倒着交换
                for (int idx = j; idx > i; idx--)
                 	array = swap(array, idx, idx-1);
            }
        }
        i++;
   }
}
vector<int> swap(vector<int> array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return array;
}
int main()
{
	vector<int> array{1,2,3,4,5,6,7};
	reOrderArray(array);
	return 0;
}
