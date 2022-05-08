/*
题意：复杂链表的复制，这个链表每个节点有一个next指针指向下一个节点，
    也有一个random指针指向链表中任意结点或为空
    复制该复杂链表，要求新链表不能与原链表地址相同，原链表最后要与最初相同
思路：
    1. 第1个循环：在原链表每个节点后复制一个新节点
    2. 第2个循环：将原节点的random指针进行复制
    3. 分离两个链表 复原旧链表
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //在每个节点后面复制一个新节点
        for(auto p=head; p;){
            auto np = new Node(p->val); //新建节点
            auto next = p->next; //为p->next起别名next
            p->next=np; //将新节点np插在p后面 / p的next指针指向np
            np->next=next;//将新节点next指针指向原来p的next
            p=next;//移动p指针到原来它后面的next
        }
        //将原来每个节点的random 复制到新节点上
        for(auto p=head; p; p=p->next->next){ //注意step是移两个
            if(p->random){
                p->next->random=p->random->next; // p后面新节点的random=p的random的后面的新节点
            }
        }
        //分离两个链表
        auto dummy = new Node(-1);
        auto cur=dummy;
        for(auto p=head;p;p=p->next){
            cur->next=p->next; //cur是p前一个结点 cur是新的 没有next指针 所以要给它next赋值 
            cur=cur->next; //cur指针移动
            p->next=p->next->next; //复原原链表（原链表不能修改）
        }
        return dummy->next;
    }
};