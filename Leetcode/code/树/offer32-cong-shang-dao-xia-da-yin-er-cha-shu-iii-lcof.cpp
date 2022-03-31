/*
题意：二叉树的zigzag遍历
思路：见103
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=0;
        while(!q.empty()){
            int len=q.size();
            vector<int>line(len);
            int i=0;
            while(len--){
                auto e=q.front();
                q.pop();
                line[flag ? len: i++] = e->val;

                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }
            res.push_back(line);
            flag=!flag;
        }
        return res;
    }  
};