/*
题意：从尾到头打印链表
思路：书上说是用栈 
    我实现是用vector 倒过来
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
    vector<int> reversePrint(ListNode* head) {
        vector<int>res;
        while(head){
            res.push_back(head->val);
            head=head->next;
        }
        //reverse(res.begin(),res.end());
        return vector<int>(res.rbegin(),res.rend());
    }
};