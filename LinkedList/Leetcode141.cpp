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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        struct ListNode * pmove=head,* qmove=head;
        while(pmove&&qmove&&qmove->next){
            pmove=pmove->next;
            qmove=qmove->next->next;
            if(pmove==qmove)
                return true;
        }
        return false;
    }
};
