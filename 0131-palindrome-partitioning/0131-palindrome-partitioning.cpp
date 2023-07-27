class Solution {
    bool check(int start,int end,string &s){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void helper(int i,int n,vector<string> &v,vector<vector<string>> &ans,string &s){
        if(i==n){
            ans.push_back(v);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(check(i,j,s)){
                v.push_back(s.substr(i,j-i+1));
                helper(j+1,n,v,ans,s);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        vector<string> v;
        
        helper(0,n,v,ans,s);
        return ans;
    }
};