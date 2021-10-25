//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学 
// 👍 4670 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = new List(0);
        ListNode* head = l;
        int carry = 0;
        while(l1 || l2){
            l->next = new ListNode(carry);
            if (l1) {
                l->next->val += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                l->next->val += l2->val;
                l2 = l2->next;
            }

            if (l->next->val >= 10) {
                carry = 1;
                l->next->val = l->next->val % 10;
            }
            l = l->next;
        }
        head = l->next;
        delete l;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
