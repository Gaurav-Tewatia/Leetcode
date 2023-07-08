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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL) return head;
        int cnt=1;
        ListNode*temp=head;
        
        while(temp->next) cnt++,temp=temp->next;
        
        temp->next=head;
        ListNode*n=head;
        k=k%cnt;
         cnt= cnt-k-1;
        while(cnt--){
            n=n->next;
            
        }
        head=n->next;
        n->next=NULL;
        return head;
    }
};