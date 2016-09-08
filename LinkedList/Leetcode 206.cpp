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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        struct ListNode *cur=head,*pnext=cur->next,*prev=NULL;
        cur->next=NULL;
        while(pnext){
            prev=pnext->next;
            pnext->next=cur;
            cur=pnext;
            pnext=prev;
        }
        head=cur;
        return head;
    }
};
