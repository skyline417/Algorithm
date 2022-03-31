/*
题意：由前序遍历和中序遍历重构二叉树
思路：见代码！
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
    vector<int> preorder, inorder;
    map<int,int>mp;//无重复元素 可以用值来map下标

    TreeNode* buildTree(vector<int>& preorder_, vector<int>& inorder_) {
        preorder=preorder_, inorder=inorder_;
        for(int i=0;i<inorder.size();++i) mp[inorder[i]]=i; // 值 -> inorder 下标
        return dfs(0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* dfs(int pl, int pr, int il, int ir){
        if(pl>pr) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pl]);
        int k = mp[ preorder[pl] ]; //k=root->val;
        root->left = dfs(pl+1, pl+k-il, il, k-1);
        root->right = dfs(pl+k-il+1, pr, k+1, ir);
        return root;
    }
};