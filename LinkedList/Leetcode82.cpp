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
    struct ListNode dummy;/*dummy作为头结点，简化操作*/
    dummy.next=head;
    struct ListNode * pre=&dummy,*cur=head,*tmp=NULL;
    bool duplicate=false;/*布尔值用来标记是否出现重复*/
    while(cur){
        if(cur->next&&cur->val==cur->next->val){
            tmp=cur->next;
            cur->next=tmp->next;
            free(tmp);
            duplicate=true;
        }
        else if(duplicate){
            pre->next=cur->next;/*删除cur指向的结点*/
            free(cur);
            cur=pre->next;
            duplicate=false;
        }
        else{
            pre=cur;
            cur=cur->next;
        }
    }
    head=dummy.next;
    return head;
}
