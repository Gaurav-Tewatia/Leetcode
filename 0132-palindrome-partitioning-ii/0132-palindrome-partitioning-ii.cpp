class Solution {
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int helper(int i,int n, string &s,vector<int> &dp){
        if(i==n or check(i,n-1,s)){
            return dp[i]=0;
        }
        if(dp[i]!=-1) return dp[i];
        int cnt=INT_MAX;
        for(int j=i;j<n;j++){
            if(check(i,j,s)){
                cnt=min(helper(j+1,n,s,dp)+1,cnt);
            }
        }
        return dp[i]=cnt;
    }
public:
    int minCut(string s) {
        if(s.size()==0 or check(0,s.size()-1,s)) return 0; 
        
        int n=s.size();
        vector<int> dp(n+1,-1);
        return helper(0,n,s,dp);
    }
};