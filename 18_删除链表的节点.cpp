void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{	
	//该节点是头节点
	if (*pListHead == pToBeDeleted)
	{
		*pListHead->m_pNext = pToBeDeleted->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
	//该节点是尾节点
	else if (pToBeDeleted->m_pNext == nullptr)
	{
		ListNode* pNext = *pListHead;
		while (pNext->m_pNext == pToBeDeleted)
		{
			pNext = m_pNext->m_pNext;
		}
		pNext->m_pNext = nullptr;
		delete pNext;
		delete pToBeDeleted;
		pNext = nullptr;
		pToBeDeleted = nullptr;
	}
	//不是尾节点也不是头节点
	else 
	{
		ListNode* pNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNode->m_nValue;
		pToBeDeleted->m_pNext = pNode->m_pNext;
		delete pNode;
		pNode = nullptr;
	}
}