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
        if(head==NULL) return false;
        
        ListNode*low=head,*fast=head;
        
        while(fast and fast->next){
            low=low->next;
            fast=fast->next->next;
            if(low==fast){
                return true;
            }
        }
        return false;
    }
};