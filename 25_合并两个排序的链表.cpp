//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//递归方法
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	if (pHead1->val < pHead2->val)
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}
}

//非递归方法
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	ListNode* pMergeHead = nullptr;
	ListNode* pMergeTail = nullptr;
	while (pHead1 != nullptr && pHead2 != nullptr)
	{
		if (pHead1->val < pHead2->val)
		{
			if (pMergeHead == nullptr)
				pMergeHead = pHead1;
			else
				pMergeTail->next = pHead1;
			pMergeTail = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			if (pMergeHead == nullptr)
				pMergeHead = pHead2;
			else
				pMergeTail->next = pHead2;
			pMergeTail = pHead2;
			pHead2 = pHead2->next;		
		}
	}
	if (pHead1 == nullptr)
        pMergeTail->next = pHead2;
    if (pHead2 == nullptr)
        pMergeTail->next = pHead1;
	return pMergeHead;
}