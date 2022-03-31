/*
题意：求二叉树的坡度
    每个节点的坡度：左子树之和与右子树之和 差的绝对值
    整棵树的坡度：所有节点的坡度之和
思路：sum函数用来(递归)求子树和，遍历过程中累加每个节点的坡度
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
    int ans=0;
    int findTilt(TreeNode* root) {
        sum(root);
        return ans;
    }
    int sum(TreeNode* root){
        if(!root) return 0;
        int l=sum(root->left), r=sum(root->right);
        ans += abs(l-r);
        return root->val+l+r;
    }
};