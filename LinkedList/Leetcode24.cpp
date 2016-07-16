/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head||!head->next)
        return head;
    struct ListNode * tmp=head->next;
    head->next=swapPairs(tmp->next);
    tmp->next=head;
    return tmp;
}


