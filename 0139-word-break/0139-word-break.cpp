class Solution {
    bool helper(int i,int n,string &s,vector<string> &wordDict,unordered_set<string> &st,vector<int> &dp){
        if(i==n) return dp[i]=true;
        
        if(dp[i]!=-1) return dp[i];
        
        for(int j=i;j<n;j++){
            string substring=s.substr(i,j-i+1);
            if(st.count(substring)){
                if(helper(j+1,n,s,wordDict,st,dp)) return dp[j]=true;
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it:wordDict) st.insert(it);
        
        int n=s.size();
        vector<int> dp(n+1,-1);
        return helper(0,n,s,wordDict,st,dp);
    }
};