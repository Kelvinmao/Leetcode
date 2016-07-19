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
    struct ListNode dummy;/*dummy��Ϊͷ��㣬�򻯲���*/
    dummy.next=head;
    struct ListNode * pre=&dummy,*cur=head,*tmp=NULL;
    bool duplicate=false;/*����ֵ��������Ƿ�����ظ�*/
    while(cur){
        if(cur->next&&cur->val==cur->next->val){
            tmp=cur->next;
            cur->next=tmp->next;
            free(tmp);
            duplicate=true;
        }
        else if(duplicate){
            pre->next=cur->next;/*ɾ��curָ��Ľ��*/
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
