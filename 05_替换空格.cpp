class Solution {
public:
	void replaceSpace(char *str,int totalLength) {
        if (str == nullptr && totalLength <= 0)
            return;
        
        int spaceNumber = 0;
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
                spaceNumber++;
            i++;
        }
        int oldLength = i;
        int newLength = oldLength + 2*spaceNumber;
        
        if (newLength > totalLength)
            return;
        
        int oldIndex = oldLength;
        int newIndex = newLength;
        while (oldIndex >= 0 && newIndex > oldIndex)
        {
            if (str[oldIndex] != ' ')
            {
                str[newIndex] = str[oldIndex];
                newIndex--;
            }
            else
            {
                str[newIndex] = '0';
                str[newIndex-1] = '2';
                str[newIndex-2] = '%';
                newIndex -= 3;
            }
            oldIndex--;
        }
	}
};