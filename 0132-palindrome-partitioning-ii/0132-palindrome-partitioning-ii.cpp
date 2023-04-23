class Solution {
public:
    bool ispossible(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n ,string &s,vector<int> &dp){
        if(i==n)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int mini=INT_MAX;
        
        for(int k=i;k<n;k++){
            int partition=0;
            
            if(ispossible(i,k,s)){
                int ans= 1+f(k+1,n,s,dp);
                mini=min(mini,ans);
            }
        }
        return dp[i]=mini;
        
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};