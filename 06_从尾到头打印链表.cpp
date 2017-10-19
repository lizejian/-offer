# 堆栈
class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode* pHead) {
    	vector<int> value;
        std::stack<ListNode*> nodes;
        ListNode* pNode = pHead;
        while (pNode != nullptr)
        {
        	nodes.push(pNode);
        	pNode = pNode -> next;
        }
        while (!nodes.empty())
        {
        	pNode = nodes.top();
        	value.push_back(pNode->val);
        	nodes.pop();
        }
        return value;
    }
};

# 递归。要求直接print时，用递归比较好。但可能会层级过深，爆掉。
class Solution2 {
public:
	vector<int> value;
    vector<int> printListFromTailToHead(ListNode* pHead) {
    	if (pHead != nullptr){
            value = printListFromTailToHead(pHead->next);
        	value.push_back(pHead->val);
    	}
    	return value;
    }
};