/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * merge(struct ListNode * l1,struct ListNode * l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    struct ListNode *new_head=NULL,*pmove=NULL;
    if(l1->val>l2->val){
        new_head=l2;
        l2=l2->next;
    }
    else{
        new_head=l1;
        l1=l1->next;
    }
    pmove=new_head;
    while(l1&&l2){
        if(l1->val>l2->val){
            pmove->next=l2;
            l2=l2->next;
        }
        else{
            pmove->next=l1;
            l1=l1->next;
        }
        pmove=pmove->next;
    }
    if(l1)
        pmove->next=l1;
    if(l2)
        pmove->next=l2;
    return new_head;
}

struct ListNode* sortList(struct ListNode* head) {
    if(!head||!head->next)
        return head;
    struct ListNode * fast=head,*slow=head,*Lhead=NULL,*Rhead=NULL;
    struct ListNode *l1=NULL,*l2=NULL;
    while(fast->next&&fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    Rhead=slow->next;
    slow->next=NULL;/*切断链表*/
    Lhead=head;
    l1=sortList(head);/*对链表左半部分递归*/
    l2=sortList(Rhead);
    return merge(l1,l2);/*合并排序后的链表*/ 
}
