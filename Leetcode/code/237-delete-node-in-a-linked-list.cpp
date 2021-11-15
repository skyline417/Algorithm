/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
题意：
    给定指向当前节点的的一个列表，要你删掉当前节点
思路：
    把下一个节点的值复制给当前结点，再删掉下一个节点
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};