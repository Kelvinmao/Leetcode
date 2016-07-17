/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head||!head->next)
        return NULL;
    struct ListNode * fast=head,*slow=head,*entry=head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            while(entry!=slow){
                entry=entry->next;
                slow=slow->next;
            }
            return entry;
        }
    }
    return NULL;
}
