/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //THIS WILL TAKE EXTRA O(N) space complexity
//         unordered_map<Node*,Node*> mp;
//         Node*temp=head;
//         while(temp!=NULL){
//             Node*n=new Node(temp->val);
//             mp[temp]=n;
//             temp=temp->next;
//         }
        
//         temp=head;
//         while(temp!=NULL){
//             Node*n=mp[temp];
//             n->next=temp->next!=NULL?mp[temp->next]:NULL;
//             n->random=temp->random!=NULL?mp[temp->random]:NULL;
//             temp=temp->next;
//         }
//         return mp[head];
        
        //THIS WILL TAKE O(1) space complexity
        
        
        //create a deep copy of node
        Node*temp=head;
        while(temp!=NULL){
            Node*n=new Node(temp->val);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;   // or temp->next->next
            
        }
        
        
        //link the random pointer of deep copied node
        
        temp=head;
        while(temp!=NULL){
            if(temp->random)
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        
        //now link the next pointer of deep copied nodes and restore the original node as well
        
        Node*dummy=new Node(0);
        Node*res=dummy;
        temp=head;
        while(temp!=NULL){
            dummy->next=temp->next;
            temp->next=temp->next->next;
                
            temp=temp->next;
            dummy=dummy->next;
        }
        
        return  res->next;
        
    }
};