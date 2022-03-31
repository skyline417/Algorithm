/*
题意：求二叉搜索树上结点p,q的最近公共祖先
思路：从上往下遍历，如果该节点大于p和q，lca一定在左子树，如果该节点小于p和q，lca一定在右子树，
    遇到的第一个在p和q中间的结点 就是lca
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
        if(root->val>p->val&&root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val&&root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};