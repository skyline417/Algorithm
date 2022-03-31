/*
题意：两个链表的第一个交点
思路：两个指针各自向前 走到null的之后 再从对方链表的头开始向前走 直到两个指针相遇
    原理（两个指针走的总和=2(A+B+C)，C是公共长度）
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