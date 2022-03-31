/*
题意：n叉树的层序遍历
思路：类似102
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);

        while(q.size()){
            vector<int> line;
            int len=q.size(); //获得该层长度

            while(len--){
                //这一层保存到答案
                auto e=q.front();
                q.pop();
                line.push_back(e->val);

                //这一层的孩子入队
                for(auto t: e->children){
                    q.push(t);
                }
            }

            res.push_back(line);
        }
        return res;
    }
};