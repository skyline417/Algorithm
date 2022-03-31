/*
题意：交换链表中相邻元素
思路：
    其实涉及三个元素，设一个dummy，然后交换dummy后面两个元素，这样dummy->next调整起来比较方便。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        auto a = dummy, b = head;
        while(b && b->next){ //交换a后面的两个（c&d）
            auto c = b, d = b->next; //交换cd
            c->next=d->next;
            a->next=d;
            d->next=c;

            a=c, b=c->next; //交换后，c在后面
        }
        return dummy->next;
    }
};