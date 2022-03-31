/*
题意：求二叉树的直径
思路：类似于求树的高度 在每个节点处求左右子树的高度l和r 取最大值max(l,r)+1作为该点的高度 
    遍历过程中同时记录该子树的直径(l+r) 最后返回直径里的最大值
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
    int maxn=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxL(root);
        return maxn;
    }
    int maxL(TreeNode* root){
        if(!root) return 0;
        int l=maxL(root->left), r=maxL(root->right);
        maxn=max(maxn,l+r);
        return max(l,r)+1;
    }
};