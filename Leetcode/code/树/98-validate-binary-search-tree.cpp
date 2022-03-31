/*
题意：判断是否是二叉搜索树
思路：
    方法1：中序遍历 递增
    方法2：带着整棵树的范围递归
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
    long p=LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
        if(!isValidBST(root->left)) return 0;

        // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
        if(root->val <= p) return false;

        p=root->val; 
        return isValidBST(root->right);
    }

};


class Solution {
public:
    vector<int>v;

    bool isValidBST(TreeNode* root) {
        return dfs(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }

    bool dfs(TreeNode* root, long l, long r){
        if(!root) return 1;
        if( l >= root->val || root->val >= r ) return 0;
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    }

};