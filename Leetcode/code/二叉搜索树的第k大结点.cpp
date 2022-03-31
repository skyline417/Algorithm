/*
题意：二叉搜索树的第k大节点
思路：右根左 遍历 这样能从大到小遍历 可以数到第k个
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
    int cnt=0,ans;
    int kthLargest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
    void dfs(TreeNode* root, int k){
        if(!root) return;
        dfs(root->right,k);
        ++cnt;
        if(cnt==k){
            ans=root->val;
            return;
        }
        dfs(root->left,k);
    }
};