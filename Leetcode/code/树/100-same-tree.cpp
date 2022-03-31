/*
题意：判断两棵二叉树是否相同
思路：按相同顺序递归遍历 具体看代码
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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //cout<< p->val <<" " << q->val <<endl;
        if(!p && !q) return 1;
        if((p && q && p->val!=q->val) || (p && !q) || (!p && q)) return 0;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};