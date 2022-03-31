/*
题意：二叉树的锯齿形遍历（每换一行要换个方向）
思路：注意 每次必须从左往右把结点插入队列 不然它们孩子顺序会乱（我一开始就这样写错的）
    关键点在代码注释的那一行里

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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*>q;
        if(!root) return res;

        q.push(root);

        bool flag=0;

        while(q.size()){
            int len=q.size();
            vector<int> line(len);

            while(len--){
                auto e=q.front();
                q.pop();
                line[flag ? len: line.size()-len-1] = e->val; //按照索引 从左到右或从右到左 放到vector里
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }
            res.push_back(line);
            flag=!flag;
        }
        return res;
    }
};