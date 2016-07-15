/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **pmove=&head;
    struct ListNode *qmove=NULL;
    if(!head)
        return NULL;
    else{
        while(*pmove){
            qmove=(*pmove);
            if((*pmove)->val==val){
                *pmove=qmove->next;
                free(qmove);
            }
            else
                pmove=&qmove->next;
        }
    }
    return head;
}
