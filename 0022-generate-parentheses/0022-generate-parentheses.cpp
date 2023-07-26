class Solution {
    private:
    void helper(int open,int close,int n, string &s,vector<string> &ans){
        if(close==n){
            ans.push_back(s);
            return;
        }
        
        if(open<n){
            s.push_back('(');
            helper(open+1,close,n,s,ans);
            s.pop_back();
        }
        if(close<open){
            s+=')';
            helper(open,close+1,n,s,ans);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(0,0,n,s,ans);
        return ans;
    }
};