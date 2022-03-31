/*
题意：奇偶链表
思路：两对额外指针 分别存奇链表和偶链表 最后再接在一起 见代码！
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        auto oh=head, ot=oh;
        auto eh=head->next, et=eh;
        for(auto p=head->next->next;p;){
            ot=ot->next=p;
            p=p->next;
            if(p){
                et=et->next=p;
                p=p->next;
            }
        } 
        ot->next=eh;
        et->next=NULL;
        return oh;
    }
};