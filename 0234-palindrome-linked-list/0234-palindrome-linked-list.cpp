/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head->next;
        stack<int> s;
        while(fast and fast->next){
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL){
            slow=slow->next;
        }
        else{
            s.push(slow->val);
            slow=slow->next;
        }
        
        while(slow){
            if(s.top()!=slow->val)
                return false;
            s.pop();
            slow=slow->next;
        }
        return true;
    }
};