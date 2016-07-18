/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode left,right;
    struct ListNode *pLeft=&left,*pRight=&right;
    if(!head)
        return head;
    while(head){
        if(head->val<x){
            pLeft->next=head;
            pLeft=pLeft->next;
        }
        else{
            pRight->next=head;
            pRight=pRight->next;
        }
        head=head->next;
    }
    pRight->next=NULL;
    pLeft->next=right.next;
    return left.next;
}
