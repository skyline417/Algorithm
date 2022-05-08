/*
题意：将二叉搜索树转换成排序的双向链表，不准创建新节点。
思路：对于每个节点，
        递归左右两边子树，返回它们最左边节点和最右边节点
    然后连起来（左子树最右边节点 = 当前节点 = 右子树最左边节点）
    (代码实现时要分4类讨论：叶子结点，左右子树都存在，只有左子树，只有右子树)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL; //特判
        auto sides = dfs(root); //两端
        sides.first->left=sides.second, sides.second->right=sides.first;//循环
        return sides.first; //返回最左侧的节点
    }
    pair<Node*, Node*> dfs(Node* root){
        if(!root->left && !root->right) return {root,root}; //叶子->直接返回当前节点
        if(root->left && root->right){ //左右子树都有
            auto lsides=dfs(root->left), rsides=dfs(root->right);//递归处理左子树、右子树
            lsides.second->right=root, root->left=lsides.second; //左子树的最右侧的点 和根节点相连
            rsides.first->left=root, root->right=rsides.first; //右子树的最左侧的点 
            return {lsides.first, rsides.second}; //返回 左子树的最左侧的点，右子树的最右侧的点
        }
        if(root->left ){ //只有左子树存在
            auto lsides=dfs(root->left);
            lsides.second->right=root, root->left=lsides.second; //左子树的最右侧的点 和根节点相连
            return {lsides.first, root}; //返回 左子树的最左侧的点，根节点（没有右子树，根节点就是最右边的）
        }
        if(root->right){ //只有右子树存在
            auto rsides=dfs(root->right);
            rsides.first->left=root, root->right=rsides.first; //右子树的最左侧的点 
            return {root, rsides.second}; //返回 左子树的最左侧的点，右子树的最右侧的点
        }
        return {NULL,NULL};
    }
};