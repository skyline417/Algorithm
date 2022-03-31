/*
题意：
    判断subtree是否是root的子树
思路：
    方法一：判断subTree是不是root的子树 可以用isSameTree（100）来判断
    方法二：树哈希 见代码
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return 1;
        if(!root || !subRoot) return 0;
        return isSameTree(root,subRoot) || isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if((p && q && p->val!=q->val) || (p && !q) || (!p && q)) return 0;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
public:
    const int P = 131, Q = 159, MOD = 1e7 + 7;
    int T = -1;
    bool ans = false;

    int dfs(TreeNode* root) {
        if (!root) return 12345;
        int left = dfs(root->left), right = dfs(root->right); //左子树哈希 右子树哈希
        int x = (root->val % MOD + MOD) % MOD; //根节点哈希值
        if (left == T || right == T) ans = true;
        return (x + left * P % MOD + right * Q) % MOD; //计算 根+左+右 的哈希值
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        T = dfs(t);
        if (T == dfs(s)) ans = true;
        return ans;
    }
};

