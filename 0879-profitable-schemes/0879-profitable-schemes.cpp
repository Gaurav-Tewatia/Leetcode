class Solution {
public:
    int mod=1e9+7;
    int dp[102][102][102];
    int solve(int i, int g, int p,int n, int minimum,vector<int> &group,vector<int> &profit){
        if(i==group.size()){
            if(p>=minimum and g<=n)
                return 1;
            
                return 0;
        }
        
       else if(g>n)
            return 0;
        
        if(dp[i][g][p]!=-1)
            return dp[i][g][p];
        
        int take=solve(i+1,g+group[i],min(profit[i]+p,minimum),n,minimum,group,profit)%mod;
        int nottake=solve(i+1,g,p,n,minimum,group,profit)%mod;
        
        return dp[i][g][p]=(take%mod+nottake%mod)%mod;
    }
    
    
    
//     int dp[102][102][102];
//     int mod=1e9+7;
//     int solve(int k,int i, int j,int n, int minProfit, vector<int>& group, vector<int>& profit)
//     {
//         if(k==group.size())
//         {
//             if(j>=minProfit and n>=i) return 1;
//             return 0;
//         }
//         else if(n<i) return 0;
     
//         if(dp[k][i][j]!=-1) return  dp[k][i][j];
//         int include=0,notInclude=0;
//         notInclude= solve(k+1,i,j,n,minProfit,group,profit);
//         include=solve(k+1,i+group[k],min(j+profit[k],minProfit),n,minProfit,group,profit);
//         return  dp[k][i][j] = (include  % mod + notInclude  % mod )%mod;
//     }
  
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
       // vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,0,n,minProfit,group,profit);
    }
};