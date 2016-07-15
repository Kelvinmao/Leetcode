/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * reverselist(struct ListNode * head){
    if(!head)
        return;
    struct ListNode * current=head;
    struct ListNode * pnext=current->next;
    struct ListNode * prev=NULL;
    current->next=NULL;
    while(pnext){
        prev=pnext->next;
        pnext->next=current;
        current=pnext;
        pnext=prev;
    }
    head=current;
    return head;
}

bool isPalindrome(struct ListNode* head) {
    if(!head||!head->next)
        return true;
    struct ListNode * fast=head;
    struct ListNode * slow=head;
    while(fast->next&&fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverselist(slow->next);
    slow=slow->next;
    while(slow){
        if(head->val!=slow->val)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;
}
