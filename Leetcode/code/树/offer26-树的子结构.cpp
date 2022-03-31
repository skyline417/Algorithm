/*
题意：二叉树的子结构
思路：（这题自己没写出来）
    注意是子结构不是子树
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return 0;
        return isSame(A,B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool isSame(TreeNode* A, TreeNode* B){//判断两棵树是否相同
        if(!B) return 1; //注意这里！ 只有前面都匹配才会走到这满足这！所以返回1！
        if( !A  || A->val != B->val ) return 0;
        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }
};