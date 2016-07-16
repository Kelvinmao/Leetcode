/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast=head,*slow=head ,*tmp=NULL;
    int i=0;
    if(!head||!n)
        return head;
    if(!head->next)/*���ֻ��һ���ڵ㣬�򷵻ؿ�����*/
        return NULL;
    while(n){
        fast=fast->next;
        n--;
        if(!fast)/*�����ָ��û��ǰ��n����λ���Ѿ�Ϊ�գ��򷵻�head->next��Ҳ����ȥ���˵�һ��Ԫ�أ��ܼ򵥣������Ƶ�*/
            return head->next;
    }
    /*�ҵ���ɾ������ǰ��*/
	while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    tmp=slow->next;
    slow->next=tmp->next;
    free(tmp);
    tmp=NULL;
    return head;
}
