/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getLen(struct ListNode * headA){
    int length=0;
    struct ListNode * pmove=headA;
    while(pmove){
        length++;
        pmove=pmove->next;
    }
    return length;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * pmove=headA;
    struct ListNode * qmove=headB;
    int lenA=getLen(pmove);
    int lenB=getLen(qmove);
    int delta=0;
    if(!pmove||!qmove)
        return NULL;
    if(lenA>lenB){
        delta=lenA-lenB;
        while(delta){
            pmove=pmove->next;
            delta--;
        }
    }
    else{
        delta=lenB-lenA;
        while(delta){
            qmove=qmove->next;
            delta--;
        }
    }
    while(pmove){
        if(pmove->val==qmove->val)
            return pmove;
        else{
            pmove=pmove->next;
            qmove=qmove->next;
        }
    }
    return NULL;
}
