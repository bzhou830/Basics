/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
Seen this question in a real interview before?  YesNo
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* pRes = new ListNode(0);
        ListNode* p = pRes;
        int carry = 0;
        while(l1 || l2)
        {
            p->next = new ListNode(0);
            p = p->next;
            
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            
            p->val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            
            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }
        if(carry != 0)
        {
            p->next = new ListNode(carry);
        }
        return pRes->next;
    }
};