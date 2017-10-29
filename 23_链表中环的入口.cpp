/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //特殊情况
		if (pHead == nullptr)
            return nullptr;
        //判断是否有环
        ListNode* pSlowNode = pHead->next;
        if (pSlowNode == nullptr)
            return nullptr;
        ListNode* pFastNode = pSlowNode->next;
        if (pFastNode == nullptr)
            return nullptr;
        while (pSlowNode != pFastNode)
        {
            pSlowNode = pSlowNode->next;
            pFastNode = pFastNode->next;
            if (pFastNode == nullptr)
                return nullptr;
            pFastNode = pFastNode->next;
            if (pFastNode == nullptr)
                return nullptr;
        }
        ListNode* meetingNode = pSlowNode;
        //判断环的节点数
        ListNode* pNode = meetingNode->next;
        int nodeNum = 1;
        while (pNode != meetingNode)
        {
            nodeNum++;
            pNode = pNode->next;
        }
        //找到环的入口处
        //节点1先移动nodeNum步
        pSlowNode = pHead;
        for (int i = 0; i < nodeNum; i++)
            pSlowNode = pSlowNode->next;
        //节点2
        pFastNode = pHead;
        while (pSlowNode != pFastNode)
        {
            pSlowNode = pSlowNode->next;
            pFastNode = pFastNode->next;
        }
        return pSlowNode;
    }
};