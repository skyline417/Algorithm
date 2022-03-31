/*
题意：对称二叉树
思路：同101
*/
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