/*
题意：
    合并两棵二叉树
思路：
    唉你仔细看看代码吧
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t2) swap(t1, t2);  // 可以保证t1一定不为空
        if (!t1) return NULL;
        if (t2) t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2 ? t2->left : NULL);
        t1->right = mergeTrees(t1->right, t2 ? t2->right : NULL);
        return t1;
    }
};



