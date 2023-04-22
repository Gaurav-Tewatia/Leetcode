class Solution {
public:

    int solve(string s, string r){
        int n=s.size();

        int dp[n+1][n+1];

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0)
                dp[i][j]=0;
                else if(s[i-1]==r[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

            }
        }

        return n-dp[n][n];
    }
    int minInsertions(string s) {
        string r=s;
        reverse(s.begin(),s.end());

        return solve(s,r);
    }
};