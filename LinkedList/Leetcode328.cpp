/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head||!head->next)
        return head;
    struct ListNode *odd=head,*even_head=head->next,*even=even_head;
    while(even&&even->next){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=even_head;
    return head;
}
