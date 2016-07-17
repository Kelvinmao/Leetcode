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
    head->next=swapPairs(tmp->next);/*使链表中第二对及之后的节点进行交换*/
    tmp->next=head;
    return tmp;
}


