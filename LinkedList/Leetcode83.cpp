/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head||!head->next)
        return head;
    struct ListNode * pmove=head;
    struct ListNode * qmove=NULL;
    struct ListNode * tmp=NULL;
    while(pmove){
        qmove=pmove;
        while(qmove->next){
            if(qmove->next->val==pmove->val){
                tmp=qmove->next;
                qmove->next=tmp->next;
                free(tmp);
            }
            else
                qmove=qmove->next;
        }
        pmove=pmove->next;
    }
    return head;
}
