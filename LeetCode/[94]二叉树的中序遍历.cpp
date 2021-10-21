//给定一个二叉树，返回它的中序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表 
// 👍 596 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
		inorder(root);
		return res;
    }
	
	void inorder(TreeNode* root){
		if(root->left)
			inorder(root->left);
		res.push_back(root->val);
		if(root->right)
			inorder(root->right);
	}
	
};
//leetcode submit region end(Prohibit modification and deletion)
