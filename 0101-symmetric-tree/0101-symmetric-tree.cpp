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
    bool check(TreeNode*a,TreeNode*b){
        if(a==NULL or b==NULL) return a==b;
        if(a->val!=b->val) return false;
        return check(a->left,b->right) and check(a->right,b->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        
        return check(root->left,root->right);
    }
};