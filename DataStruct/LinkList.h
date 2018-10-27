//
// Created by BineanZhou on 2018/10/26.
//

#ifndef ALGOLEARN_LINKLIST_H
#define ALGOLEARN_LINKLIST_H

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


/***********************************************************************************************************************
 * 根据输入的数组创建链表
***********************************************************************************************************************/
ListNode *createLinkList(int a[], int n) {
    if (n == 0)
        return NULL;
    ListNode *pHead = new ListNode(a[0]);
    ListNode *p = pHead;
    for (int i = 1; i < n; ++i) {
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    return pHead;
}

/***********************************************************************************************************************
 * 链表的销毁
***********************************************************************************************************************/
void *destoryLinkList(ListNode *root) {
    while (root) {
        ListNode *pDel = root;
        root = root->next;

        delete pDel;
        pDel = NULL;
    }
}


/***********************************************************************************************************************
 * 链表的反转
***********************************************************************************************************************/
ListNode *reverseLinkList(ListNode *root) {
    ListNode *cur = root;
    ListNode *pre = NULL;
    while (cur != NULL) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}


/***********************************************************************************************************************
 * 链表的打印
***********************************************************************************************************************/
void printLinkList(ListNode *root) {
    while (root) {
        std::cout << root->val << "->";
        root = root->next;
    }
    std::cout << "NULL" << std::endl;
}


/***********************************************************************************************************************
 * 创建排序链表
***********************************************************************************************************************/
ListNode *createSortedList(int arr[], int n) {
    if (n == 0)
        return NULL;
    // 因为插入的节点很可能是头节点，所以使用一个空的头节点来方便操作
    ListNode *pDummyHead = new ListNode(0);
    pDummyHead->next = new ListNode(arr[0]);
    for (int i = 1; i < n; ++i) {
        ListNode *cur = pDummyHead;
        while (cur->next != NULL && cur->next->val <= arr[i]) {
            cur = cur->next;
        }
        ListNode *n = new ListNode(arr[i]);
        n->next = cur->next;
        cur->next = n;
    }
    ListNode *res = pDummyHead->next;
    delete pDummyHead;
    return res;
}

#endif //ALGOLEARN_LINKLIST_H
