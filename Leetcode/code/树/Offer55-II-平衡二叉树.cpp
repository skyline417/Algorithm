/*
题意：判断一棵二叉树是不是平衡二叉树（任意节点的左右子树的深度相差不超过1）
思路：depth求深度，（每个结点只会遍历一遍）。
    书上有个每个结点会遍历多次的写法，也不知道人在什么情况下会想到这种写法。
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
    int ans=true;
    bool isBalanced(TreeNode* root){
        depth(root);
        return ans;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        int l=depth(root->left), r=depth(root->right);
        if(abs(l-r) > 1) ans=false;
        return max(l,r)+1;
    }
};