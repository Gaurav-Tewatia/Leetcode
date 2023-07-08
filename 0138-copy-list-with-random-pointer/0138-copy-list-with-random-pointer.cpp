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
        Node*itr=head;
        
        //creating duplicate nodes 
        while(itr){
            Node*n=new Node(itr->val);
            n->next=itr->next;
            itr->next=n;
            itr=itr->next->next;
        }
        
        //adding random pointers in duplicate node
        itr=head;
        while(itr){
            if(itr->random){
                itr->next->random=itr->random->next;
            }
            itr=itr->next->next;
        }
        
        //separating the duplicate node from original nodes

        Node*dummy=new Node(0);
        Node*copy=dummy;
        itr=head;
        while(itr){
            copy->next=itr->next;
            Node*front=itr->next->next;
            itr->next=front;
            copy=copy->next;
            itr=front;
        }
        
        return dummy->next;
    }
};