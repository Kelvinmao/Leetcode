/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode * pmove=head;
    struct ListNode * qmove=head;
    if(!head)
        return false;
    while(pmove&&qmove&&qmove->next){
        pmove=pmove->next;
        qmove=qmove->next->next;
        if(pmove==qmove)
            return true;
    }
    return false;
}
