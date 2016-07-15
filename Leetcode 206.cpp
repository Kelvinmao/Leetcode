/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head)
        return NULL;
    else{
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
}

/*Recursion*/
struct ListNode* reverseList(struct ListNode* head) {
    if(!head)
    	return head;
    struct ListNode * p=reverselist(head->next);
    head->next-next=head;
    head->next=NULL;
	return p;
}
