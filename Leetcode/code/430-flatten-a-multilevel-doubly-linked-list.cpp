/*
题意：链表的先序遍历
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    public:
        Node* last = NULL;
        Node* flatten(Node* head) {
            if(head==NULL) return NULL;
            Node* next=head->next; //保存兄弟（否则递归完孩子 next就变了）
            if(last!=NULL){ //连接 last是全局变量，所以会按递归顺序连接
                last->next=head;
                head->prev=last;
                last->child=NULL; //最后的链表是单链表
            }
            last=head;
            flatten(head->child); //递归孩子
            flatten(next); //递归兄弟
            return head;
        }
};