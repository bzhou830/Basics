#include <iostream>
#include <stack>
#include "LinkList.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/***********************************************************************************************************************
 * 根据中序遍历的顺序，对于任一结点，优先访问其左孩子，而左孩子结点又可以看做一根结点，然后继续访问其左孩子结点，
 * 直到遇到左孩子结点为空的结点才进行访问，然后按相同的规则访问其右子树。因此其处理过程如下：
 *　对于任一结点P，
 *  1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前结点P再进行相同的处理；
 *  2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的P置为栈顶结点的右孩子；
 *  3)直到P为NULL并且栈为空则遍历结束。
***********************************************************************************************************************/
void inorder_NoRec(TreeNode *root) {
    stack<TreeNode *> sk;
    while (!sk.empty() || root != NULL) {
        while (root != NULL) {
            sk.push(root);
            root = root->left;
        }
        if (!sk.empty()) {
            root = sk.top();
            cout << root->val;
            sk.pop();
            root = root->right;
        }
    }
}


void inorder_Rec(TreeNode *root) {
    if (root != NULL) {
        inorder_Rec(root->left);
        cout << root->val;
        inorder_Rec(root->right);
    }
}


int main() {
    int a[5] = {1, 2, 3, 4, 5};
    ListNode* l = createSortedList(a, 5);
    printLinkList(l);
    ListNode* r = reverseLinkList(l);
    printLinkList(r);
    destoryLinkList(r);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}

