/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return 1;
        queue<pair<long long,TreeNode*>>q;
        q.push({0,root});
        int maxi=0;
        while(!q.empty()){
            int min=q.front().first;
               
            int first,last;
            int size=q.size();
            for(int i=0;i<size;i++){
                 TreeNode*node=q.front().second;
                
                int cud_id=q.front().first-min;
                q.pop();
                if(i==0) first=cud_id;
                if(i==size-1) last=cud_id;
                if(node->left) q.push({2*1ll*cud_id+1,node->left});
                if(node->right) q.push({2*1ll*cud_id+2,node->right});
                
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};