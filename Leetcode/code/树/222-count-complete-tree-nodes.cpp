/*
题意：完全二叉树的节点个数
思路：（一）普通二叉树：递归左右两边 返回左子树节点数 和 右子树节点数。
（二）完全二叉树：有一种二分的做法，我没细看。以后来补。
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ans=1;
        if(root->left) {ans+=countNodes(root->left);}
        if(root->right) {ans+=countNodes(root->right);}
        return ans;
    }
};