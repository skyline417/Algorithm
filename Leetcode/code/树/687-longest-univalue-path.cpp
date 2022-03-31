/*
题意：
    由一个数组生成最大二叉树 最大值拎起来当跟 两边递归
思路：
    求每个节点的同值路径长max(l,r)+1 过程中记录最大值max(l+r,maxn) 类似于543二叉树的直径
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
    int longestUnivaluePath(TreeNode* root) {
        dfs(root); //同值路径长
        return maxn;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;

        int l=dfs(root->left), r=dfs(root->right); //每个结点都要求 同值路径 因为可能该结点不是最长
        
        //只合并同值的
        if(!root->left || root->left->val!=root->val) l=0;
        if(!root->right || root->right->val!=root->val) r=0;

        maxn=max(maxn,l+r);
        return max(l,r)+1;
    }
};

