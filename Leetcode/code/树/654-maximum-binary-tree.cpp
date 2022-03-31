/*
题意：
    由一个数组生成最大二叉树 最大值拎起来当跟 两边递归
思路：
    看代码吧 很有条理 很工整优美
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
    TreeNode* dfs(vector<int>& nums, int l, int r){
        if(l>r) return NULL;
        if(l==r) return new TreeNode(nums[l]);

        int maxn=0, pos=0;
        for(int i=l;i<=r;++i){
            if(nums[i]>=maxn){
                maxn=nums[i];
                pos=i;
            }
        }

        TreeNode* root = new TreeNode(maxn);
        root->left = dfs(nums,l,pos-1);
        root->right= dfs(nums,pos+1,r);
        return root;
    }
};