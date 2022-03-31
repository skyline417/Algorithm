/*
题意：二叉树的层序遍历
思路：创建一个TreeNode*的队列
    将根节点加入队列
    获得队伍长度len // 该层长度
    在该长度内将元素出队, 值放入vector中 //while(len--) 
    将这一行vector加入答案
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);

        while(q.size()){
            vector<int> line;
            int len=q.size();

            while(len--){
                auto e=q.front();
                q.pop();
                line.push_back(e->val);
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }
            
            res.push_back(line);
        }
        return res;
    }
};