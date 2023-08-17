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
    int length(const ListNode*head) const{
        int len=1;
        while(head->next) {
len++;
        head=head->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0 or k==1) return head;
        
        int len=length(head);
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*nex,*curr,*pre=dummy;
        while(len>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            len-=k;
        }
        return dummy->next;
    }
};