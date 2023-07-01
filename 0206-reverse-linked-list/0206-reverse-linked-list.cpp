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
    ListNode* reverseList(ListNode* head) {
        
//         if(head->next==NULL or head==NULL) return head;
        
//         ListNode*shead=reverseList(head->next);
        
//        head->next->next=head;
//         head->next=NULL;
        
//         return shead;
        
        if(head==NULL or head->next==NULL) return head;
        ListNode*temp=head;
        ListNode*n;
        ListNode*prev=NULL;
        
        while(temp->next){
            n=temp->next;
            temp->next=prev;
            prev=temp;
            temp=n;
        }
        temp->next=prev;
        head=temp;
        return head;
    }
};