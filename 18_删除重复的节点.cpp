class Solution {
public:
    ListNode* deleteDuplication(ListNode** pHead)
    {
    	if (pHead == nullptr || pHead->next = nullptr)
    		return pHead;
    	ListNode* pNode = *pHead;
    	ListNode* pPreNode = nullptr;
    	while (pNode != nullptr)
    	{
    		ListNode* pNext = pNode->next;
    		if (pNode->val == pNext->val && pNext != nullptr)
    		{
    			int value = pNode->val;
    			while (pNext->val == value && pNext != nullptr)
    				pNext = pNext->next;
    			if (pPreNode == nullptr)
    				*pHead = pNext;
    			else
    				pPreNode->next = pNext; 
    		}
    		else
    		{
    			pPreNode = pNode;
    			pNode = pNext;
    		}
    	}
    }
};