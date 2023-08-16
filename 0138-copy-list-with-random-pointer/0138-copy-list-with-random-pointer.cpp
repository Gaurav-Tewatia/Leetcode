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
        unordered_map<Node*,Node*> mp;
        Node*temp=head;
        while(temp!=NULL){
            Node*n=new Node(temp->val);
            mp[temp]=n;
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=NULL){
            Node*n=mp[temp];
            n->next=temp->next!=NULL?mp[temp->next]:NULL;
            n->random=temp->random!=NULL?mp[temp->random]:NULL;
            temp=temp->next;
        }
        return mp[head];
    }
};