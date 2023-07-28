class Solution {
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int helper(int i,int n,string &s,int k,vector<int> &dp){
        if(i==n){
            return dp[i]=0;
        }
        if(dp[i]!=-1) return dp[i];
        int cnt=0;
       if(i+k-1<n){
           for(int j=i+k-1;j<n;j++){
               if(check(i,j,s))
               cnt=max(cnt,helper(j+1,n,s,k,dp)+1);
           }
           cnt=max(cnt,helper(i+1,n,s,k,dp));
       }
        return dp[i]=cnt;
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return helper(0,n,s,k,dp);
    }
};