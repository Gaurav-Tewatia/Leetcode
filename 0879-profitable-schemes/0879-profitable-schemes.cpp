class Solution {
public:
    int mod=1e9+7;
    
    int solve(int i, int g, int p,int n, int minimum,vector<int> &group,vector<int> &profit,vector<vector<vector<int>>> &dp){
        if(i==group.size()){
            if(p>=minimum and g<=n)
                return 1;
            
                return 0;
        }
        
       else if(g>n)
            return 0;
        
        if(dp[i][g][p]!=-1)
            return dp[i][g][p];
        
        int take=solve(i+1,g+group[i],min(profit[i]+p,minimum),n,minimum,group,profit,dp)%mod;
        int nottake=solve(i+1,g,p,n,minimum,group,profit,dp)%mod;
        
        return dp[i][g][p]=(take%mod+nottake%mod)%mod;
    }
    
    
    

  
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        
        
        
        return solve(0,0,0,n,minProfit,group,profit,dp);
    }
};