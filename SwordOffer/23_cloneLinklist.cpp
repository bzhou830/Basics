/*************************************************************************
	> File Name: 04_list_link.cpp
	> Author: Robin
	> Mail: chou_robin@163.com 
	> Created Time: 2016年06月19日 星期日 09时51分58秒
	> From: 剑指offer
 ************************************************************************/
#include <iostream>
#include <deque>
#include <stack>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
    ListNode* m_pSibling;
};


ListNode* construct()
{
    ListNode* pHead = new ListNode[5];
    for(int i=0; i<3; ++i)
    {
        pHead[i].m_nValue = i + 1;
        pHead[i].m_pNext = &pHead[i+1];
    }
    pHead[4].m_nValue = 5;
    pHead[4].m_pNext = NULL;
    pHead[4].m_pSibling = NULL;

    pHead[0].m_pSibling = &pHead[2];
    pHead[1].m_pSibling = &pHead[4];
    pHead[2].m_pSibling = NULL;
    pHead[3].m_pSibling = &pHead[1];

   return pHead;
}

void CloneNodes(ListNode* head)
{
    ListNode* pNode = head;
    while(pNode != NULL)
    {
        ListNode* clone = new ListNode;
        clone->m_nValue = pNode->m_nValue;
        clone->m_pNext = pNode->m_pNext;
        clone->m_pSibling = NULL;
        pNode->m_pNext = clone;
        pNode = clone->m_pNext;
    }
}

void Connectsibling(ListNode* head)
{
    ListNode* pNode = head;
    ListNode* pClone = NULL;
    while(pNode != NULL)
    {
        pClone = pNode->m_pNext;
        if(pNode->m_pSibling != NULL)
            pClone->m_pSibling = pNode->m_pSibling;
        pNode = pClone->m_pNext;
    }
}

ListNode* ReconnectNodes(ListNode* head)
{
    ListNode* pNode = head;
    ListNode* pCloneHead = NULL;
    ListNode* pClone = NULL;
    if(pNode != NULL)
    {
        pCloneHead = pClone = pNode->m_pNext;
        pNode->m_pNext = pClone->m_pNext;
        pNode = pNode->m_pNext;
    }
    while(pNode != NULL)
    {
        pClone->m_pNext = pNode->m_pNext;
        pClone = pClone->m_pNext;

        pNode->m_pNext = pClone->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pCloneHead;
}

int main()
{	
    ListNode *head = construct();
    CloneNodes(head);
    Connectsibling(head);
    ListNode *newlist = ReconnectNodes(head);

	return 0;
}






