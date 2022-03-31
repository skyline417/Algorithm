/*
题意：书上和为k的路径数（必须从上到下的一条路）
思路：前缀和思想 遍历整棵树 然后在子结点 加上 当前和-targetSum 的个数（hash表统计）
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
    unordered_map<int,int> hash;
    int res=0;

    int pathSum(TreeNode* root, int sum) {
        hash[0]=1;
        dfs(root,0,sum);
        return res;
    }

    void dfs(TreeNode* root, int cur, int sum){
        if(!root) return;
        cur+=root->val;
        res+=hash[cur-sum];
        ++hash[cur];
        dfs(root->left,cur,sum), dfs(root->right,cur,sum);
        --hash[cur];
    }
};