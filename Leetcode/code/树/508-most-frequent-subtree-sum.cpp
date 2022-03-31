/*
题意：
    出现最多的子树元素和
思路：
    void sum用来遍历子树，过程中累加子树和并统计，可以和563对比一下（我有点搞不清）。
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
    unordered_map<int,int>cnt;
    int maxn=0;
    vector<int> findFrequentTreeSum(TreeNode* root) {  
        sum(root);
        vector<int>res;
        for(auto e:cnt){
            if(maxn==e.second) res.push_back(e.first);
        }
        return res;
    }
    void sum(TreeNode* root){
        if(!root) return;
        sum(root->left), sum(root->right);
        if(root->left) root->val+=root->left->val;
        if(root->right) root->val+=root->right->val;
        ++cnt[root->val];
        maxn=max(maxn,cnt[root->val]);
        return;
    }
};