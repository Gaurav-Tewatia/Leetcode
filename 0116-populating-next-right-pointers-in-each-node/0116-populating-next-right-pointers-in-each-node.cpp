/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node*node=q.front();
            q.pop();
            node->next=NULL;
            int size=q.size();
            if(node->left) q.push(node->left);
            if(node->right)  q.push(node->right);
            for(int i=0;i<size;i++){
                Node*temp=q.front();
                q.pop();
                node->next=temp;
                node=temp;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            node->next=NULL;
            
        }
        return root;
    }
};