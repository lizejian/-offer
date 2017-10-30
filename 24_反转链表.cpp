// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。
ListNode* ReverseList(ListNode* pHead)
{
	//specical case
	if (pHead == nullptr)
		return nullptr;
	ListNode* pReverseHead;
	ListNode* pNode = pHead;
	ListNode* pPrev = nullptr;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->next;
		if (pNext == nullptr)
			pReverseHead = pNode;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

//***递归实现***
ListNode* ReverseList(ListNode* pHead)
{
	//specical case
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	ListNode* pReverseHead = ReverseList(pHead->next);
	head->next->next = head;
	head->next = nullptr;
	return pReverseHead;
}
