// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //特殊情况
        if (pListHead == nullptr || k == 0)
            return nullptr;
        ListNode* pNode1 = pListHead;
        //找到第k个节点
        for (unsigned int i = 0; i < k-1; i++)
        {
            if (pNode1->next != nullptr)
                pNode1 = pNode1->next;
            else
                return nullptr;
        }
        ListNode* pNode2 = pListHead;
        while (pNode1->next != nullptr)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode2;
    }
};