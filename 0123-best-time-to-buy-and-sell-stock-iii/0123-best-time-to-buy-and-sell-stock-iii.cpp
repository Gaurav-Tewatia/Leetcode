class Solution {
public:
    // this is top down approach
    int solve(vector<int> & prices,int i, int buy,int limit,vector<vector<vector<int>>> &dp ){
        if(i==prices.size())
            return 0;
        
        if(limit==0)
            return 0;
        
        if(dp[i][buy][limit]!=-1)
            return dp[i][buy][limit];
        
        int profit=0;
        
        if(!buy){
            profit=max(-prices[i]+solve(prices,i+1,1,limit,dp),solve(prices,i+1,0,limit,dp));
        }
        else{
            profit=max(prices[i]+solve(prices,i+1,0,limit-1,dp),solve(prices,i+1,1,limit,dp));
        }
        
        return dp[i][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<vector<int> > > dp(n,vector<vector<int> >(2,vector<int>(3,-1)));
        
        return solve(prices,0,0,2,dp);
    }
};