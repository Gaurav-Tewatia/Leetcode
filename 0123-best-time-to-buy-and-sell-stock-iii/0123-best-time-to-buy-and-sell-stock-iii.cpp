class Solution {
public:
    /*
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
    
    */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(2,vector<int>(3,0)));
        
       // return solve(prices,0,0,2,dp);
        
        
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;

                    if(!j)
                        profit=max(-prices[i]+dp[i+1][1][limit],dp[i+1][0][limit]);
                    else
                        profit=max(prices[i]+dp[i+1][0][limit-1],dp[i+1][1][limit]);

                    dp[i][j][limit]=profit;
                    
                }
            }
        }
        
        return dp[0][0][2];
    }
};