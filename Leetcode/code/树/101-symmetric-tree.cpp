/*
题意：判断二叉树是否对称
思路：递归对称位置，具体见代码。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode* l, TreeNode* r){
        if(!l && !r) return 1;
        if(l && r && l->val==r->val) return dfs(l->left, r->right) && dfs(l->right, r->left);
        return 0;
    }
};
/*
20220318 不会写
*/