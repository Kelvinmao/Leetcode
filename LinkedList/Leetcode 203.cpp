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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode dummy(0);
        dummy.next=head;
        struct ListNode *pmove=&dummy;
        while(pmove->next){
            if(pmove->next->val==val)
                pmove->next=pmove->next->next;
            else
                pmove=pmove->next;
        }
        return dummy.next;
    }
};
