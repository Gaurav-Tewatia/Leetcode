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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode*dummy=new ListNode(0);
        ListNode*pre=dummy,*curr=dummy,*nex=dummy,*temp=head;
        dummy->next=head;
        int cnt=1;
        while(temp->next){
            cnt++;
            temp=temp->next;
        }
        while(cnt>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            cnt-=k;
        }
        return dummy->next;
    }
};