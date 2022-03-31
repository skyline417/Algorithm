/*
题意：判断从根到叶子有没有和为目标值的路径
思路：dfs见代码，这题自己没写出来（关于何时调用自己 何时要重新写个dfs函数 我有点搞不清）
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        targetSum-=root->val;
        if(!root->left && !root->right) return targetSum==0;
        return root->left && hasPathSum(root->left, targetSum) || root->right && hasPathSum(root->right, targetSum);
    }
};