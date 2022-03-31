/*
题意：链表右移k
思路：
    特殊情况：链表为空/链表长度为1/k=0
    k=n-k
    找到第k-1个节点 它的next置为NULL
    找到最后一个节点 它的next置为head
    返回第k个结点
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        auto last=head;
        int n=1;
        while(last->next){
            last=last->next;
            ++n;
        }//得到了链表长度和最后的结点last

        auto a=head;
        k=k%n; //实际右移次数
        if(n==1||!k) return head;
        k=n-k; //右移k，要找第n-k（为链表头）
        
        for(int i=0;i<k-1;++i) a=a->next; //第k-1个
        auto ans=a->next; //最终答案
        last->next=head; //最后的节点的last置为head
        a->next=NULL; //第k-1个节点的next置为NULL
        return ans;
    }
};