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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         set<ListNode*> s;
        
//         ListNode*temp=headA;
//         while(temp){
//             s.insert(temp);
//             temp=temp->next;
//         }
//         temp=headB;
//         while(temp){
//             if(s.find(temp)!=s.end())
//                 return temp;
//             temp=temp->next;
//         }
//         return NULL;
        
        ListNode*d1=headA;
        ListNode*d2=headB;
        
        while(d1!=d2){
            d1=d1==NULL?headB:d1->next;
            d2=d2==NULL?headA:d2->next;
        }
        return d1;
    }
};