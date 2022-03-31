/*
题意：二叉树的镜像
思路：遍历的时候 每次交换左右子树 注意对比28对称二叉树
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
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        //if(!root->left && !root->right) return;
        swap(root->left, root->right);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
        return; 
    }
};