/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head||!head->next||k<=0)
        return head;
    struct ListNode *pmove=head;
    int len=1;
    while(pmove->next){
        pmove=pmove->next;
        len++;
    }
    pmove->next=head;
    k=len-k%len;
    while(k){
        pmove=pmove->next;
        k--;
    }
    head=pmove->next;
    pmove->next=NULL;
    return head;
}
