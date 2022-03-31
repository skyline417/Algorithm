/*
题意：链表中倒数第k个节点
思路：双指针，i先走k步，然后j也开始走，当i走到终点，j指向的就是倒数第k个结点，因为i和j距离是k。
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto i=0;
        auto j=head;
        while(head){
            ++i;
            head=head->next;
            if(i==k) break;
        }
        while(head){
            ++i; 
            j=j->next;
            head=head->next;
        }
        return j;
    }
};