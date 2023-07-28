class Solution {
    bool check(int i, int j, string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    bool helper(int i,int n, int cnt, string &s,vector<vector<int>>&dp){
        if(i==n){
            if(cnt==3) return dp[i][cnt]=true;
            return dp[i][cnt]=false;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        for(int j=i;j<n;j++){
            if(check(i,j,s)){
                if(cnt+1>3) return dp[i][cnt]=false;
                if(helper(j+1,n,cnt+1,s,dp)) return dp[i][cnt]=true;
            }
        }
        return dp[i][cnt]=false;
    }
public:
    bool checkPartitioning(string s) {
        int n=s.size();
        int cnt=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,n,cnt,s,dp);
    }
};