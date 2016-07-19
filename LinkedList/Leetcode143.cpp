/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * reverseList(struct ListNode *head){
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

void reorderList(struct ListNode* head) {
    if(!head||!head->next)
        return;
    struct ListNode *fast=head,*slow=head,*right=NULL,*pmove=head,*qmove=NULL;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    right=slow->next;
    slow->next=NULL;
    
    right=reverseList(right);
    qmove=right;
    pmove=head;
    int index=0;
    /*这段建议画图观察指针的移动，便于理解*/
    while(pmove&&qmove){
		if(index%2==0){
            struct ListNode * next=pmove->next;
            pmove->next=qmove;
            pmove=next;
        }
		else{
            struct ListNode * next=qmove->next;
            qmove->next=pmove;
            qmove=next;
        }
        index++;
    }
}
