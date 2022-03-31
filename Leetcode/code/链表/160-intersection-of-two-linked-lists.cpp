/*
题意：求两个链表的第一个共同结点
思路：p=headA, q=headB 一起往前走 
    谁先走到NULL 就再从对方的起点开始走 
    p和q第一次相等的地方就是它们的第一个交点(都走了相同的长度a+b+c) 
    即便两条链表无交点也对
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p=headA, q=headB;
        while(p!=q){
            p=p?p->next:headB;
            q=q?q->next:headA;
        }
        return p;
    }
};