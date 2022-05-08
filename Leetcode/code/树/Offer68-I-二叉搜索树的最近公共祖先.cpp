/*
题意：二叉搜索树的最近公共祖先 同235
思路：若root全大于p和q 找左子树
    若root全小于p和q 找右子树
    否则它就是lca
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};

/*
20220503 第2次
*/