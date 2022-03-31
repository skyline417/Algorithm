/*
题意：返回二叉树中好节点的数目。「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
思路：dfs
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
    int cnt=0;
    int goodNodes(TreeNode* root) {
        
        dfs(root, -99999);
        return cnt;
    }

    void dfs(TreeNode* root, int maxn){
        if(!root) return;

        if(maxn<=root->val) {
            ++cnt;
            maxn=root->val;
        }
        
        dfs(root->left, maxn);
        dfs(root->right,maxn);
    }
};